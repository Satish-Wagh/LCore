#include "Localcredentialdialog.h"
#include "ui_Localcredentialdialog.h"


Localcredentialdialog::Localcredentialdialog(QWidget *parent, const QString &str, const QString &conn_type, const QStringList &strlistcred) :
    QDialog(parent),
    ui(new Ui::Localcredentialdialog)
{
    ui->setupUi(this);
    LCore liblcore;
    setWindowFlags(((windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowCloseButtonHint));

    QString procType = " Process VARCHAR(30) PRIMARY KEY , PID VARCHAR(30) , WID VARCHAR(30) , Extra1 INTEGER, Extra2 INTEGER, Extra3 INTEGER, Extra4 VARCHAR(30), Extra5 VARCHAR(30) ";
    QString procValues = " '"+ QString("LocalCitrixLocalcredentialdialog") +"' , '"+ QString::number(getpid()) +"', '"+ QString::number(winId()) +"' , 0, 0, 0, '"+ +"', '"+ +"' ";
    liblcore.writeTable( "ProcessInfo", procType , procValues , "AppendNew");
    strlistConnDetails = strlistcred;
    arg_no = str;
    strConnectionType = conn_type;
    SetValidations();

    ui->PB_CitxCancle->setIcon(QIcon(QString(ICON_PATH)+"close.png"));
    ui->PB_CitxOk->setIcon(QIcon(QString(ICON_PATH)+"apply.png"));
    if(strConnectionType == "PNAgent")
    {
        ui->LB_Logo->show();
    }
    else
    {
        ui->LB_Logo->hide();
    }

    ui->PB_CitxOk->setDefault(true);
    ui->LE_CitxServer->show();
    ui->LE_CitxDomain->show();
    ui->LB_CitxDomain->show();
    ui->LB_CitxServer->show();
    ui->CB_CitxDomain->hide();
    //ui->LE_CitxDomain->setFixedWidth(170);

    QStringList strDefaultValSorbonneUni = liblcore.readDefaultsValue("ShowKeyboardLayoutOnCitrix");
    QStringList strDefaultVal = liblcore.readDefaultsValue("CitrixLWTitle");
    if(strDefaultVal.count())
    {
        this->setWindowTitle(tr(strDefaultVal.at(0).toLatin1()));
    }
    else
        this->setWindowTitle(tr("Citrix Receiver"));

    if(strlistcred.count())
    {
        strDefaultVal.clear();
        strDefaultVal = liblcore.readDefaultsValue("CitrixLWServer");
        if(strlistcred[0].contains("None"))
        {
            ui->LE_CitxServer->setDisabled(false);
        }
        else
        {
            ui->LE_CitxServer->setText(strlistcred[0]);
            ui->LE_CitxServer->setDisabled(true);
            if(strConnectionType == "PNAgent" && (strDefaultVal.count() && !strDefaultVal.at(0).toInt()))
            {
                ui->LB_CitxServer->hide();
                ui->LE_CitxServer->hide();
            }
        }

        strDefaultVal.clear();
        strDefaultVal = liblcore.readDefaultsValue("CitrixLWUsername");
        if(strlistcred[1].contains("None"))
        {
            ui->LE_CitxUsername->setDisabled(false);
            ui->LE_CitxUsername->show();
        }
        else
        {
            ui->LE_CitxUsername->setText(strlistcred[1]);
            ui->LE_CitxUsername->setDisabled(true);
            if(strConnectionType == "PNAgent" && (strDefaultVal.count() && !strDefaultVal.at(0).toInt()))
            {
                ui->LB_CitxUsername->hide();
                ui->LE_CitxUsername->hide();
            }
        }

        strDefaultVal.clear();
        strDefaultVal = liblcore.readDefaultsValue("CitrixLWPassword");
        if(strlistcred[2].contains("None"))
        {
            ui->LE_CitxPassword->setDisabled(false);
        }
        else
        {
            ui->LE_CitxPassword->setText(strlistcred[2]);
            ui->LE_CitxPassword->setDisabled(true);
            if(strConnectionType == "PNAgent" && (strDefaultVal.count() && !strDefaultVal.at(0).toInt()))
            {
                ui->LB_CitxPassword->hide();
                ui->LE_CitxPassword->hide();
            }
        }

        strDefaultVal.clear();
        strDefaultVal = liblcore.readDefaultsValue("CitrixLWDomain");
        if(strlistcred[3].contains("None"))
        {
            ui->LE_CitxDomain->setDisabled(false);
            if(strlistcred.count() > 4 && strConnectionType == "PNAgent")
            {
                QString strServerWithScheme,strProtocol;
                if(!strlistcred[4].isEmpty())
                {
                    strProtocol= strlistcred[4].toLower().simplified();
                }
                QString strServer = strlistcred[0].simplified();
                QUrl serverurl(strServer);
                if(serverurl.scheme().length())
                    strServerWithScheme = strProtocol+":"+serverurl.toString(QUrl::RemoveScheme);
                else
                    strServerWithScheme = strProtocol+"://"+strServer;

                connect(this, SIGNAL(domainList(QString)), this, SLOT(updateDomains(QString)));


                QFutureWatcher<void> futureWatcher;
                QFuture<void> future = QtConcurrent::run(this, &Localcredentialdialog::getTrustedDomainList, strServerWithScheme);
                futureWatcher.setFuture(future);
                while(futureWatcher.isRunning())
                    qApp->processEvents();
            }
        }
        else
        {
            ui->LE_CitxDomain->setText(strlistcred[3]);
            ui->CB_CitxDomain->addItem(strlistcred[3]);
            ui->LE_CitxDomain->setDisabled(true);
            if(strConnectionType == "PNAgent" && (strDefaultVal.count() && !strDefaultVal.at(0).toInt()))
            {
                ui->LE_CitxDomain->hide();
                ui->CB_CitxDomain->hide();
                ui->WID_Domain->hide();
                ui->LB_CitxDomain->hide();
            }
        }
    }

    if(QFile::exists(ENCRYPT255))
        ui->LE_CitxPassword->setMaxLength(255);
    else
        ui->LE_CitxPassword->setMaxLength(50);

    ui->PB_KbdLayout->setIconSize(QSize(23,23));
    ui->PB_KbdLayout->setIcon(QIcon(QString(ICON_PATH)+"keyboard.png"));
    ui->PB_KbdLayout->setToolTip("Keyboard Layout");
    if(strDefaultValSorbonneUni.count() && strDefaultValSorbonneUni.at(0).toInt() && strlistcred.count() > 4)
    {
        ui->PB_KbdLayout->show();
    }
    else
    {
        ui->PB_KbdLayout->hide();
    }

    strDefaultValSorbonneUni.clear();
    strDefaultValSorbonneUni = liblcore.readDefaultsValue("CitrixHideCancelButton");
    if(strDefaultValSorbonneUni.count() && strDefaultValSorbonneUni.at(0).toInt())
    {
        ui->PB_CitxCancle->hide();
    }

    strDefaultValSorbonneUni.clear();
    strDefaultVal.clear();
    strDefaultValSorbonneUni = liblcore.readDefaultsValue("CitrixLogo");
    strDefaultVal = liblcore.readDefaultsValue("CitrixLWLogo");
    if((strDefaultVal.count() && strDefaultVal.at(0).toInt()) || !strDefaultVal.count())
    {
        if(strDefaultValSorbonneUni.count() && strDefaultValSorbonneUni.at(0).toInt() && QFile::exists("/root/Sorbonne_Logo.png"))
        {
            ui->LB_Logo->setPixmap(QPixmap(QString("/root/") +"Sorbonne_Logo.png").scaled(QSize(140, 50)));
        }
        else
        {
            if(strDefaultValSorbonneUni.count() && !strDefaultValSorbonneUni.at(0).toInt())
            {
                ui->gridLayout_3->addItem(ui->horizontalSpacer_2, 0, 1);
                ui->gridLayout_3->addWidget(ui->LB_Logo, 0, 0);
            }
            ui->LB_Logo->setPixmap(QPixmap(QString(ICON_PATH) +"Citrix_Logo.png"));
        }
    }
    else
    {
        ui->LB_Logo->hide();
    }

    strDefaultValSorbonneUni.clear();
    strDefaultVal.clear();
    strDefaultValSorbonneUni = liblcore.readDefaultsValue("CitrixIcon");
    strDefaultVal = liblcore.readDefaultsValue("CitrixLWIcon");
    if((strDefaultVal.count() && strDefaultVal.at(0).toInt()) || !strDefaultVal.count())
    {
        if(strDefaultValSorbonneUni.count() && strDefaultValSorbonneUni.at(0).toInt() &&  QFile::exists("/root/Sorbonne_Icon.png"))
        {
           setWindowIcon(QIcon("/root/Sorbonne_Icon.png"));
        }
        else
           setWindowIcon(QIcon("/opt/Citrix/ICAClient/icons/receiver.png"));
    }

    QStringList strUsernameType;
    strUsernameType << QString("$hostname") << QString("$assettag") << QString("$serialnumber") ;
    if(strUsernameType.contains(ui->LE_CitxUsername->text(), Qt::CaseInsensitive))
    {
        ui->LE_CitxUsername->setEnabled(true);
    }

    QStringList ShowPresetLogin = liblcore.readDefaultsValue("ShowPresetLogin");
    if((ShowPresetLogin.count() && ShowPresetLogin.at(0).toInt()))
    {
        QStringList strListglobalValuesVM = liblcore.readTable("PNAgentGlobal", "");
        if(strListglobalValuesVM.count() && strListglobalValuesVM.at(9).trimmed().length())
        {
            ReadConnectionUserDomain(strListglobalValuesVM.at(9).trimmed());
        }
    }
    ui->PB_CitxCancle->setIcon(QIcon(QString("/usr/os-bin/images/")+"close.png"));
    ui->PB_CitxOk->setIcon(QIcon(QString("/usr/os-bin/images/")+"apply.png"));

    adjustSize();
    setFixedSize(size());
    liblcore.setWidgetGeometry(this, qApp);
}

void Localcredentialdialog::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    if(ui->CB_CitxDomain->isVisible())
    {

        ui->CB_CitxDomain->setGeometry(0, 0, ui->WID_Domain->width(), ui->WID_Domain->height()-1);
    }

    if(ui->LE_CitxDomain->isVisible())
    {
        if(ui->CB_CitxDomain->isVisible())
        {
            ui->LE_CitxDomain->setGeometry(0, 0, ui->WID_Domain->width()-20, ui->WID_Domain->height()-1);
        }
        else
        {
            ui->LE_CitxDomain->setGeometry(0, 0, ui->WID_Domain->width(), ui->WID_Domain->height()-1);
        }
    }
}

