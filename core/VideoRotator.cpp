#include "VideoRotator.h"

#include <QMetaMethod>
#include <QDebug>

VideoRotator::VideoRotator(QObject *parent) :
    QObject(parent),
    timer_(new QTimer(this))
{
    connect(timer_, &QTimer::timeout, this, &VideoRotator::onTimerTimeout);
}

QObject *VideoRotator::videoViewer() const
{
    return videoViewer_;
}

void VideoRotator::setVideoViewer(QObject *videoViewer)
{
    if (videoViewer_ == videoViewer)
        return;

    videoViewer_ = videoViewer;

    connect(videoViewer_, SIGNAL(playbackEnd()), this, SLOT(onPlaybackEnd()));

    emit videoViewerChanged();
}

int VideoRotator::interval()
{
    return timer_->interval() / 1000;
}

void VideoRotator::setInterval(int interval)
{
    if ((timer_->interval() / 1000) == interval)
        return;

    timer_->setInterval(interval * 1000);
    emit intervalChanged();
}

bool VideoRotator::active()
{
    return isActive_;
}

void VideoRotator::setActive(bool active)
{
    if (isActive_ == active)
        return;

    isActive_ = active;

    if (isActive_ == true)
    {
        timer_->start();
    }
    else
    {
        timer_->stop();

        if (videoViewer_ != nullptr)
        {
            QMetaObject::invokeMethod(videoViewer_, "stop", Qt::QueuedConnection);
        }
    }
}

void VideoRotator::onTimerTimeout()
{
    if (videoViewer_ != nullptr)
    {
        QString filePath = newFile();
        if (!filePath.isEmpty())
        {
            QMetaObject::invokeMethod(videoViewer_, "play", Qt::QueuedConnection, Q_ARG(QVariant, filePath));
            timer_->stop();
        }
    }
}

void VideoRotator::onPlaybackEnd()
{
    if (isActive_ == true)
    {
        timer_->start();
    }
}

QString VideoRotator::newFile()
{
    if (videoGridViewer_ == nullptr)
        return "";

    currentIndex_++;
    QStringList files = videoGridViewer_->files();
    if (currentIndex_ < files.size())
    {
        return files.at(currentIndex_);
    }
    else if (!files.isEmpty())
    {
        currentIndex_ = 0;
        return files.at(currentIndex_);
    }
    return "";
}

VideoGridViewer *VideoRotator::videoGridViewer() const
{
    return videoGridViewer_;
}

void VideoRotator::setVideoGridViewer(VideoGridViewer *videoGridViewer)
{
    videoGridViewer_ = videoGridViewer;
}
