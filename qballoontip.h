#ifndef QBALLOONTIP_H
#define QBALLOONTIP_H

#include <QtGui/QWidget>
#include <QtGui/QSystemTrayIcon>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QStyle>
#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QPainter>
#include <QtGui/QBitmap>
#include <QtGui/QMouseEvent>

#include <QDebug>

class QBalloonTip : public QWidget
{
    Q_OBJECT
public:
    static void showBalloon(QSystemTrayIcon::MessageIcon icon, const QString& title, const QString& message, QWidget *trayIcon, const QPoint& pos, int timeout, bool showArrow = true);
    static void hideBalloon();
    static bool isBalloonVisible();

private:
    QBalloonTip(QSystemTrayIcon::MessageIcon icon, const QString& title, const QString& message, QWidget *ti);
    ~QBalloonTip();
    void balloon(const QPoint&, int, bool);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *e);
    void timerEvent(QTimerEvent *e);

private:
    QWidget *trayIcon = nullptr;
    QPixmap pixmap;
    int timerId = 0;
};


#endif // QBALLOONTIP_H
