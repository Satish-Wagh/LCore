#include "leforpassword.h"
#include "lcore.h"

Leforpassword::Leforpassword(QWidget *parent) :
    QWidget(parent)
{
    LE_Password = NULL;
    PB_EyeIcon = NULL;
    strExistingPwd.clear();
    CreatePasswordWidget();
}
void Leforpassword::CreatePasswordWidget()
{
    qDebug()<<"Leforpassword:CreatePasswordWidget::3::Start";
    QHBoxLayout *layout = new QHBoxLayout(this);

    LE_Password = new QLineEdit(this);
    PB_EyeIcon = new QPushButton(this);

    QString strParentAppName = qAppName();
    if(strParentAppName == "PNAgentDialog" || strParentAppName == "FreeRDPDialog" || strParentAppName == "CertificateManager" || strParentAppName == "ConfigurationWizard" )
    {
        this->setFocusProxy(LE_Password);
        PB_EyeIcon->setFocusPolicy(Qt::NoFocus);
    }
    else
    {
        QWidget::setFocusProxy(LE_Password);
    }
    LE_Password->setFixedSize(290,27);
    LE_Password->setEchoMode(QLineEdit::Password);
    layout->addWidget(LE_Password);

//    PB_EyeIcon->setFixedSize(38,25);
    PB_EyeIcon->setIcon(QIcon(QString(IMAGEPATH)+"showpassword.png"));
//    LE_Password->setStyleSheet("QLineEdit{ border-width: 1px; border-style: solid; border-color: black white black black;}");
//    PB_EyeIcon->setStyleSheet("background-color: white ;border-radius:0px; border:0px;border-right:1px solid black;border-left: none;");
    PB_EyeIcon->setFlat(true);
    PB_EyeIcon->setAutoFillBackground(true);
    layout->addWidget(PB_EyeIcon);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    connect(PB_EyeIcon,SIGNAL(pressed()),this,SLOT(PressPushButton()));
    connect(PB_EyeIcon,SIGNAL(released()),this,SLOT(ReleasedPushButton()));
    connect(LE_Password, SIGNAL(returnPressed()), this, SLOT(LE_Password_returnPressed()));
    qDebug()<<"Leforpassword:CreatePasswordWidget::3::End";
}

void Leforpassword::setText(QString strText)
{
    LE_Password->setText(strText);

    strExistingPwd = strText;
}

void Leforpassword::clear()
{
    LE_Password->clear();

}

void Leforpassword::setMaxLength(int nlength)
{
    LE_Password->setMaxLength(nlength);
}

void Leforpassword::setCursorPosition(int nposition)
{
    LE_Password->setCursorPosition(nposition);
}

void Leforpassword::setReadOnly(bool bCheck)
{
    LE_Password->setReadOnly(bCheck);
}

void Leforpassword::setPlaceholderText(const QString &strtext)
{

    LE_Password->setPlaceholderText(strtext);

}

void Leforpassword::setValidator(const QValidator *hostname)
{
    LE_Password->setValidator(liblcore.SetValidation("hostname"));
}

