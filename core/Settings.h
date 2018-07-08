#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT
public:
    static Settings *instance();


public slots:
    QString splashScreen();
    QString videoFolder();
    bool isDebug();

private:
    Settings(QObject *parent = nullptr);

    QSettings *settings_;

    const QString SPLASH_SCREEN = "splash_screen";
    const QString VIDEO_FOLDER = "video_folder";
    const QString IS_DEBUG = "debug";
};

#endif // SETTINGS_H
