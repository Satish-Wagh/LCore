#ifndef LCORE_H
#define LCORE_H

#include"aesencryptionlib.h"
#include <libintl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <libgen.h>
#include <time.h>
#include <sys/time.h>
#include <dirent.h>
#include <ctype.h>
#include <features.h>
#include <linux/hdreg.h>

#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFrame>
#include <QDesktopWidget>

#include <QDebug>
#include <QProcess>
#include <QObject>
#include <QtNetwork/QNetworkInterface>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QHostInfo>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QHostAddress>
#include <QVariant>
#include <QtSql/QSqlRecord>
#include <QtGui/QLabel>
#include <QtGui/QMovie>
#include <QtGui/QWidget>
#include <QFileInfo>
#include <QtGui/QMessageBox>
#include <QtGlobal>
#include <QTimer>
#include <QtGui/QDesktopWidget>
#include <QtGui/QApplication>
#include <QtGui/QX11Info>
#include <QtGui/QMenu>
#include <QtGui/QWidgetItem>

#include <iostream>
#include <cstring>
#include <sys/ioctl.h>
#include <arpa/inet.h>
//#include <linux/if.h>
#include <net/if.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <error.h>
#include <errno.h>
#include <err.h>
#include <qsharedmemory.h>
#include <QSharedMemory>
#include <QBuffer>
#include <QtGui/QX11Info>
#include <QtGui/QValidator>
#include <QList>
#include <sys/mount.h>
#include <QCryptographicHash>
//#include <libexplain/tcsetattr.h>
#include <QThread>
#include <QTextCodec>
#include <QLocalSocket>
#include <mcrypt.h>
#include <fstream>
#include <libudev.h>

#include <ldap.h>

#include "defineslcore.h"
#include "ftp.h"
#include "http.h"
#include "qballoontip.h"
#include "customfiledialog.h"
#include "Localcredentialdialog.h"
#include "qtjson.h"
#include <curl/curl.h>

#include <execinfo.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ucontext.h>
#include <unistd.h>
#include <cxxabi.h>

using QtJson::JsonObject;

using namespace std;

class threadgetdevices : public QThread
{
public:
    QString cmd = "";
    QStringList usbdevices = QStringList();
    QStringList networkdevices = QStringList();
    QStringList networkmakemodel = QStringList();

public:
    threadgetdevices() : strClass(QString("USB"))
    {

    }

    ~threadgetdevices()
    {

    }

    // cppcheck-suppress unusedFunction
    void setClass(const QString& strClassValue)
    {
        strClass = strClassValue;
    }

