#ifndef VIDEOROTATOR_H
#define VIDEOROTATOR_H

#include <QObject>
#include <QTimer>

#include <core/VideoGridViewer.h>

class VideoRotator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* videoViewer READ videoViewer WRITE setVideoViewer NOTIFY videoViewerChanged)
    Q_PROPERTY(int interval READ interval WRITE setInterval NOTIFY intervalChanged)
    Q_PROPERTY(bool active READ active WRITE setActive)
    Q_PROPERTY(VideoGridViewer* videoGrid READ videoGridViewer WRITE setVideoGridViewer)

public:
    explicit VideoRotator(QObject *parent = nullptr);

    QObject *videoViewer() const;
    void setVideoViewer(QObject *videoViewer);

    int interval();
    void setInterval(int interval);

    bool active();
    void setActive(bool active);

    VideoGridViewer *videoGridViewer() const;
    void setVideoGridViewer(VideoGridViewer *fileWatcher);

signals:
    void videoViewerChanged();
    void intervalChanged();

private slots:
    void onTimerTimeout();
    void onPlaybackEnd();

private:
    VideoGridViewer *videoGridViewer_;
    QObject *videoViewer_;
    QTimer *timer_;
    bool isActive_ = false;
    int currentIndex_ = -1;

    QString newFile();
};

#endif // VIDEOROTATOR_H
