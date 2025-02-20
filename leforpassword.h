#ifndef LEFORPASSWORD_H
#define LEFORPASSWORD_H

#include <QWidget>
#include "lcore.h"
#include "defineslcore.h"

class Leforpassword : public QWidget
{
    Q_OBJECT
public:
    explicit Leforpassword(QWidget *parent = 0);
    void CreatePasswordWidget();
    void setText(QString);
    void clear();
    void setMaxLength(int nlength);
    void setCursorPosition(int nposition);
    void setReadOnly(bool bCheck);
    void setPlaceholderText(const QString &strtext);
    void setValidator(const QValidator *hostname );
    QString readBuildFiles(QString strFileName);
    QString getRandomString(QString strKey, int nLength, bool bEncrypt);    
    QString text();
    QString strKey = "";
    QLineEdit *LE_Password = nullptr;
    QPushButton *PB_EyeIcon = nullptr;
    LCore liblcore;
    QString strExistingPwd = "";

signals:

public slots:
    void PressPushButton();
    void ReleasedPushButton();
    void LE_Password_returnPressed();
};

#endif // LEFORPASSWORD_H