    // cppcheck-suppress unusedFunction
    QString getClass()
    {
        return strClass;
    }

private:
    QString strClass;

private:
    // cppcheck-suppress unusedFunction
    void run()
    {
        if(strClass == QString("USB"))
        {
#if 1
            QMap<QString, QString> mapUsbDeviceIds;

            QDir dir("/dev/usb");

            if(dir.exists() == true)
            {
                dir.setFilter(QDir::Files | QDir::System);

                QString strSysUsbPath = QString("/sys/class/usb");

                if(QDir(strSysUsbPath).exists() == false)
                {
                    qDebug() << strSysUsbPath << "not found";

                    strSysUsbPath = QString("/sys/class/usbmisc");

                    qDebug() << "Trying " << strSysUsbPath;
                }

                if(QDir(strSysUsbPath).exists() == true)
                {
                    QFileInfoList listFileInfo = dir.entryInfoList();

                    for(int i = 0; i < listFileInfo.size(); i++)
                    {
                        QFileInfo fileInfo = listFileInfo.at(i);
                        QString strFileName = fileInfo.fileName();

                        qDebug() << "strFileName : " << strFileName;

                        if(strFileName.startsWith("lp") == true)
                        {
                            QString strSysUsbDevicePath = QString("%1/%2/device/ieee1284_id").arg(strSysUsbPath, strFileName);

                            QFile fileRead(strSysUsbDevicePath);

                            if(fileRead.open(QIODevice::ReadOnly | QIODevice::Text) == true)
                            {
                                QString strDeviceId = QString(fileRead.readAll()).trimmed();
                                qDebug() << "Inserting device id " << strDeviceId << "for" << strFileName;
                                mapUsbDeviceIds.insert(strDeviceId, strFileName);

                                fileRead.close();
                            }
                        }
                    }

                    if(mapUsbDeviceIds.count() > 0)
                    {
#if 0
                        QString strCommand = QString("/usr/lib/cups/backend/usb");

                        QStringList strlistLines;
                        QProcess proc;
                        proc.start(strCommand);

                        if(proc.waitForFinished() == true)
                        {
                            strlistLines = QString(proc.readAll()).split("\n", QString::SkipEmptyParts);
                        }

                        qDebug() << "strlistUsbDevices.count(): " << strlistLines.count();

                        usbdevices.clear();
                        networkdevices.clear();

                        foreach(QString strLine, strlistLines)
                        {
                            if(strLine.startsWith("direct ") == true)
                            {
                                qDebug() << "strLine: " << strLine;

                                QStringList strlistOutput = strLine.split(' ');

                                QString strUri = strlistOutput.at(1);

                                strlistOutput = strLine.split('\"', QString::SkipEmptyParts);

                                qDebug() << "strlistOutput: " << strlistOutput;

                                QString strInfo = strlistOutput.at(1);
                                QString strMakeAndModel = strlistOutput.at(3);
                                QString strDeviceId = strlistOutput.at(5);

                                qDebug() << "strUri: " << strUri;
                                qDebug() << "strInfo: " << strInfo;
                                qDebug() << "strMakeAndModel: " << strMakeAndModel;
                                qDebug() << "strDeviceId: " << strDeviceId;

                                int nDeviceId = 0;

                                if(strDeviceId.isEmpty() == false)
                                {
                                    QString strFileName = mapUsbDeviceIds.value(strDeviceId);

                                    qDebug() << "strFileName: " << strFileName;

                                    if(strFileName.isEmpty() == false)
                                    {
                                        nDeviceId = strFileName.remove("lp").toInt() + 1;
                                    }
                                }

                                if(nDeviceId > 0)
                                {
                                    if(strInfo.isEmpty() == true)
                                    {
                                        strInfo = strMakeAndModel;
                                    }

                                    QString strDeviceInfo = QString("USB%1: %2\t%3").arg(QString::number(nDeviceId), strInfo, strUri);

                                    usbdevices.append(strDeviceInfo);
                                }
                            }
                        }
#else
                        QStringList strlistUsbDevices;
                        QProcess proc;
                        proc.start("lpinfo --timeout 2 -l -v");

                        if(proc.waitForFinished() == true)
                        {
                            strlistUsbDevices = QString(proc.readAll()).split("\n", QString::SkipEmptyParts);
                        }

                        qDebug() << "strlistUsbDevices.count(): " << strlistUsbDevices.count();

                        usbdevices.clear();
                        networkdevices.clear();

                        for(int i = 0, j = 0; i < strlistUsbDevices.count(); i += 6)
                        {
                            QString strClassCheck = strlistUsbDevices.at(j+1).section('=', 1, -1).trimmed();

                            if(strClassCheck == QString("direct"))
                            {
                                QString strUri = strlistUsbDevices.at(j).section('=', 1, -1).trimmed();
                                QString strInfo = strlistUsbDevices.at(j+2).section('=', 1, -1).trimmed();
                                QString strMakeAndModel = strlistUsbDevices.at(j+3).section('=', 1, -1).trimmed();
                                QString strDeviceId = strlistUsbDevices.at(j+4).section('=', 1, -1).trimmed();
                                int nDeviceId = 0;
                                bool bPrinterAdded = false;

                                qDebug() << "strUri: " << strUri;
                                qDebug() << "strInfo: " << strInfo;
                                qDebug() << "strMakeAndModel: " << strMakeAndModel;
                                qDebug() << "strDeviceId: " << strDeviceId;

                                if(strDeviceId.isEmpty() == false)
                                {
                                    QString strFileName = mapUsbDeviceIds.value(strDeviceId);

                                    qDebug() << "strFileName: " << strFileName;

                                    if(strFileName.isEmpty() == false)
                                    {
                                        nDeviceId = strFileName.remove("lp").toInt() + 1;
                                        bPrinterAdded = true;
                                    }
                                }

                                if(bPrinterAdded == false)
                                {
                                    QMapIterator<QString, QString> itr(mapUsbDeviceIds);
                                    while(itr.hasNext())
                                    {
                                        itr.next();
                                        QString strMapDeviceId = itr.key();

                                        if(strMapDeviceId.contains(strMakeAndModel) == true || strMapDeviceId.contains(strInfo) == true)
                                        {
                                            QString strMapFileName = itr.value();

                                            qDebug() << "strMapFileName: " << strMapFileName;

                                            if(strMapFileName.isEmpty() == false)
                                            {
                                                nDeviceId = strMapFileName.remove("lp").toInt() + 1;
                                            }

                                            break;
                                        }
                                    }
                                }

                                if(nDeviceId > 0)
                                {
                                    QString strDeviceInfo = QString("USB%1: %2\t%3").arg(QString::number(nDeviceId), strInfo, strUri);

                                    usbdevices.append(strDeviceInfo);
                                }
                            }

                            j += 6;
                        }
#endif
                    }
                }
                else
                {
                    qDebug() << strSysUsbPath << "not found";
                }
            }
            else
            {
                qDebug() << dir.dirName() << " not found";
            }
#else
            QStringList devicelist, directdevlist, printerMakeModelList;
            char procOutput[500],procOutput1[500];

            QProcess proc;
            proc.start("/usr/sbin/lpinfo --timeout 2 -l -v");

            if(proc.waitForFinished())
                devicelist = QString(proc.readAll()).split("\n");
            qDebug()<<"devicelist="<<devicelist.count();
            bool cond=false;
            int usbdevcnt=0;

            for(int i=0; i<devicelist.count(); i++)
            {
                if(devicelist.at(i).trimmed().contains(": uri =") && (devicelist.at(i+1).trimmed().contains("class = direct") || devicelist.at(i+1).trimmed().contains("clase = direct")))
                {
                    cond = true;
                }

                if(cond)
                {
                    usbdevcnt++;
                    directdevlist.append(devicelist.at(i).trimmed());

                    if(usbdevcnt==4)
                    {
                        cond=false;
                        usbdevcnt=0;
                    }
                }
            }

            QDir dir("/dev/usb/");
            if(dir.exists())
            {
                qDebug()<<"*********** inside printer ***********";
                dir.setFilter(QDir::Files | QDir::System);
                QString line1;

                int flag=0;
                QFileInfoList list = dir.entryInfoList();

                QDir USBMISC("/sys/class/usbmisc");
                QDir USB("/sys/class/usb");
                QString strPath;

                if(USBMISC.exists() && !USB.exists())
                    strPath = "cat /sys/class/usbmisc/";
                else if((!USBMISC.exists() && USB.exists()) || (USBMISC.exists() && USB.exists()))
                    strPath = "cat /sys/class/usb/";

                QString data;
                QFile file(OSBUILD_FILE);
                if (file.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    QTextStream in(&file);
                    data = in.readLine();
                    file.close();
                }
                for(int i = 0; i < list.size(); i++)
                {
                    QFileInfo fileInfo = list.at(i);
                    qDebug()<<"fileName:---------------"<<fileInfo.fileName();
                    QString baseName = fileInfo.baseName();
                    qDebug()<<"baseName:---------------"<<baseName;
                    if((line1=fileInfo.fileName()).contains("lp"))
                    {
                        memset(procOutput, 0, sizeof(procOutput));
                        bool satocheck = 0;
                        QString strOut1 ;
                        //                     if(data.contains("JHT",Qt::CaseInsensitive))
                        //                     {
                        memset(procOutput1, 0, sizeof(procOutput1));
                        //  FILE *fpProc1  = popen(QString(strPath+QString::number(i)+"/device/ieee1284_id").toLatin1().data(), "r");
                        FILE *fpProc1  = popen(QString(strPath+baseName+"/device/ieee1284_id").toLatin1().data(), "r");
                        fgets(procOutput1, sizeof(procOutput1), fpProc1);
                        procOutput1[strlen(procOutput1)-1]='\0';
                        pclose(fpProc1);

                        strOut1 = QString(procOutput1).trimmed();
                        qDebug()<<"str1out *************"<<strOut1;
                        satocheck  = strOut1.contains("MFG:SATO");
                        //                     }
                        //FILE *fpProc = popen(QString("cat /sys/class/usb/lp"+QString::number(flag)+"/device/ieee1284_id | awk -F'MANUFACTURER:|MODEL:' '{ print $2 $3 }' | awk -F';' '{ print $1 $3}'").toLatin1().data(), "r");
                        FILE *fpProc ;
                        if(data.contains("JHT",Qt::CaseInsensitive) && !satocheck)
                        {
                            //  fpProc = popen(QString(strPath+QString::number(i)+"/device/ieee1284_id ").toLatin1().data(), "r");
                            fpProc = popen(QString(strPath+baseName+"/device/ieee1284_id ").toLatin1().data(), "r");
                            qDebug()<<"Inisde jht condition ************************************";
                        }
                        else
                        {
                            // fpProc = popen(QString(strPath+QString::number(i)+"/device/ieee1284_id | awk -F'MANUFACTURER:|MODEL:' '{ print $2 $3 }' | awk -F';' '{ print $1 \" \" $3}'").toLatin1().data(), "r");
                            fpProc = popen(QString(strPath+baseName+"/device/ieee1284_id | awk -F'MANUFACTURER:|MODEL:' '{ print $2 $3 }' | awk -F';' '{ print $1 \" \" $3}'").toLatin1().data(), "r");
                        }
                        fgets(procOutput, sizeof(procOutput), fpProc);
                        procOutput[strlen(procOutput)-1]='\0';
                        pclose(fpProc);

                        QString strOut = QString(procOutput).trimmed();

                        qDebug() << "1---strOut: " << strOut;

                        if(strOut.isEmpty())
                        {
                            memset(procOutput, 0, sizeof(procOutput));
                            //fpProc = popen(QString("cat /sys/class/usb/lp"+QString::number(flag)+"/device/ieee1284_id | awk -F'DES:|DESCRIPTION:' '{ print $2 }' | awk -F';' '{ print $1}'").toLatin1().data(), "r");
                            //fpProc = popen(QString(strPath+QString::number(i)+"/device/ieee1284_id | awk -F'DES:|DESCRIPTION:' '{ print $2 }' | awk -F';' '{ print $1}'").toLatin1().data(), "r");
                            fpProc = popen(QString(strPath+baseName+"/device/ieee1284_id | awk -F'DES:|DESCRIPTION:' '{ print $2 }' | awk -F';' '{ print $1}'").toLatin1().data(), "r");
                            fgets(procOutput, sizeof(procOutput), fpProc);
                            procOutput[strlen(procOutput)-1]='\0';
                            pclose(fpProc);

                            strOut = QString(procOutput).trimmed();
                        }

                        qDebug() << "2---strOut: " << strOut;

                        if(!strOut.isEmpty())
                        {
                            memset(procOutput, 0, sizeof(procOutput));
                            fpProc = popen(QString(strPath+baseName+"/device/ieee1284_id | awk -F'DES:|DESCRIPTION:' '{ print $2 }' | awk -F';' '{ print $1}'").toLatin1().data(), "r");
                            // fpProc = popen(QString(strPath+QString::number(i)+"/device/ieee1284_id | awk -F'MDL:' '{ print $2 }' | awk -F';' '{ print $1 }'").toLatin1().data(), "r");
                            fgets(procOutput, sizeof(procOutput), fpProc);
                            procOutput[strlen(procOutput)-1]='\0';
                            pclose(fpProc);
                            qDebug()<<"procOutput = "<<procOutput;

                            if(!strOut.contains(QString(procOutput)))
                            {
                                qDebug() << "Clearing strOut as MDL not found in it";
                                strOut.clear();
                            }
                        }

                        qDebug() << "3---strOut: " << strOut;

                        if(strOut.isEmpty())
                        {
                            QStringList op;
                            //  QString cmd= QString("cat /sys/class/usbmisc/lp0/device/ieee1284_id > /tmp/tmp_printer");
                            QString cmd= QString("cat /sys/class/usbmisc/"+baseName+"/device/ieee1284_id > /tmp/tmp_printer");
                            qDebug()<<"\n\n"<<cmd<<"\n\n";
                            system(cmd.toLatin1());

                            QFile myfile("/tmp/tmp_printer");
                            if(myfile.open(QIODevice::ReadOnly | QIODevice::Text))
                            {
                                QTextStream in(&myfile);
                                while (!in.atEnd())
                                {
                                    QString line = in.readLine().trimmed();
                                    qDebug()<<"Line output : "<<line;
                                    QStringList data = line.split(";");
                                    for(int i = 0; i < data.count();i++)
                                    {
                                        if(data.at(i).startsWith("MFG:"))
                                            op.insert(0,QString(data.at(i)).remove("MFG:"));
                                        //  strOut.append(" ");
                                        if(data.at(i).startsWith("MDL:"))
                                            op.insert(1,QString(data.at(i)).remove("MDL:"));
                                    }

                                }
                            }
                            strOut = op.join(" ");
                            qDebug()<<"strOut==========="<<strOut;
                        }

                        // strOut = strOut.simplified();

                        qDebug() << "strOut: " << strOut;

                        if(strOut.contains("Hewlett-Packard") || strOut.contains("HP LaserJet"))
                        {
                            strOut = strOut.replace("Hewlett-Packard", "HP");
                            qDebug() << "new strOut: " << strOut;
                        }
                        QString strCheck;
                        QString strdata;
                        QStringList values;
                        QSqlQuery query;
                        QString qry = "SELECT * FROM SysConf WHERE Property='Language'";
                        if(query.exec(qry))
                        {
                            QSqlRecord rec = query.record();
                            //            qDebug() << "query.next() = " << query.next() << query.record();
                            while (query.next())
                            {
                                for(int i=0 ; i < rec.count(); i++)
                                {
                                    values << query.value(i).toString();
                                    //                    qDebug() << values;
                                }
                            }
                        }
                        qDebug()<<"Lang------>>>>>>"<<values;
                        if(values.contains("Spanish"))
                        {
                            qDebug()<<"if condition for Spanish";
                            if(data.contains("JHT",Qt::CaseInsensitive) && !satocheck)
                            {
                                qDebug()<<"JHT";
                                strdata = strOut.section("MDL:",1,1).section(";",0,0);
                                if(strOut1.contains("Canon"))
                                    strCheck = QString("marca y modelo = Canon ") + QString(strdata);
                                else
                                    strCheck = QString("marca y modelo = ") + QString(strdata);
                            }
                            else
                                strCheck = QString("marca y modelo = ") + QString(strOut);
                        }
                        else
                        {
                            if(data.contains("JHT",Qt::CaseInsensitive) && !satocheck)
                            {
                                strdata = strOut.section("MDL:",1,1).section(";",0,0);
                                if(strOut1.contains("Canon"))
                                    strCheck = QString("make-and-model = Canon ") + QString(strdata);
                                else
                                    strCheck = QString("make-and-model = ") + QString(strdata);
                            }
                            else
                                strCheck = QString("make-and-model = ") + QString(strOut);
                        }
                        qDebug()<<"***************************** strout condition 11" <<strOut <<"********** strcheck"<<strCheck;
                        qDebug()<<"\n\n***********8 directdevlist  "<<directdevlist;

                        if(directdevlist.contains(strCheck) && !printerMakeModelList.contains(strOut))
                        {
                            qDebug()<<"***************************** strout condition" <<strOut <<"********** strcheck"<<strCheck;
                            if(data.contains("JHT",Qt::CaseInsensitive) && !satocheck)
                            {
                                if(strOut1.contains("Canon"))
                                {
                                    QString strcanon = "Canon "+strdata;
                                    printerMakeModelList.append(strcanon);
                                }
                                else
                                    printerMakeModelList.append(strdata);
                            }
                            else
                                printerMakeModelList.append(strOut);
                        }
                        //                    flag++;
                    }
                }
            }

            // for converter
            bool bConverterConnected = false;
            for(int i=0; i<directdevlist.count(); i++)
            {
                if(directdevlist.at(i).contains(": uri ="))
                {
                    QString strCmpMakeModel = directdevlist.at(i+3).section("=", 1,1).trimmed();
                    QString strCmpInfo = directdevlist.at(i+2).section("=", 1,1).trimmed();
                    qDebug()<<"***************************** strcmpmakemodel condition 11" <<strCmpMakeModel <<"********** strcmpinfo"<<strCmpInfo;
                    if(strCmpMakeModel == QString("Unknown") && strCmpInfo == QString("Unknown"))
                    {
                        bConverterConnected = true;
                        break;
                    }
                }
            }

            if(bConverterConnected)
                printerMakeModelList.append(QString("Unknown"));
            //----------------------

            qDebug() << "printer make model: " << printerMakeModelList.count();

            usbdevices.clear();
            networkdevices.clear();

            qDebug() << "directdevlist : " << directdevlist;

            for(int i=0; i<directdevlist.count(); i++)
            {
                if(directdevlist.at(i).contains(": uri ="))
                {
                    for(int j=0; j<printerMakeModelList.count(); j++)
                    {
                        QString strCmpMakeModel = directdevlist.at(i+3).section("=", 1,1).trimmed();
                        qDebug()<<"******************* strCmpMakeModel ******** "<<strCmpMakeModel;

                        if(printerMakeModelList.at(j) == strCmpMakeModel)
                        {
                            if(strCmpMakeModel == QString("Unknown") && directdevlist.at(i+2).section("=", 1, 1).trimmed() != QString("Unknown")) // for converter
                                continue;

                            usbdevices.append("USB"+QString::number(j+1)+": "+directdevlist.at(i+2).section("=", 1, 1).trimmed()+"\t"+directdevlist.at(i).section("=", 1, -1));
                        }
                    }
                }
            }

            qDebug() << "lcore usb devlist: " << usbdevices;
#endif
        }
        else if(strClass == QString("NETWORK"))
        {
            QStringList devicelist;
            QProcess proc;
            proc.start("lpinfo -l -v");

            if(proc.waitForFinished())
                devicelist = QString(proc.readAll()).split("\n");

            qDebug()<<"devicelist="<<devicelist.count();

            usbdevices.clear();
            networkdevices.clear();

            for(int i=0; i<devicelist.count(); i++)
            {
                if(devicelist.at(i).trimmed().contains(": uri =") && (devicelist.at(i+1).trimmed().contains("class = network") || devicelist.at(i+1).trimmed().contains("class = direct")) && (!devicelist.at(i+3).trimmed().contains("make-and-model = Unknown")) )
                {
                    qDebug()<<"devicelist to print ="<<devicelist.at(i);
                    QString strUri = devicelist.at(i).section(" = ", 1,1).trimmed();
                    QString strmakemodel = devicelist.at(i+3).section(" = ", 1,1).trimmed();
                    qDebug()<<"only uir data ="<<strUri;
                    networkdevices << strUri;
                    networkmakemodel << strmakemodel;
                }
            }
        }
    }
};


