#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QDebug>

#include <core/Settings.h>
//#include <core/FileWatcher.h>
#include <core/VideoRotator.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    VideoRotator videoRotator(Settings::instance()->videoFolder());

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("videoRotator", &videoRotator);
    engine.rootContext()->setContextProperty("settings", Settings::instance());

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
