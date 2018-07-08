#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include <QObject>
#include <QQueue>

#include "core/FileWatcher.h"

class VideoRotator : public QObject
{
    Q_OBJECT
public:
    explicit VideoRotator(const QString &videoFolder, QObject *parent = nullptr);

signals:

public slots:
    void addMediaPlayer(QObject *mp);
    void init();

private slots:
    void onNewFile(const QString &fileName);

private:
    bool isDebug_ = false;

    FileWatcher fileWatcher_;
    QObjectList mediaPlayerList_;
    QQueue<QObject *> mediaPlayerQueue_;
};

#endif // FILESTORAGE_H