class LCore : public QObject
{
    Q_OBJECT

public:
    enum EditFileForTouchPadFlag {Change, Reverse};
    enum FileProcess{Damage, Repair, IsValid};
    struct fstats
    {
        short mode = 0;
    };

    LCore();
    threadgetdevices *thlpinfo = nullptr;
//    static QString strResponseData;
    QString strConnectionLaunchPath = "";
    bool bEnableImprivataLogs = false;

private:
    QLabel *label = nullptr;
    QMovie *movie = nullptr;
    QWidget *wid = nullptr, *widget = nullptr;
    QSharedMemory sharedMemory;
    QSqlDatabase db;
    QString strFusionmsHBeats = "";
    QLineEdit *LE_Password = nullptr;
    QDialog *passwordDialog = nullptr;

private slots:
    void detach();
    void checkForZC();
    void showClicked();
    void closeClicked();

public:
    int generateUniqueId();
    int writeLogsInDataBase(int, QMap<QString, QString>);
    QStringList getVGAcardList();
    int CheckRAMSizeAvailable();
    void sendMessageToCloseButton(QByteArray strMessage);
    int FusionmsStatus();
    int FusionmsIsRunningStatus();
    QString getMac();
    QString getCPUname();
    QString getVGAcard();
    QString getEthernetCard();
    QString getDateTime(int);
    QString getAudioInfo();
    QString getHardDiskInfo();
    QString getCDdriveInfo();
    QStringList getDriveInfo();
    QString getTotalMem();
    QString getFreeMem();
    QString getResolution();
    QStringList ShortingResolution(QStringList);
    QString getFrequency();
    QString getDriver();
    QString getColorDepth();
    QString getHostname();
    QString getGateway(const QString &);
    QString getIPAddress(const QString &);
    QString getKbdType();
    QString getKbd_rate();
    QString getDNS(int opcode);
    QString getNetmask();
    QString uptimefn(void);
    int checkLink(QString); //prash
    QString writeTable(const QString & , const QString & , const QString & , const QString & );   //prash
    QStringList readTable(const QString &tableName , const QString &primeKeyName , const QString &selectProperty="*");  //prash
    QString writeImprivataGlobalTable(const QString &strProperty, const QString &strValue);
    QString readImprivataGlobalTable(const QString &);
    QString deleteEntry(const QString & , const QString & );   //prash
    //    int CheckDataExist(QString , QString );
    void LoadImage(QWidget *);
    void StopImage();
    //    QString encrypt(QString str);
    //    QString decrypt(QString str);
    char* encrypt(char *);
    int hex_decode(char *, char *, int );
    int decrypt(char *, int );
    QString CreateTempIniFile(const QString &name, const QStringList &conn);  //prash
    QString CreateWfclientIniFile(const QString &name, const QStringList &conn);  //prash
    int isExtended();
    int is2ndDispRotated();
    int GetXDisplayNum(void);
    QString GenerateVNC(QStringList conn);
    bool copyDir(const QString& source, const QString& destination, const bool override); //prash
    QStringList getAllConnections(QString tableName, int opcode);   //prash
    int isTableExists(const QString &,  const QString &primeKeyName=QString(""));  //prash
    QString getManufracturerDetalis(QString prop);    //Aash 10-06-2013
    QString getFlashSize();   //Aash 10-06-2013
    int SetSerialPortsettings(QString port);    //prash
    QList<QStringList> readCompleteTable(const QString &tableName, const QString &primeKeyName);  //Kr 12-06/2013
    QStringList getDisplayDriverList(); //Aash 19-06-13
    QString GetDefaultPrinter();    //prash
    QStringList GetPrinterList();   //prash
    QStringList FillConnectionFailoverOption(); //prash
    void Modify_DB(const QString & , const QString & , const QString & );          //Aash 26-06-13
    QString getEthernetDevice(); //Nikhil Parte
    bool isValidIP(const string & );   //Nikhil Parte
    QStringList getResolutionList(const QString & );
    QString updateTable(const QString & , const QStringList & , const QString & )    ;   //Aash 4-7-13 (modified)
    QMap<QString, QString> getEthernetInfo();    //Rachana 4/7/13
    QString getLinkModes(QString );              //Rachana 4/7/13
    void ModifyStartMenu(QString , QString , int ); //prash
    void ModifyStartup(QString , QString, int );    //prash
    void ModifyDesktop(const QString &connectionName, const QString &cmd, int value, const QString &AppImagePath);
    void ModifyDesktop(const QString & , const QString & , int , const QString &AppImagePath=QString(""), bool bSendSignal=true); //prash
    void WriteWfclient();   //prash
    QStringList getKeyboardList(const QString & );          //Aash 08-07-2013
    QStringList ListEthernetInterfaces();
    QStringList ListWirelessInterfaces();           //Rachana 13-07-2013
    void ModifyXorgFileForScreen();                 // Aash 16-07-2013
    void ModifyXorgFileForScreenMcD(const QStringList &, int);
    QString getDisplayDevice(const QString & );       // Aash 16-07-2013
    int getScreenCount();
    void UpdateDB(int );    //prash
    QString convertSizeToHumanReadable(QString );
    void UpdateEthernetSettings(int invokeType = 0);
    static bool raiseWindow(QString );
    QValidator* SetValidation(const QString & );
    bool isValidIP(QString );    //Nikhil Parte
    QString getWirelessESSID();
    int CheckServerExist(QString, QString, QString mode="", int nRetry=0);
    void readDateTime();    //Maithili 18-07-2013
    int setDateTime(const QString &, const QString &); //Maithili 18-07-2013
    void setTimeZone();     //Maithili 18-07-2013
    void saveTimezone(QString);
    void setNTPDate();
    void ScreenSaver();     //Maithili 26-07-2013
    //void setScreenSaver(int , int , QString , int , QString , int , QString );  //Maithili 26-07-2013
    QStringList getMountedDirectories(const QString &); //Maithili 26-07-2013
    QStringList getDirectoryContent(QString);    //Maithili 26-07-2013
    void createNFSDrive();  //Maithili 26-07-2013
    QString setPermissionOfNFS(const QString &);   //Maithili 26-07-2013
    void createSMBDrive();  //Maithili 29-07-2013
    QString setPermissionOfSMB(const QString &);   //Maithili 29-07-2013
    int umountDirectory(QString);   //Maithili 31-07-2013
    bool deviceIsMounted(const QString &, const QString &); //Maithili 31-07-2013
    int getNFS_SMB_Enable_Disable_status(const QString &); //Maithili 1-10-2013
    QString getHostNameFromIP(QString); //Maithili 31-07-2013
    QString getIPFromHostName(QString);   //Maithili 1-08-2013
    int getPermission(const QString &, const QString &);    //Maithili 1-08-2013
    QStringList setKeyboardSettings();
    void LaunchPNAgentAppsOnDesktop(QString , int );    //prash
    void LaunchPNAgentAppsOnMenu(const QString & , int );   //prash
    void LaunchFreeRDPAppsOnMenu(QString , int );
    void setHostname();
    void setTaskbarproperties();        //Rachana 02-08-2013
    void writeFile(QString , QMap<QString, QString> );      //Rachana 02-08-2013
    void startCustomService();      //Aash 02-08-2013
    void WritePrintersConf();    //Kr 30-08-2013
    void WriteSMBconf(); //Kr 07-08-2013
    int checkIPConflict(const QString &, const QString &);
    void writeShortcutKeyFile(); //Kr 07-08-2013
    void changeDisplayDriver();  //Aash 8/8/2013
    void setWidgetGeometry(QWidget* , QApplication *);
    bool removeDir(const QString &);    //prash
    static void reparentWidget(QString, QWidget*, int, int);
    static QPoint adjustedMenuPosition(QWidget*, QMenu*);
    static void showBalloonMessage(QWidget*, const QString &, const QString &, QSystemTrayIcon::MessageIcon, int);
    static void hideBalloonMessage(void);
    static QString DownloadFile(const QString &, const QString &, const QString &, const QString &, const QString &username = "", const QString &password = "");
    static QString UploadFile(const QString &, const QString &, const QString &username = "", const QString &password = "", const QString &protocol = "", const QString &strDomain = "");
    static bool processFile(FileProcess process, QString fileName, int mode = 1);
    static void restoreFactorySettings(int);
    static QString generateNativeKey(const QString &, const QString &prefix = QLatin1String("qipc_sharedmemory_"));
    void ModifyXorgForArm();
    QStringList GetDriverList();    //maithili 5-08-2013
    static QString getOpenFileName(const QStringList &NameFilters); //kr 12-09-13
    static QStringList getOpenFileNames(const QStringList &NameFilters); //kr 12-09-13
    static QString getOpenDirectory(); //kr 12-09-13
    static QString getSaveFileName(const QStringList &Filters, const QString &FilePath); //kr 16-09-13
    void SendSignalToTC(const QString &strCondition, const QString &ConnectionName, const QString &ConnectionType);      //prash
    void UpdateConnectionTable(QString , QString , QString , int );   // 1 for "Active", 0 for ""   //prash
    QStringList ReadLoginDetails(); //prash
    void killpid(QString);      //prash    
    void updateSharedMemory();      //prash
    void startWPAService(const QString &);
    QString getCurrentESSIDInfo(const QString &, const QString &);
    QString getCurrentESSID(const QString &);
    void removeESSIDDetails(const QString &, const QString &, bool, bool bDeleteEntryFromDatabase = true);
    void enableAllDisabledESSID(const QString &);
    void writeESSIDInfoIntoDatabase(QMap<QString, QString>);
    void deleteESSIDFromDatabase(QString);
    QStringList write802NetworkBlock(QString, QString);
    QStringList getWPAPassphrase(QString, QString, QString);
    void writeWPAConfFile(const QString &, bool);
    void writeWiredWPAConfFile();
    void killWPASupplicantCommand(const QString &);
    void configureWifiSettings(int nCheckCounter=10, bool bConfigure=true);
    QStringList getMHzFrequencies(const QString &, const QString &, const QString &, const QString &);
    bool isDeviceExists(QString);
    void Create_wvdialConfFile(const QStringList & );   //prash
    void displayDaylightSavingTime(const QString &, const QString &, const QString &);
    QStringList getDSTCommand(const QString &, const QString &, const QString &);
    int getDSTIndex(QStringList);
    int getDSTIndexFormContinentAndRegion(const QString &, const QString &);
    int getInSec(QTime);
    QStringList getTimeDifference(QStringList, int);
    QString get_Time(QString);
    void writeFilesForRemoteShadow();
    void ChangeResolutionInDB();
    void Configure8021xSecuritySettings(QString);
    bool isDesktopMode();   //prash
    void sighupICEWM();

