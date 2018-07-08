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
    QString screensaverPicture();
    QString videoFolder();

private:
    Settings(QObject *parent = nullptr);

    QSettings *settings_;

    const QString SCREENSAVER_PICTURE = "screensaver_picture";
    const QString VIDEO_FOLDER = "video_folder";
};

#endif // SETTINGS_H
