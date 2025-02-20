#ifndef Localcredentialdialog_H
#define Localcredentialdialog_H

#include <QDialog>
#include <QFuture>
#include <QFutureWatcher>
#include <QtConcurrentRun>

#include "lcore.h"
#include "defineslcore.h"

namespace Ui {
class Localcredentialdialog;
}

class Localcredentialdialog : public QDialog
{
    Q_OBJECT

public:
    explicit Localcredentialdialog(QWidget *parent = 0, const QString& str="", const QString& conn_type="", const QStringList& strlistcred=QStringList(""));
    ~Localcredentialdialog();

    void SetValidations();
    void getTrustedDomainList(const QString &);

public:
    QString arg_no = "";
    QString strconnection = "";
    QString strConnectionType = "";
    QStringList strlistConnDetails = QStringList();
    bool bVNCCancle = false, bpnacancle = false;

    static QStringList callCitrixwindow(const QString &ConnectionType, const QStringList &);
    void ReadConnectionUserDomain(QString );

protected:
    void showEvent(QShowEvent*);
    void keyPressEvent(QKeyEvent *);

signals:
    void domainList(QString);

private slots:
    void on_PB_CitxOk_clicked();
    void on_PB_CitxCancle_clicked();
    void updateDomains(QString);
    void on_CB_CitxDomain_currentIndexChanged(const QString &arg1);
    void on_LE_CitxUsername_textEdited(const QString &arg1);
    void on_PB_KbdLayout_clicked();

private:
    Ui::Localcredentialdialog *ui = nullptr;
    QString name = "";
    QStringList strcredentialList = QStringList();
};

#endif // Localcredentialdialog_H