    void ExecuteKeyboardSettings(); //Aash 10-06-2013
    QString ExecutePowerSettings();     //Aash 13-06-13
    void ExecuteMouseSettings();  //Aash 21-06-2013
    void ExecuteNetworkSettings(QString, int invokeType = 0);   //Rachana 08-07-2013
    void ExecuteSecondDisplaySettings();    // Aash 16-07-2013
    void ExecuteDisplaySettings();          // Aash 16-07-2013
    void ExecuteJetDirectSettings(); //Kr 18-07-2013
    int ExecuteNFSCommand(const QString & , const QString & , const QString & , const QString & ); //Maithili 26-07-2013
    //QString ExecuteNFSCommand(QString , QString , QString , QString ); //Maithili 1-08-2013
    int ExecuteSMBCommand(const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString &); //Maithili 29-07-2013
    void ExecuteTouchScreenSettings(int opcode=0);  //prash
    void ExecuteNetconnectSettings();   //prash
    void ExecuteDaylightSavingTime();
    void getLpInfo(); //kr on 12-11-13 2:52
    QString GetDeviceURI(const QString &PortType, const QString &IP, const QString &username, const QString &passwd, const QString &sharename, bool chkWinDriv, const QString &domain = ""); //kr on 12-11-13 2:52
    void modifyFilesForADS();
    void writeToFile(const QString &, const QStringList &);
    QStringList readFile(const QString &, const QString &strDomain = "");
    bool removePrinter(const QString & ); //kr 0n 27-11-2013
    int checkPrinters(int); //kr 0n 29-11-2013
    void addPkgInfoInDB();
    void writeDHCPConf();
    void writeX11vncOptions();
    QStringList readPrinterPPD(const QString & ); //Kr on 24/01/2014
    bool UpdatePrinterMapOnRDP_ICA(bool , bool , QString ); //Kr on 24/01/2014
    int createPPDforPrinter(QString , QString , QString , QString , QString , QString ); //Kr on 24/01/2014
    QString getPkgVersion(const QString & ); //Kr on 04/02/2014