Localcredentialdialog::~Localcredentialdialog()
{
    delete ui;
}

void Localcredentialdialog::SetValidations()
{

}

void Localcredentialdialog::getTrustedDomainList(const QString& url)
{
    qDebug()<<"getTrustedDomainList ";
    QProcess proc;
    QStringList args;
    args<<"-G"<<url;
    qDebug()<<QString(TRUSTTEDDOMAIN)<<args;
    proc.start(QString(TRUSTTEDDOMAIN),args);
    proc.waitForFinished(-1);
    qDebug()<<"error="<<proc.readAllStandardError();
    qDebug()<<"output="<<proc.readAllStandardOutput();
    proc.close();
    QFile readFile("/tmp/.domainlist");
    if(readFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream in(&readFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            qDebug()<<"line="<<line;
            emit domainList(line);
        }
    }
    readFile.close();
}

// cppcheck-suppress unusedFunction
QStringList Localcredentialdialog::callCitrixwindow(const QString& ConnectionType, const QStringList& credential)
{
    Localcredentialdialog *cred = new Localcredentialdialog(0,"0",ConnectionType,credential);
    if(cred->exec() == QDialog::Accepted)
    {
        return QStringList()<<"sundyne";
    }

    if(cred->strcredentialList.count())
    {
        return cred->strcredentialList;
    }
    else
    {
        return QStringList()<<"";
    }
}

