#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>

class FileWatcher : public QObject
{
    Q_OBJECT
public:
    explicit FileWatcher(QObject *parent = nullptr);

signals:

public slots:
};

#endif // FILEWATCHER_H