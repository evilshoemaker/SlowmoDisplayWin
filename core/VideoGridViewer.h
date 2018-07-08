#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include <QObject>
#include <QQueue>

#include "core/FileWatcher.h"

class VideoGridViewer : public QObject
{
    Q_OBJECT
public:
    explicit VideoGridViewer(const QString &videoFolder, QObject *parent = nullptr);

signals:

public slots:
    void addMediaPlayer(QObject *mp);
    void init();
    QStringList files();

private slots:
    void onNewFile(const QString &fileName);

private:
    bool isDebug_ = false;

    FileWatcher fileWatcher_;
    QObjectList mediaPlayerList_;
    QQueue<QObject *> mediaPlayerQueue_;
};

#endif // FILESTORAGE_H