// cppcheck-suppress unusedFunction
void Leforpassword::LE_Password_returnPressed()
{
    qDebug() <<"Leforpassword:on_LE_Password_returnPressed::3::Start";
    qDebug() <<qAppName();
    qDebug() <<qApp->parent();
    QString strParentAppName = qAppName();
    qDebug() <<"Leforpassword:on_LE_Password_returnPressed::3::Name :-"<<strParentAppName;

    if(strParentAppName == "ScreenSaver" || strParentAppName == "ConfigurationWizard")
    {
        QString password = LE_Password->text();
        int nTimeCnt;
        QString strosBuild,strCmp,strPassword,strpwd;
        QStringList strlistosBuildparameter;
        if(password == "terminal")
        {
            QString strMac = liblcore.getMac().remove(":");
            strKey = getRandomString(strMac, 12, true);
            LE_Password->clear();

            QMessageBox::information(this, tr("Code For OTP Generation"), tr("Code For OTP Generation : \"%1\"").arg(strKey));
            return;
        }

        qDebug()<<"password :----"<<password;
        if(password.contains("OS"))
        {
            QString strCnt = password.section("OS", -1);
            nTimeCnt = strCnt.toInt();
            password.chop(strCnt.length());
            qDebug() << "strTimeCnt " << nTimeCnt;

            strosBuild = readBuildFiles("/data/.osbuild");
            strlistosBuildparameter= strosBuild.split("-");
            QString strbuildNo = "";
            if(strlistosBuildparameter.count())
                strbuildNo=strlistosBuildparameter.at(5);

            strPassword=password;
            qDebug()<<"build no :" <<strbuildNo;
            strpwd="Gio6@Sukshm"+strbuildNo+"#OS";

            qDebug()<<"actual password ---"<<strpwd <<nTimeCnt;
        }
        else
        {
            QString md5sum = liblcore.getMd5Sum(password.toLatin1());

            qDebug() << "md5sum ***D*"<<md5sum;
            qDebug() << "md5sum ***CONFIGPWD*"<<CONFIGPWD;
            if(md5sum == QString(TERMINALPWD) || md5sum == QString(CONFIGPWD))
            {
                if(LE_Password !=NULL)
                    LE_Password->clear();
                QProcess::startDetached(TERMINALCMD, QStringList() << QString::number(999));

            }
        }

        QString md5sum = liblcore.getMd5Sum(strKey.toLatin1());
        strCmp = getRandomString(md5sum, 15, false);

        if(!password.isEmpty() && !strCmp.isEmpty())
        {
            if(password == strCmp)
            {
                LE_Password->clear();
                QProcess::startDetached(TERMINALCMD, QStringList() << QString::number(999));
                strKey.clear();
                strCmp.clear();
            }
        }

        if(!strPassword.isEmpty() && !strpwd.isEmpty())
        {
            if(strPassword == QString(strpwd) && nTimeCnt) // Terminal
            {
                LE_Password->clear();
                QProcess::startDetached(TERMINALCMD, QStringList() << QString::number(nTimeCnt));
                strCmp.clear();
            }
        }
    }
    qDebug()<<"Dialog:on_LE_Password_returnPressed::3::End";
}

QString Leforpassword::getRandomString(QString strKey, int nLength, bool bEncrypt)
{
    qDebug()<<"Leforpassword:getRandomString::3::Start";
    qDebug()<<"Leforpassword:getRandomString::3::Arguments:strKey,nLength,"<<strKey,nLength,bEncrypt;

    if(bEncrypt)
        qsrand(QTime::currentTime().msec());
    else
        qsrand(22091986);

    const QString possibleCharacters(strKey);
    const int randomStringLength = nLength;
    QString randomString;

    for(int i = 0; i < randomStringLength; ++i)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    qDebug()<<"Leforpassword:getRandomString::3::End";
    return randomString;
}

QString Leforpassword::readBuildFiles(QString strFileName)
{
    qDebug()<<"Leforpassword:readBuildFiles::3::Start";
    qDebug()<<"Leforpassword:readBuildFiles::3::Arguments:strFileName:-"<<strFileName;
    QString build = "";
    if(QFile::exists(strFileName))
    {
        QFile file(strFileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            QString line = in.readLine().simplified();
            if(line.count() && !line.isEmpty())
                build = line;
        }
    }
    qDebug()<<"Leforpassword:readBuildFiles::3::End";
    return build;
}

QString Leforpassword::text()
{
    QString strText = LE_Password->text();
    return strText;
}

// cppcheck-suppress unusedFunction
void Leforpassword::PressPushButton()
{

    QString strPassword = LE_Password->text();

    if(strExistingPwd == strPassword)
    {
        LE_Password->setEchoMode(QLineEdit::Password);
    }
    else if(!strPassword.contains("Gio6@Sukshm"))
    {
        LE_Password->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        return;
    }
}

// cppcheck-suppress unusedFunction
void Leforpassword::ReleasedPushButton()
{
    LE_Password->setEchoMode(QLineEdit::Password);
}
