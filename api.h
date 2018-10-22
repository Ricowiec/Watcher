#ifndef API_H
#define API_H

#include <memory>

#include <QObject>
#include <QDir>
#include <QFile>
#include <QStandardPaths>
#include <QString>

/// Json
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

/// For android
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkConfiguration>

/// For windows
#include <QProcess>
#include <QThread>

class API : public QObject
{
    Q_OBJECT

    QNetworkAccessManager downloadManager;
    QVector<QNetworkReply *> replies;
    QMap<QString, QString> data;

    QString dataPath;

    bool createDataFolder();
    bool createDataTemplate();
    bool createObserved();

    unsigned int currentPage = 1;
    unsigned int elementsLimit = 23;
    QString currentSearchText;

    QMap<QString, QJsonObject> returnedObjects;

public:
    API();

    /// Windows
    Q_INVOKABLE void requestToCurl(const QString &request);

    /// Android
    Q_INVOKABLE void request(const QString &request);
    Q_INVOKABLE QString getData(const QString &txt) const;

    Q_INVOKABLE QStringList getReturnedObject(QString objectName) const;

    Q_INVOKABLE bool jsonParser(const QString &fileName);

    Q_INVOKABLE QStringList getObjectsList(const QString &fileName);

    Q_INVOKABLE void setCurrentPage(const unsigned int &number) { currentPage = number; }
    Q_INVOKABLE unsigned int getCurrentPage() const { return currentPage; }

    Q_INVOKABLE void setElementsLimit(const unsigned int &limit) { elementsLimit = limit; }
    Q_INVOKABLE unsigned int getElementsLimit() const { return elementsLimit; }

    Q_INVOKABLE QString getCurrentSearchText() const { return currentSearchText; }

private slots:
    void downloadFinished(QNetworkReply *reply);

signals:
    void readyRead();
};

#endif // API_H
