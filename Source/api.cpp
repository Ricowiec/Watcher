#include "api.h"

#include <QDebug>

API::API()
{
    connect(&downloadManager, &QNetworkAccessManager::finished,
            this, &API::downloadFinished);

    createDataFolder();
    createDataTemplate();
    createObserved();
}

void API::requestToCurl(const QString &request)
{
//    qDebug() << "requestToCurl()";
//    qDebug() << "Request: " << request;
    QProcess *curl = new QProcess(this);
//    curl->setProcessChannelMode( QProcess::MergedChannels );
    curl->setProcessChannelMode( QProcess::SeparateChannels );
//    qDebug() << QDir::currentPath() + "/Curl/curl.exe";
    QString argument = request + "&page=" + QString::number(currentPage) + "&limit=" + QString::number(elementsLimit);
    qDebug() << "Argument: " << argument;
    qDebug() << "Path: " << QDir::currentPath() + "/Curl/curl";
    curl->start(QDir::currentPath() + "/Curl/curl", QStringList() << argument /* << "pause"*/);
//    curl->start(QDir::currentPath() + "/Curl/cmd", QStringList() << "curl" + request << "pause");
    QThread::sleep(2);

    if(!curl->waitForStarted(-1))
        qDebug() << curl->error();
    else
//        qDebug() << "Curl was started";

//    curl->waitForReadyRead(3000);

//    while(curl->canReadLine())
//        qDebug() << curl->readLine();

    connect(curl, &QProcess::readyReadStandardOutput,
            this, [=]()
            {
//                while(curl->canReadLine())
//                    qDebug() << curl->readLine();
//                qDebug() << "Read: " << curl->readAll();
                QString replyName = request.split("=")[1];
                QFile file(dataPath + "/" + replyName + ".json");
                if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
                {
                    qDebug() << "Failed open file\n" << file.errorString()
                             << "\nFile name: " << file.fileName();
                }
                else
                {
//                    qDebug() << "File name: " << file.fileName();
                    QTextStream out(&file);
                    file.resize(0);
                    out << curl->readAll();
                    file.close();
                    emit readyRead();
                }
//                qDebug() << "ReadAllStandarOutput: " << curl->readAllStandardOutput();
            });

    connect(curl, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [=](int exitCode, QProcess::ExitStatus exitStatus)
            {
                qDebug() << "Error: " << curl->errorString();
                qDebug() << "Exit code: " << exitCode;
                qDebug() << "Exit status: " << exitStatus;
            });

    curl->close();
}

bool API::createDataFolder()
{
    dataPath = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).value(0);
    qDebug() << "Data path: " << dataPath;
    QDir myDir(dataPath);
    if (!myDir.exists()) {
        if(!myDir.mkpath(dataPath)) {
            qDebug() << "Failed create data folder: " << dataPath;
            return false;
        }
        qDebug() << "Created data folder path" << dataPath;
    }
    return true;
}

bool API::createDataTemplate()
{
    QFile dataTemplate(dataPath + "/detailedDataTemplate.txt");

    if(dataTemplate.exists() && dataTemplate.size() > 2)
        return true;

    if(!dataTemplate.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed create template";
        return false;
    }

    QTextStream stream(&dataTemplate);
    stream << "krs_podmioty.nazwa\n";

    stream << "krs_podmioty.kraj\n";
    stream << "krs_podmioty.miejscowosc\n";
    stream << "krs_podmioty.kod_pocztowy\n";
    stream << "krs_podmioty.adres_ulica\n";

    stream << "krs_podmioty.wartosc_kapital_zakladowy\n";

    stream << "krs_podmioty.krs\n";
    stream << "krs_podmioty.nip\n";
    stream << "krs_podmioty.regon\n";

    stream << "krs_podmioty.www\n";
    stream << "krs_podmioty.email\n";
//    stream << "krs_podmioty.twitter_account_id\n";

    stream << "krs_podmioty.firma\n";
    stream << "krs_podmioty.forma_prawna_str\n";
    stream << "krs_podmioty.nazwa_organu_reprezentacji\n";

    stream << "krs_podmioty.data_dokonania_wpisu\n";
    stream << "krs_podmioty.cel_dzialania\n";
    stream << "krs_podmioty.sposob_reprezentacji\n";

    stream << "krs_podmioty.data_zawieszenia_dzialalnosci\n";
    stream << "krs_podmioty.data_wznowienia_dzialalnosci\n";
    stream << "krs_podmioty.data_rejestracji_stowarzyszenia\n";
    stream << "krs_podmioty.data_wyrejestrowania_przedsiebiorcy\n";
    stream << "krs_podmioty.data_wykreslenia_przedsiebiorcy\n";

    stream << "krs_podmioty.oznaczenie_sadu\n";

    stream << "krs_podmioty.sygnatura_akt\n";

    dataTemplate.close();

    return true;
}

