#include "ftp.h"

FTP::FTP(QObject* parent, const QString& path) :
    QObject(parent),
    filepath(path)
{
    ftpProcess = DOWNLOAD;
    file = NULL;
    startDownload = false;
}

// cppcheck-suppress unusedFunction
void FTP::connectToFTP(const QString& ip, const QString& name, const QString& username, const QString& password, FTPProcess ftpProc, const QString& protocol)
{
    ftpProcess = ftpProc;
    startDownload = true;

    if(protocol.simplified().toLower() == "ftp")
        strProtocol = "ftp";
    else
        strProtocol = "ftps";

    QFtp *ftp = new QFtp(this);
    ftp->setTransferMode(QFtp::Passive);
    connect(ftp, SIGNAL(done(bool)), this, SLOT(ftpDone(bool)));
    connect(ftp, SIGNAL(stateChanged(int)), this, SLOT(ftpStateChanged(int)));
    connect(ftp, SIGNAL(commandFinished(int,bool)), this, SLOT(ftpCommandFinished(int,bool)));

    QString urlstr;

    urlstr = strProtocol+"://"+username+":"+password+"@"+ip;

    QUrl url(urlstr);
    if(strProtocol == "ftp")
        ftp->connectToHost(url.host(), 21);
    else
        ftp->connectToHost(url.host(), 990);

    filename = name;
    userName = username;
    Password = password;
    errMsg.clear();
}

void FTP::waitForFinished()
{
    while(startDownload)
    {
        qApp->processEvents();
        ::usleep(400);
    }
}

// cppcheck-suppress unusedFunction
void FTP::ftpCommandFinished(int, bool error)
{
    QFtp *ftpobj = qobject_cast<QFtp*> (sender());

    if (ftpobj->currentCommand() == QFtp::Get || ftpobj->currentCommand() == QFtp::Put)
    {
        if(error)
        {
            file->close();
            file->remove();
            delete file;
            return;
        }
        else
        {
            errMsg.clear();
            file->close();
        }
        startDownload = false;
    }
}

// cppcheck-suppress unusedFunction
void FTP::ftpStateChanged(int state)
{
    QFtp *ftpobj = qobject_cast<QFtp*> (sender());
    switch(state)
    {
    case 3:
        ftpobj->login(QUrl::fromPercentEncoding(userName.toLatin1()), Password);
        break;
    case 4:
    {
        QFileInfo fi(filename);
        QString tmpFilePath = QString("/tmp/") + fi.fileName();

        file = new QFile((ftpProcess == DOWNLOAD)?tmpFilePath:filename);
        if(!file->open((ftpProcess == DOWNLOAD)?QIODevice::WriteOnly:QIODevice::ReadOnly))
        {
            errMsg = tr("Unable to save the file");
            delete file;
            return;
        }
        if(ftpProcess == DOWNLOAD)
            ftpobj->get(filename, file);
        else
            ftpobj->put(file, fi.fileName());
        break;
    }
    }
}

// cppcheck-suppress unusedFunction
void FTP::ftpDone(bool error)
{
    QFtp *ftpobj = qobject_cast<QFtp*> (sender());
    if(error)
        errMsg = ftpobj->errorString();
    else
    {
        if(ftpProcess == DOWNLOAD)
        {
            QFile::remove(filepath);
            file->copy(QString(filepath));
            file->remove();
        }
        delete file;
    }
    startDownload = false;
}

// cppcheck-suppress unusedFunction
QString FTP::getErrorMessage()
{
    return errMsg;
}
