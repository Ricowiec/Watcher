#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QIcon>

#include "api.h"
#include "bridge.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/Menu/Icons/spy2.png"));

//    qmlRegisterSingletonType<Bridge>("Bridge", 1, 0, "Bridge", &bridge);

    API api;
    qmlRegisterType<API>("Watcher", 1, 0, "Requester");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    Bridge bridge;
    engine.rootContext()->setContextProperty("APIBridge", &bridge);
    if (engine.rootObjects().isEmpty())
        return -1;

//    emit bridge.pushedPage();

    return app.exec();
}