bool API::createObserved()
{
    QFile dataTemplate(dataPath + "/observed.txt");

    if(dataTemplate.exists())
        return true;

    if(!dataTemplate.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed create template";
        return false;
    }

    return true;
}

void API::request(const QString &url)
{
    QNetworkRequest request;
    qDebug() << "URL: " << url + "&page=" + QString::number(currentPage) + "&limit=" + QString::number(elementsLimit);
    request.setUrl(QUrl(url + "&page=" + QString::number(currentPage) + "&limit=" + QString::number(elementsLimit)));

    replies.append(downloadManager.get(request));
}

QString API::getData(const QString &txt) const
{
    return data[txt];
}

QStringList API::getReturnedObject(QString objectName) const
{
    QStringList objectData;

    objectName = objectName.toUpper();
    qDebug() << "ObjectName: " << objectName;
    QJsonObject object = returnedObjects[objectName];
    qDebug() << object.count();

//    for(auto it = object.begin(); it != object.end(); ++it)
//    {
//        qDebug() << *it;
//    }

    QFile dataTemplate(dataPath + "/detailedDataTemplate.txt");

    if(!dataTemplate.exists() || dataTemplate.size() == 2)
    {
        qDebug() << "DataTemplate isn't exists";
        return QStringList();
    }

    if(!dataTemplate.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed open dataTemplate";
    }

    QTextStream stream(&dataTemplate);
    QString key;
    key = stream.readLine();
    do
    {
        QString returnedValue = object.value(key).toString();

        qDebug() << "Key: " << key << "  " << returnedValue;

        if(key == "krs_podmioty.firma" || key == "krs_podmioty.forma_prawna_str" || key == "krs_podmioty.cel_dzialania" ||
                key == "krs_podmioty.sposob_reprezentacji" || key == "krs_podmioty.oznaczenie_sadu" ||
                key == "krs_podmioty.nazwa_organu_reprezentacji")
        {
            returnedValue = returnedValue.toLower();
            returnedValue[0] = returnedValue[0].toUpper();
        }

        if(key == "krs_podmioty.www")
            returnedValue = returnedValue.toLower();

//        if(key == "krs_podmioty.sygnatura_akt")
//        {
//            qDebug() << "Key: " << key;
//            qDebug() << "Returned value: " << returnedValue;
//        }

        if(returnedValue == "" || returnedValue == "0")
            returnedValue = "-";

        objectData << returnedValue;
        key = stream.readLine();
    } while(!key.isNull());

//    do
//    {
//        objectData << dataTemplate.readLine();
//    } while((objectData.end() - 1)->isNull());

//    qDebug() << *(objectData.end() - 1);

    return objectData;
}

bool API::jsonParser(const QString &fileName)
{

    QFile file(dataPath + "/" + fileName + ".json");
    qDebug() << "(Parser)File name: " << file.fileName();
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed open JsonFile";
        qDebug() << file.fileName() ;
        return false;
    }

    QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonObject object = document.object();
    if(object.isEmpty())
    {
        qDebug() << "Empty";
        return false;
    }
    else
        qDebug() << "Not empty";

    qDebug() << "Count: " << object.count();
    qDebug() << "Keys: " << object.keys();

    QJsonValue valueDataobject = object.value("Dataobject");
//    qDebug() << "valueDataobject: " << valueDataobject; //Print main array

    QJsonArray mainArrayDataobject;
    if(valueDataobject.isArray())
    {
        qDebug() << "dataobject is array";
        mainArrayDataobject = valueDataobject.toArray();
    }
    else if(valueDataobject.isObject())
    {
        qDebug() << "dataobject is object";
        return false;
    }
    else
    {
        qDebug() << "Nani?";
        return false;
    }

//    qDebug() << mainArrayDataobject.

//    qDebug() << mainArrayDataobject.first();
//    int i = 0;
//    for(auto it = mainArrayDataobject.begin(); it != mainArrayDataobject.end(); ++it)
//    {
//        qDebug() << "i: " << i << ": " << *it << "\n";
//        ++i;
//    }
//    qDebug() << "Last i: " << i;

    QJsonObject mainObject(mainArrayDataobject.first().toObject());

    /// Print all data in one object
////    qDebug() << mainObject;
//    qDebug() << "Data in one object: ";
//    qDebug() << "Count: " << mainObject.count();
////    qDebug() << "id: " << mainObject.value("id").toString();
//    QStringList keys = mainObject.keys();
//    for(auto it = keys.begin(); it != keys.end(); ++it)
//    {
//        qDebug() << "Key: " << *it;
//        qDebug() << "Value: " << mainObject.value(*it);
//    }

    qDebug() << "Main data in one object:";
    QJsonObject data(mainObject.value("data").toObject());
