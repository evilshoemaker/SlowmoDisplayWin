#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QFileSystemWatcher>
#include <QMap>

class FileWatcher : public QObject
{
    Q_OBJECT
public:
    explicit FileWatcher(QObject *parent = nullptr);

public slots:
    void addWatchPath(const QString &path);
    QStringList files();

signals:
    void newFile(const QString &fileName);
    void deleteFile(const QString &fileName);

private slots:
    void onFileChanged(const QString &path);
    void onDirectoryChanged(const QString &path);

private:
    QMap<QString, QStringList> currContents_;
    QFileSystemWatcher sysWatcher_;
    void directoryCheck(const QString &path);
};

#endif // FILEWATCHER_H
