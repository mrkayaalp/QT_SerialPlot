#include <QApplication>
#include <QQmlApplicationEngine>
#include "qwindowdefs.h"
#include "serialmanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<SerialManager>("Moon", 1, 0, "SerialManager");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/SerialAndPlot/main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
