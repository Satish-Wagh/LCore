#ifndef HTTP_H
#define HTTP_H

#include <QHttp>
#include <QFile>
#include <QObject>
#include <QDebug>
#include <QUrl>
#include <QtGui/QApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFileInfo>
#include <unistd.h>
#include <QDir>
#include <QSslError>
#include <QSsl>
#include <QSslKey>
//#include <QSslSocket>
#include <QSslConfiguration>
#define CERTIFICATEPATH         "/usr/local/share/ca-certificates"

class HTTP : public QObject
{
    Q_OBJECT
public:
    explicit HTTP(QObject *parent = 0, const QString &path = "");
//    void downloadFile(QString, QString, QString = "", QString = "");
    void downloadFile(const QString&, const QString&, const QString& = "", const QString& = "", const QString& = ""); // new parameter is added for protocol(https)
    QString getErrorMessage();
    void waitForFinished();

private slots:
    void startRequest(QUrl);
    void httpFinished();
    void httpReadyRead();
 //   void sslErrorHandler(QNetworkReply* qnr, const QList<QSslError> & errlist);

private:
    QFile *file = nullptr;
    QString filename = "", userName = "", Password = "", errMsg = "", filepath = "", protocol = "";
    bool startDownload = false, httpRequestAborted = false;
    QNetworkAccessManager qnam;
    QNetworkReply *reply = nullptr;
    QUrl url;
};

#endif // HTTP_H