// cppcheck-suppress unusedFunction
void Localcredentialdialog::on_PB_CitxOk_clicked()
{
    LCore liblcore;
    QString strerrormsg ,strDomain;
    if(!ui->LE_CitxUsername->text().length())
        strerrormsg += tr("Username,");
    if(!ui->LE_CitxPassword->text().length())
        strerrormsg += tr("Password,");
    if((ui->LE_CitxDomain->text().length() && (!ui->LE_CitxUsername->text().contains("@") && !ui->LE_CitxUsername->text().contains("\\"))) || !ui->LE_CitxDomain->text().length())
    {
        strerrormsg += tr("Domain,");
    }

    strerrormsg.chop(1);

    if(ui->LE_CitxServer->text().simplified().isEmpty())
    {
        QMessageBox::warning(this, tr("Credential Information"), tr("Please enter server IP."));
        return;
    }
    if(!ui->LE_CitxUsername->text().length() || !ui->LE_CitxPassword->text().length() || ((!ui->LE_CitxDomain->text().length()) && !ui->LE_CitxUsername->text().contains("@") && !ui->LE_CitxUsername->text().contains("\\")))
    {
        QMessageBox::information(this, tr("Credential Information"), (tr("Please enter ")+strerrormsg), QMessageBox::Ok);
        return;
    }
    QPair<QString,QString> pairUserNmDomain;

    if(!ui->LE_CitxUsername->text().isEmpty())
    {

        pairUserNmDomain = liblcore.getUserNameDomain(ui->LE_CitxUsername->text().trimmed());
    }
    if(pairUserNmDomain.first.trimmed().isEmpty())
    {
        QMessageBox::warning(this, tr("Credential Error"), tr("Failed To retrive username."));
        return;
    }
    strDomain= (!pairUserNmDomain.second.isEmpty())?pairUserNmDomain.second.trimmed():ui->LE_CitxDomain->text().trimmed();
    strcredentialList<<ui->LE_CitxServer->text()<<pairUserNmDomain.first.trimmed()<<ui->LE_CitxPassword->text()<< strDomain;
    close();
}


