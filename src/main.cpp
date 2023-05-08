#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>
#include <QQuickWindow>
#include <QQuickStyle>

#include "calibcoord.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("ParkerInt64");
    QCoreApplication::setOrganizationDomain("https://github.com/parker-int64");
    QCoreApplication::setApplicationName("CalibrationApp");
    QQuickStyle::setStyle("Basic");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<CalibCoord>("Qt.CalibCoord", 0, 1, "CalibCoord");



    const QUrl url(u"qrc:/Calibration/qml/App.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
