#include "Variables.h"

#include <QCoreApplication>
#include <QDir>

QString Variables::settingsFilePath()
{
    return QDir::toNativeSeparators(qApp->applicationDirPath() + "/config.ini");
}