void Localcredentialdialog::on_PB_CitxCancle_clicked()
{
    if(QFile::exists("/tmp/.kioskreconnect"))
        QFile::remove("/tmp/.kioskreconnect");

    if(QFile::exists("/tmp/.reconnect"))
        QFile::remove("/tmp/.reconnect");

    // reject();
    close();
}

// cppcheck-suppress unusedFunction
void Localcredentialdialog::updateDomains(QString domain)
{
    ui->WID_Domain->show();
    ui->CB_CitxDomain->show();
    //ui->LE_CitxDomain->setFixedWidth(152);
    ui->CB_CitxDomain->addItem(domain);
    ui->LE_CitxDomain->setText(ui->CB_CitxDomain->currentText());
}

// cppcheck-suppress unusedFunction
void Localcredentialdialog::on_CB_CitxDomain_currentIndexChanged(const QString &)
{
    ui->LE_CitxDomain->setText(ui->CB_CitxDomain->currentText());
}

// cppcheck-suppress unusedFunction
void Localcredentialdialog::on_LE_CitxUsername_textEdited(const QString &arg1)
{
    QString tmp = arg1.toAscii();
    if(tmp.contains("\\") || tmp.contains("@"))
    {
        ui->LE_CitxDomain->setDisabled(true);
        ui->CB_CitxDomain->setDisabled(true);
        ui->LE_CitxDomain->clear();
    }
    else
    {
        ui->LE_CitxDomain->setEnabled(true);
        ui->CB_CitxDomain->setEnabled(true);
        if(ui->CB_CitxDomain->count() && ui->LE_CitxDomain->text().trimmed().isEmpty())
        {
            ui->LE_CitxDomain->setText(ui->CB_CitxDomain->currentText());
            ui->LE_CitxDomain->setDisabled(true);
        }
        else if(strlistConnDetails.count() && strlistConnDetails.at(3).length() && strlistConnDetails.at(3) != QString("None"))
        {
            ui->LE_CitxDomain->setEnabled(false);
            ui->CB_CitxDomain->setEnabled(false);
            if(ui->LE_CitxDomain->text().trimmed().isEmpty())
                ui->LE_CitxDomain->setText(strlistConnDetails.at(2));
        }
    }
}

void Localcredentialdialog::ReadConnectionUserDomain(QString strPresetLoginInfo)
{
    qDebug()<<"Localcredentialdialog:ReadConnectionUserDomain::3:: Starts";
    LCore liblcore;
    QString strLastUsernameDomain;
    QStringList strConnUsernamelist, strConnDomainlist;
    if(strPresetLoginInfo.length() && strPresetLoginInfo.trimmed() == "Set User/Domain From Last Login")
    {

        if(ui->LE_CitxUsername->text().isEmpty())
        {
            strConnUsernamelist = liblcore.readTable("SysConf", "Property='"+strConnectionType+"LastUser'", "Value");
        }

        if(ui->LE_CitxDomain->text().isEmpty())
        {
            strConnDomainlist = liblcore.readTable("SysConf", "Property='"+strConnectionType+"LastDomain'", "Value");
        }
    }
    if(strPresetLoginInfo.length() && strPresetLoginInfo.trimmed() == "Set User/Domain From ADS")
    {
        if(ui->LE_CitxUsername->text().isEmpty())
        {
            strConnUsernamelist = liblcore.readTable("SysConf", "Property='ADSUsername'", "Value");
        }

        if(ui->LE_CitxDomain->text().isEmpty())
        {
            strConnDomainlist = liblcore.readTable("SysConf", "Property='Domain'", "Value");
        }
    }

    if(!strConnUsernamelist.isEmpty())
    {
        strLastUsernameDomain = strConnUsernamelist.at(0);
        ui->LE_CitxUsername->setText(strLastUsernameDomain);
    }

    if(!strConnDomainlist.isEmpty())
    {
        strLastUsernameDomain.clear();
        strLastUsernameDomain = strConnDomainlist.at(0);
        ui->LE_CitxDomain->setText(strLastUsernameDomain);
    }

    qDebug()<<"Localcredentialdialog:ReadConnectionUserDomain::3:: Ends";

}

void Localcredentialdialog::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape)
    {
        on_PB_CitxCancle_clicked();
    }
    QDialog::keyPressEvent(e);
}

// cppcheck-suppress unusedFunction
void Localcredentialdialog::on_PB_KbdLayout_clicked()
{
    qDebug()<<"Localcredentialdialog:on_PB_KbdLayout_clicked::1:: Starts";
    QProcess::startDetached("KeyboardMouse 1");
    qDebug()<<"Localcredentialdialog:on_PB_KbdLayout_clicked::1:: Ends";
}

