#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QStringList>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include "lcore.h"

QStringList strValues;
void SDMessageHandler(QtMsgType type, const char *msg)
{
    QString txt;
    QString str_datetime = QDateTime::currentDateTime().toString("MMM dd hh:mm:ss yyyy");
    switch (type) {
    case QtDebugMsg:
        txt = QString("%3:: %2:: %1").arg(msg).arg("LCore").arg(str_datetime);
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);
        break;
    case QtCriticalMsg:
        txt = QString("Critical: %1").arg(msg);
        break;
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);
        abort();
    }

    QFile outFile(QString(DBGFILENAME));

    if(outFile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream ts(&outFile);
        for(int i = 0; i < strValues.count(); i++)
        {
           QString strPriority = "::"+strValues.at(i)+"::";
           if(txt.simplified().contains(strPriority))
           {
                ts << txt .simplified()<<endl;
           }

        }        outFile.close();
    }
}

int main(int argc, char *argv[])
{
    QStringList strListDefVal;
    LCore liblcore;
    strListDefVal = liblcore.readDefaultsValue(QString("DebugLevel"));
    if(!strListDefVal.isEmpty())
    {
        QString strDefVal = strListDefVal.at(1);
        strValues << strDefVal.simplified().split("|");
    }
    else
    {
        strValues << "1";
    }

    if(strValues.count() && strValues.at(0).toInt())
    {
        qInstallMsgHandler(SDMessageHandler);
    }

    QCoreApplication a(argc, argv);

    return a.exec();
}
