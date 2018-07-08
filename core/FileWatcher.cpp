#include "FileWatcher.h"

#include <QDir>
#include <QDebug>
#include <QThread>
#include <QThreadPool>
#include <QtConcurrent/QtConcurrent>

FileWatcher::FileWatcher(QObject *parent) : QObject(parent)
{
    connect(&sysWatcher_, SIGNAL(directoryChanged(QString)), this, SLOT(onDirectoryChanged(QString)));
    connect(&sysWatcher_, SIGNAL(fileChanged(QString)), this, SLOT(onFileChanged(QString)));
}

void FileWatcher::addWatchPath(const QString &path)
{
    sysWatcher_.addPath(path);

    QFileInfo fileInfo(path);
    if(fileInfo.isDir())
    {
        const QDir dirw(path);
        currContents_[path] = dirw.entryList(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files, QDir::Time);
    }
}

QStringList FileWatcher::files()
{
    QStringList fileList;
    for (const QString &dir : currContents_.keys())
    {
        for (const QString &fileName : currContents_[dir])
        {
            QString fullPath = QDir(dir).filePath(fileName);
            QFileInfo fileInfo(fullPath);
            if (fileInfo.exists())
            {
                fileList << fullPath;
            }
        }
    }

    return fileList;
}

void FileWatcher::onFileChanged(const QString &path)
{
    QFileInfo file(path);
    QString path1 = file.absolutePath();
    QString name = file.fileName();
    qDebug()<<"The file "<<name<<" at path "<<path1<<" is updated";
}

void FileWatcher::onDirectoryChanged(const QString &path)
{
    QtConcurrent::run(QThreadPool::globalInstance(), this, &FileWatcher::directoryCheck, path);
}

void FileWatcher::directoryCheck(const QString &path)
{
    QStringList currEntryList = currContents_[path];
    const QDir dir(path);

    QStringList newEntryList = dir.entryList(QDir::NoDotAndDotDot  | QDir::AllDirs | QDir::Files, QDir::Time);

    QSet<QString> newDirSet = QSet<QString>::fromList( newEntryList );

    QSet<QString> currentDirSet = QSet<QString>::fromList( currEntryList );

    // Files that have been added
    QSet<QString> newFiles = newDirSet - currentDirSet;
    QStringList newFileList = newFiles.toList();

    // Files that have been removed
    QSet<QString> deletedFiles = currentDirSet - newDirSet;
    QStringList deleteFileList = deletedFiles.toList();

    // Update the current set
    currContents_[path] = newEntryList;

    if (!newFileList.isEmpty() && !deleteFileList.isEmpty())
    {
        // File/Dir is renamed

        if (newFileList.count() == 1 && deleteFileList.count() == 1)
        {
            //qDebug()<<"File Renamed from "<<newFileList.first()<<" to "<<deleteFileList.first();
        }
    }

    else
    {
        // New File/Dir Added to Dir
        if(!newFileList.isEmpty())
        {
            for (QString fileName : newFileList)
            {
                QFile file(QDir(path).filePath(fileName));

                while (true)
                {
                    if (!file.exists())
                        break;

                    if (file.open(QIODevice::WriteOnly | QIODevice::Append))
                    {
                        file.close();
                        //qDebug() << "new file " << fileName;
                        emit newFile(file.fileName());
                        break;
                    }

                    QThread::msleep(500);
                }
            }
        }

        // File/Dir is deleted from Dir
        if (!deleteFileList.isEmpty())
        {
            for (const QString &fileName : deleteFileList)
            {
                QFile file(QDir(path).filePath(fileName));
                emit deleteFile(file.fileName());
            }
        }

    }
}
