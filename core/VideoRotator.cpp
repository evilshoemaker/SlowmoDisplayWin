#include "VideoRotator.h"

#include <QDebug>

#include "core/Settings.h"

VideoRotator::VideoRotator(const QString &videoFolder, QObject *parent) :
    QObject(parent)
{
    fileWatcher_.addWatchPath(videoFolder);
    connect(&fileWatcher_, &FileWatcher::newFile, this, &VideoRotator::onNewFile);
    //connect(&fileWatcher_, &FileWatcher::deleteFile, this, &VideoRotator::onRemoveFile);

    isDebug_ = Settings::instance()->isDebug();
}

void VideoRotator::addMediaPlayer(QObject *mp)
{
    //mediaPlayerList_.append(mp);
    mediaPlayerQueue_.enqueue(mp);
}

void VideoRotator::init()
{
    QStringList files = fileWatcher_.files();
    for (int i = 0; i < files.size(); i++)
    {
        onNewFile(files.at(i));
    }
}

void VideoRotator::onNewFile(const QString &fileName)
{
    if (isDebug_)
    {
        qDebug() << "Added new file" << fileName;
    }

    if (!mediaPlayerQueue_.isEmpty())
    {
        QObject *mp = mediaPlayerQueue_.dequeue();
        mp->setProperty("videoSource", fileName);
        mediaPlayerQueue_.enqueue(mp);
    }
}
