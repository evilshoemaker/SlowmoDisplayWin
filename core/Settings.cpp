#include "Settings.h"

#include <QDir>
#include <QUrl>

#include <core/Variables.h>

Settings *Settings::instance()
{
    static Settings instance;
    return &instance;
}

QString Settings::splashScreen()
{
    QString filePath = settings_->value(SPLASH_SCREEN, "").toString();
    return QUrl::fromLocalFile(filePath).toString();
}

QString Settings::videoFolder()
{
    return settings_->value(VIDEO_FOLDER, "").toString();
}

bool Settings::isDebug()
{
    return settings_->value(IS_DEBUG, false).toBool();
}

int Settings::interval()
{
    return settings_->value(INTERVAL, 5).toInt();
}

Settings::Settings(QObject *parent) :
    QObject(parent),
    settings_(new QSettings(Variables::settingsFilePath(), QSettings::IniFormat))
{
    //settings_->setValue(SCREENSAVER_PICTURE, "1");
    //settings_->setValue(VIDEO_FOLDER, "1");
    //settings_->sync();
}