    void WritePowerTermPTS_File(QStringList );  //prash
    void WritePowerTermPTC_File( QStringList ); //prash
    void WritePowerTermPSL_File( QStringList ); //prash
    bool saveVMSSettingsFromFDMFile();
    void saveVMSSettingsFromDHCPParams();
    void setDefaultSettingsToVMS();
    void fillCloudDesktopAllowLicenceEntry();
    QString ExecuteFirewallSettings();          //sayali
    QString ExcuteFirewallSettingsForBoth(QString);
    void getHwData(); //Kr on 25/02/2014
    QString getOSDetails(QString); //Kr on 25/02/2014
    QStringList readHWDetailsFile(QStringList); //Kr on 25/02/2014
    void ModifyChromiumPreferencesFile(QStringList );
    void updateResolvConf(const QString & );            //prash
    int getTimeFormat(); //Maithilli 13/03/2014
    void cupsEnable(); //karthik 14/03/2014
    void Launch2XClientAppsOnDesktop(const QString &connectionName, int value);//Sayali 25/03/2014
    void Launch2XClientAppsOnMenu(const QString &, int);//Sayali 25/03/2014
    int authenticateLDAP(QStringList, int nLogin = 0);
    void writeXORGForARM();
    void createDefaultModularUSBTable(const QString &, const QString &strCheckModule = "");
    void insertValuesInDatabase(QString, QString, QString, QString, QString, QString, QString, QString, QString);
    void writePtconnsFile(QString, QString, QString, int);
    QString getMd5Sum(QByteArray);
    void DisplayErrorMessageBox(QString, QString, QString="/usr/os-bin/images/information.png");
    void createDenyAllFile();
    void WritePrinterPort_RDP(QStringList, QStringList);
    void WriteDB_RDP(QString);
    QString calculateDiskFreeSpace();
    void addDNSserver(const QString &strDevice = "Ethernet");
    void setPrimaryDevice();
    QString getMacForWifi();
    void setGateways(const QString &, const QString &);
    void writeHostnameInDHCPConf(QString);
    QString OSBuildVersion();
    char *getDevice();
    void updateGrubConf();
    bool setSSHPassword(QString);
    void createLanguageLink();
    QString downloadCertificate(QString, QString &);
    QString getCertificate(QString, QString, QString, QString);
    void ExecuteVMSSettings();
    void insertUDMValues(const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString & , const QString &, const QString &);
    void insertValues_VMView(const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, int, int, int, int, int, const QString &);
    void insertValues_PNAgent(const QString& strModuleName, const QString& strLocalUDMSettings, const QString& strServerSideRendering, const QString& strHDX_RTME, const QString& strFlashRed, const QString& strClipboard, const QString& HDXOverUDP="0", const QString& ShowFloatingBar="1", const QString& CitrixDisconnectONChildClose="0", const QString& strFullScreenMode="0", const QString& strPresetLoginInfo="Set User/Domain From Last Login", const QString& strBrowserContentRedirection="1", const QString& strMicrosoft_Teams="1", const QString& strSkype="1", const QString& strZoom="1", const QString& strWebEx="1", const QString& strCisco_VDI="1");
    void insertDefaultValues_ImprivataGlobal();
    void executeResolveIpScript();  //Ritesh
    void copyModularUSBDatabase(const QString &tableName);
    void writeUSBFile(bool);
    void copyUSBTestTable(const QString &);
    void writeVMViewUDMFile(bool);
    void writeCronFiles();
    void forLog(QString);
    QString readOemName();
    QString getIPFromServerHostName(const QString &);
    void executeVMViewGlobal();
    bool CheckforFileContents(QString);
    void WriteModuleDotIni();
    bool checkForLaptop();
    QString readOemFile(QString arg); //by namrata
    bool checkFolderExits(QString);
    void callCredentialDialog(QStringList);
    void setReconnetingInTCCenter(const QString &, const QString &, const QString &);
    void sendReconnectingSignal(const QString &, const QString &, const QString &);
    /// for SCB Client ///
    QString encryptDecryptString(QString, int);
    QString encryptDecryptStringOLD(QString SourceString, int ntype);
    int encryptString(void* buffer,int buffer_len, char* IV,char* key,int key_len);
    int decryptString(void* buffer,int buffer_len,char* IV,char* key,int key_len);
    char* convertQstringToCharArray(QString value);
    /// ================ ///
    string encrypDncryRescuePasswd(const string &SourceString, int ntype);
    char* convertQstringToCharArray(string value);
    void encryptDecryrptShowterminal(const string &, const string &);
    int ConvertToAscii(const string &strKey);
    QString getImpactNotebook();
    bool isImpactNotebook(QString strImpactNotebook);
    QString getLenovoMT();
    bool isLM600(QString strMTs);
    bool isLM625(QString strMTs);
    bool isLM700(QString strMTs);
    bool isM715qRR(QString strMTs);
    bool isM715q(QString strMTs);
    bool isL480(QString strMTs);
    int getSerialDevicesCount();
    QString getTimeZoneOffSet(QString strTimeZone);
    long int CalculateDifference(QString, QString);
    QString getCurrentOffset();
    void writeNSSwitch();
    bool findICAApplication(const QString &strappname, const QString &strip);
    QStringList readDefaultsValue(QString); // by namrata 27th april 2017
    void writeFDMDetailsFile();
    void writeDHCP81optionINDns(bool);
    bool checkrunningProcService(QString ServProc);
    QString readContentsFromFile(QString FileName);
    QMap<QString, QStringList> getClassNames();
    void insertDefaultPNA_UDMValues(bool bDummy = false);
    bool getEthernetConnectStatus();
    void on_offImprivataForVC(const QString &, const QString &);
    int smbpasswd_admin(QString);
    QString getHostNameFromDmidecode();
    bool checkForLenovoValidBoards();
    bool getWirelessInterfaceConnectedStatus();
    bool getWiredInterfaceConnectedStatus();
    bool getNetworkDeviceLinkStatus(const QString &, const QString &);
    QStringList getavailableIP();
    int WEBLauncherStatus();
    QString checkPassord(const QString &, const QString &);
    QStringList getBootSequenceList(QString);
    QString echoCommand(QString, QString);
    bool checkPasswordState(QString);
    QString getBIOSSettingPath();
    QString ChangeBIOSPassword(const QString &, const QString &, const QString &);
    //QString ChangeBootSequence(QString,QString,QString,bool);  //changed to
    QString ChangeBootSequence(const QString &, const QString &, const QString &, bool, const QString &strList="");
    QStringList getBootSequenceListExclude(QString);//Aboli
    QString RestoreDefaultConf(const QString &, const QString &);
    bool checkBoardTypeForBIOS();
    bool executeNmap(const QString &);
    bool checkNetworkIP(const QString &, const QString &);
    int getWifiSignalStrength();
    bool isEfiImage();
    QStringList findIPs();
    void getKeyCode(QString);
    void disableKeyCode(QString);
    void LaunchFreeRDPAppsOnDesktop(QString , int );
    void processApplicationLogFile(); // by Siddharth for application.log file
    int getNumberofLinesFromFile(QString, QStringList &); // by Siddharth for application.log file
    QString getActiveWindowId();
    QString getWindowClass(const QString &);
    void callWindowFocusHackForCitriWorkSpcae();
    void sendClickSignal(QString strActiveWindowId = QString(""), bool nFileWriteCheck = false);
    QString executeIPsecEnrollment(const QString &, const QString &, const QString &);
    QString getCertificateRequestEnrollmentStatus(QStringList);
    int getConnectionEdingTime(const QString &, const QString &);
    void sendMessageToTCCenter(const QString &, const QString &);
    void CheckLockScreenRunning();
    QString getTouchDeviceID(QString);
    void ExecuteTouchScreenAfterDisplaySettings();
    void updateHostnameValuesafterTarExtract(int);
    //    void ExcludeDeviceInVMVIEW(QString);
    //QString getTouchScreenVIDPID(QString);
    QStringList getTouchScreenDeviceList();
    void excludeVIDPID(const QString &, const QString &, const QString & = "");
    //void execludeTouchScreenInSessions();
    void updateVmsLogsFile(const QString &, const QString &);
    bool isWifiConfigured(const QString &strWifiDevice);
    bool checkL480Laptop();                         // Added this function to check laptop is 480 or not
    QString DownloadFile(const QString &, const QString &);
    QString getWindowId(const QString &);
    void acticateWindow(const QString &);
    QString alterTable(const QString &tableName, const QString &columnNameType, const QString &columnValue, const QString &strType = QString("ADD"), const QString &strSecTableName = QString("Jugad"));
    QString createTable(const QString &strTableName, const QString &strColumnName);
    QString insertTableValues(const QString &strTableName, const QString &strColumnNames, const QString &strTableForValues = QString("Jugad"));
    void getCert9Key4DB(int,QString="");
    void modifyThinPrintProperties();
    void writingDefaultSettingstoVMS();
    void changeNTPServerToConf(const QString &);
    void modifyAllRegionsINIFile(QString, QString, QString);
    QString getUserNameFromStandardHotname(QString);
	QString getUSBPENSerialNumber();
    int is_probably_full_disk(const char *name);
    bool checkForUSBImage();
    QString getBootDevice();
    QString getDeviceVidPid(const QString &);
    void liveImageUSBRestrict(const QString & ="");
    void ModifyAll_RegionINIFileForComPort(QString, int);
    QString getUSBSerialOrMac();
    QPair<QString , QString> getUserNameDomain(QString);
    bool writeDataInSocket(const QString &strSocketName, const QString &strSocketData );
    void fillDummyTimeZoneFile(const QStringList &strTimeZoneList = QStringList());
    QStringList readDummyTimeZoneFile(bool bWriteTable = true);    
    bool isL14W(QString strMTs);
    bool isM75n(QString strMTs);
    void readNetworkDetailsFromTableAndFillFromFile(bool);
    void readMD5SUMTableAndWriteAfterExtract(bool, bool nForSDA1 = false);
    bool readGrubFile(QString);
    void readAndAddWiFiDetails(const QString &);
    QString checkForZeroClientInOSConf();
    QString readOSConfFromLeasesFile(QString, QString);
    void writeTouchPadConfigurationFile(bool, bool, bool, bool, bool, bool, int, int);
    void setTouchPaddAccelertion();
    void touchpadConfigurationForLaptop();
    QString writeTouchPadConfigrationTable(const QString &, const QString &);
    QString getSpecialESSID(QString strESSID);
    void updateOSBuild();
    static QString getAvailableSizeInFolderOrFile(const QString &, const QString &strCondition = "");
    static QString calculateMd5sum(QString strFilePath);
    bool CheckServerExistUsingCurlCmd(QString);
    QPair<QString , QString> getLayoutFullName(QString strLayout, QString strVariant);
     int isInDST(const QString &continent, const QString &region);
    QStringList getDSTList(const QString &cont_Region, const QString &nyear);
    void applyDateTimeAfterConfigurationUpdate(const QString &);
    QMap<QString,QString> getUrlDataSeperatly(QString strUrl);
    QString getFTPS_HTTPSSHostnamefromIP(QString);
    bool ADSJoinOnLogin(QString strUserName,QString strPassword, QString strDomainName, QString strtOrganisationUnit);
    void editSmbConf(QString strProperty, QString strValue);
    void joinADS();
    QStringList getMaximumResolutionAndRefreshRate(const QString &strDisplayNumber);
    QStringList getDisplayResolutionList(QString strDisplayName);
    QList < QStringList> getResolutionAndRefreshList(const QString &strDisplayName);
    //void readAndAddWiFiDetails(QString);
    void setProperDisplayResolutionRefreshRate();
    int getsystemTrayStatus(const QString &strTablename, const QString &strModulname);
    QList<QStringList> getModuleListTaskbarContainer();
    void readAndAddHostnameDetails(const QString &);
    void readHostnameDetailsFromAndToTableFromFile(bool);

