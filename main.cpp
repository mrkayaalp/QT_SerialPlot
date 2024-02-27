#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "serialmanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<SerialManager>("Moon", 1, 0, "SerialManager");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/SerialAndPlot/main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
