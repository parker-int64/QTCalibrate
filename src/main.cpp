#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>
#include <QQuickWindow>
#include <QQuickStyle>
#include <QString>
#include <QVariant>
#include <QMap>

QMap<QString, QVariant> properties(){
    QMap<QString, QVariant> map;
    return map;
}
int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("ParkerInt64");
    QCoreApplication::setOrganizationDomain("https://github.com/parker-int64");
    QCoreApplication::setApplicationName("CalibrationApp");
    QQuickStyle::setStyle("Basic");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QMapIterator<QString, QVariant> iterator(properties());

    while (iterator.hasNext()) {
        iterator.next();
        QString key = iterator.key();
        QVariant value = iterator.value();
        engine.rootContext()->setContextProperty(key,value);
    }

    // registry the QMap
    engine.rootContext()->setContextProperty("properties",properties());
    const QUrl url(u"qrc:/qml/App.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
