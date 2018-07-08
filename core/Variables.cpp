#include "Variables.h"

QString Variables::settingsFilePath()
{
    return QDir::toNativeSeparators(qApp->applicationDirPath() + "/config.ini");
}
