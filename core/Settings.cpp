#include "Settings.h"

#include <core/Variables.h>

Settings *Settings::instance()
{
    static Settings instance;
    return &instance;
}

QString Settings::screensaverPicture()
{
    return settings_->value(SCREENSAVER_PICTURE, "").toString();
}

QString Settings::videoFolder()
{
    return settings_->value(VIDEO_FOLDER, "").toString();
}

Settings::Settings(QObject *parent) :
    QObject(parent),
    settings_(new QSettings(Variables::settingsFilePath(), QSettings::IniFormat))
{

}
