#include "http.h"

HTTP::HTTP(QObject* parent, const QString& path) :
    QObject(parent),
    filepath(path)
{
    file = NULL;
    startDownload = false;
    httpRequestAborted = false;
    reply = nullptr;
}

void HTTP::downloadFile(const QString& ip,const QString& name, const QString& username, const QString& password, const QString& strprotocol)
{
    errMsg.clear();
    startDownload = true;
    QString URLstr ;

    protocol = strprotocol;

    if(strprotocol.toLower() == "https")
    {
        if(name.startsWith("/"))
            URLstr = "https://"+ip+name.simplified();
        else
            URLstr = "https://"+ip+"/"+name.simplified();
    }
    else if(strprotocol.toLower() == "http")
    {
        if(username.length() && password.length())
            URLstr = "http://"+username+":"+password+"@"+ip+"/"+name;
        else
            URLstr = "http://"+ip+"/"+name;
    }

    url = URLstr;
    QFileInfo fileInfo(url.path());
    QString fileName = fileInfo.fileName();
    if (fileName.isEmpty())
        fileName = "index.html";

    file = new QFile(fileName);
    if (!file->open(QIODevice::WriteOnly))
    {
        errMsg = tr("Unable to save the file %1: %2.").arg(fileName).arg(file->errorString());
        delete file;
        file = NULL;
        startDownload = false;
        return;
    }
    httpRequestAborted = false;
    startRequest(url);
}

void HTTP::startRequest(QUrl url)
{
    reply = qnam.get(QNetworkRequest(url));
    connect(reply, SIGNAL(finished()), this, SLOT(httpFinished()));
    connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));

}

// cppcheck-suppress unusedFunction
void HTTP::httpFinished()
{
    if (httpRequestAborted)
    {
        if (file)
        {
            file->close();
            file->remove();
            delete file;
            file = NULL;
        }
        reply->deleteLater();
        return;
    }

    file->flush();
    file->close();


    QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if (reply->error())
    {
        file->remove();
        errMsg = reply->errorString();
        startDownload = false;
    }
    else if (!redirectionTarget.isNull())
    {
        QUrl newUrl = url.resolved(redirectionTarget.toUrl());
        url = newUrl;
        reply->deleteLater();
        file->open(QIODevice::WriteOnly);
        file->resize(0);
        startRequest(url);
        return;
    }
    else
    {
        errMsg.clear();
        startDownload = false;
        if(QFile::exists(filepath))
            QFile::remove(filepath);

        file->remove();
        delete file;
        file = NULL;
    }

    reply->deleteLater();
    reply = 0;
    delete file;
    file = 0;
}

// cppcheck-suppress unusedFunction
void HTTP::httpReadyRead()
{
    if (file)
        file->write(reply->readAll());
}

void HTTP::waitForFinished()
{
    while(startDownload)
    {
        qApp->processEvents();
        ::usleep(400);
    }
}

QString HTTP::getErrorMessage()
{
    return errMsg;
}