    QStringList getINIDirectoryInfo(QString strDirURLPath);
    QString getReturnCodeForCurlCmd(const QString &strUrlType, int nProcExitCode, const QStringList &strOutPutList);
    void readOrAddFirmwareDetails(const QStringList &strList);
    void backupNetworkDetailsForUpdate(bool bFillInFile);
    QStringList getMountedDivicePortBusNo(const QString &strSerial);
    void backupDomainDetailseAndjoinADS(const QString &strCondition);
    void backupDomain(const QString &strCondition);

    QStringList getMultiMonitorResolutionList(QString); //bhavika
    void ExecuteMultiMonitorSettings(void); //bhavika
    QStringList getPosition(const QString &, const QString &, const QString &); //bhavika
    void setMonitorPosition(const QString &, int, int); //bhavika
    void setMultiMonitor(QStringList); //bhavika
    void ModifyXorigMultiDisplay();
    QMap<QString,QString> mapMonitorPosition(void);//bhavika
    QStringList getCardCount(void); //bhavika
    QStringList getDriverName(void); //bhavika
    QMap<QString,QString> getCardDriverMap(void); //bhavika
    QString getLSUSBOutput(QString strFirstKeyWord, QString strSecondKeyWord = "");
    void checkAndCallForDisplayLink();
    QMap<QString, QStringList> getMonitorList();
    QString getDefaultRefreshrate(const QString &, const QString &);
    void installSignal(int) ;
    void startDeamonsForVC(void);
    void ModifyXorgFileForScreenOLD();
    void driverConfirmation();
    QStringList readAndWriteFile(const QString &strFileName, const QString &strRWCondition, const QStringList &strWriteList = QStringList(), const QString &strReadCondition = "", const QString &strWriteCondition = "" );
    JsonObject restServerRequest(QString strRequestType, QString strURL, QString strId, QString strLicenseKey = "", QString strDeviceType = "");
    JsonObject dummyRestServerRequest(QString strRequestType, QString strURL, QString strId, QString strLicenseKey, QString strDeviceType);
    static size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up);
    void createEnterPasswordUI(QWidget* w, QApplication *a);
    void invokeTerminalFromLineEdit(QWidget* w, QString password);
    QString getRandomString(QString, int, bool);
    QString base64BitEncodeAndDecode(const QString &strCondition, const QString &strString);

    void writeGenericSettingsFiles(const QString & , const QString &  );
    QString readBuildFiles(QString);
    QString getHostnameForImpact();
    void cleanUpLogs(QMap<QString, QString>);
    QString formatSize(qint64 num);
    QString QProcessOutput(QString cmd);
    bool IsImpactClient();
    QString readLivepenKeyFileData(QString strData);
     void writeAppliDisConfigFile(QMap<QString, QString>, const QString &);
     void DisconnectAllConnectionFromImprivata(bool bForceLogout = true);
    QStringList getValues(const QString &strSearch, const QList<QStringList> &listCompleleteValues);
    QPair<QString, QString> getHighestResolution(int );
    void editFileForTouchpad(EditFileForTouchPadFlag);
    QString checkClientisCloudDesktop();
    bool isImprivataLogout(bool bLogout = true );
    void DisableIWConfigPowerManagenentOption(const QString &strWifiDeviceName);
    void chownFilesAndDir(const QString &);
    QString getHomeUserPath();
    void writeLogsOnDefaultValue(const QString &strStatement , const QString &strOP);
};

#endif // LCORE_H
 