//    qDebug() << data;
//    QStringList keysMainData = data.keys();
//    for(auto it = keysMainData.begin(); it != keysMainData.end(); ++it)
//    {
//        qDebug() << "Key: " << *it;
//        qDebug() << "Value: " << data.value(*it);
//    }
    /// Data
    /// Print:
    /// Forma, adres, krs, nip, regon, kapital
//    qD
    qDebug() << "Forma prawna: " << data.value("krs_podmioty.forma_prawna_str").toString().toLower();
    qDebug() << "Pełny adres: " << data.value("krs_podmioty.adres_lokal").toString() << " " <<
                data.value("krs_podmioty.adres_miejscowosc").toString() << " " <<
                data.value("krs_podmioty.adres_kod_pocztowy").toString() << " " <<
                data.value("krs_podmioty.adres_kraj").toString();
    qDebug() << "KRS: " << data.value("krs_podmioty.krs").toString();
    qDebug() << "NIP: " << data.value("krs_podmioty.nip").toString();
    qDebug() << "REGON: " << data.value("krs_podmioty.regon").toString();
    qDebug() << "Kapitał: " << data.value("krs_podmioty.wartosc_kapital_zakladowy").toString().toInt();
}

QStringList API::getObjectsList(const QString &fileName)
{
    QFile file(dataPath + "/" + fileName + ".json");
    qDebug() << "(Parser)File name: " << file.fileName();
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed open JsonFile";
        qDebug() << file.fileName() ;
        return QStringList();
    }

    QJsonDocument mainDocument = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonObject mainObject = mainDocument.object();
//    qDebug() << "Main object: " << mainObject;
//    qDebug() << mainObject.count();

    QJsonValue dataobjectValue = mainObject.value("Dataobject");

    if(dataobjectValue.isArray())
        qDebug() << "dataobjectValue is array";
    else if(dataobjectValue.isObject())
        qDebug() << "dataobjectValue is object";
    else
    {
        qDebug() << "Nani?";
        return QStringList();
    }

    QJsonArray dataobjectArray = dataobjectValue.toArray();
//    qDebug() << "Count of objects: " << dataobjectArray.length();
//    qDebug() << "Count of objects: " << dataobjectArray.size();
    qDebug() << "Count of objects: " << dataobjectArray.count();

//    qDebug() << dataobjectArray.first() << "\n";
//    qDebug() << dataobjectArray.last();

//    if(dataobjectArray.first().isArray())
//        qDebug() << "Is array";
//    else if(dataobjectArray.first().isObject())
//        qDebug() << "Is object";

//int i = 0;
    QStringList objectsList;
    returnedObjects.clear();
    for(auto object = dataobjectArray.begin(); object != dataobjectArray.end(); ++object)
    {
//        qDebug() << *object;
//        ++i;
//        qDebug() << i;

        QJsonObject singleKRSObject = object->toObject();
//        objectsList << singleObject.value()

//        qDebug() << singleKRSObject.value("data") << "\n";

        QJsonObject dataSingleKRSObject = singleKRSObject.value("data").toObject();

        returnedObjects[dataSingleKRSObject.value("krs_podmioty.nazwa_skrocona").toString()] = singleKRSObject.value("data").toObject();

        QString shortName = dataSingleKRSObject.value("krs_podmioty.nazwa_skrocona").toString().toLower();
        if(shortName[0] == '"')
            shortName[1] = shortName[1].toUpper();
        else
            shortName[0] = shortName[0].toUpper();
        objectsList << shortName;
//        objectsList << dataSingleKRSObject.value("krs_podmioty.firma").toString();
        objectsList << dataSingleKRSObject.value("krs_podmioty.krs").toString();
    }

    return objectsList;
}

void API::downloadFinished(QNetworkReply *reply)
{
//    qDebug() << reply->url().toString().split("=")[1];
    if(reply->error())
    {
        qDebug() << "Download failed\n" << reply->errorString();
    }
    else
    {
        QString replyName = reply->url().toString().split("=")[1].split("&")[0];
        qDebug() << "ReplyName: " << replyName;
        data[replyName] = reply->readAll();
//        qDebug() << "data[replyName]: " << data[replyName];
        QFile file(dataPath + "/" + replyName + ".json");
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Failed open file\n" << file.errorString()
                     << "\nFile name: " << file.fileName();
        }
        else
        {
            QTextStream out(&file);
            file.resize(0);
            out << data[replyName];
            file.close();
            emit readyRead();
        }

    }
}
