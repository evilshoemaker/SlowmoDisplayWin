#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QQuickWindow>

#include <QDebug>

#include <core/Settings.h>
//#include <core/FileWatcher.h>
#include <core/VideoGridViewer.h>
#include <core/VideoRotator.h>

void registerType()
{
    qmlRegisterType<VideoRotator>("esm", 1, 0, "VideoRotator");
}

int main(int argc, char *argv[])
{
    //QCoreApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
    //QQuickWindow::setSceneGraphBackend(QSGRendererInterface::Software);

    QGuiApplication app(argc, argv);

    registerType();

    VideoGridViewer videoGridViewer(Settings::instance()->videoFolder());

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("videoGridViewer", &videoGridViewer);
    engine.rootContext()->setContextProperty("settings", Settings::instance());

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
