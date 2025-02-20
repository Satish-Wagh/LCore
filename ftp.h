#ifndef FTP_H
#define FTP_H

#include <QFtp>
#include <QFile>
#include <QFileInfo>
#include <QObject>
#include <QDebug>
#include <QUrl>
#include <QtGui/QApplication>
#include <QVariant>
#include <unistd.h>

class FTP : public QObject
{
    Q_OBJECT
public:
    enum FTPProcess{DOWNLOAD, UPLOAD};
    explicit FTP(QObject *parent = 0, const QString &path = QString());
    void connectToFTP(const QString&, const QString&, const QString&, const QString&, FTPProcess, const QString&);
    QString getErrorMessage();
    void waitForFinished();

private slots:
    void ftpDone(bool);
    void ftpStateChanged(int);
    void ftpCommandFinished(int, bool);

private:
    QFile *file = nullptr;
    QString filename = "", userName = "", Password = "", errMsg = "", filepath = "", strProtocol = "";
    bool startDownload = false;
    FTPProcess ftpProcess = DOWNLOAD;
};
#endif // FTP_H
