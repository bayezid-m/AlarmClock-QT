#ifndef MYAPP_H
#define MYAPP_H
#include <QtCore>
#include <QDebug>

class myapp : public QObject
{
    Q_OBJECT
public:
    myapp();
    QTimer *timer;
    QTimer *timer2;
signals:
    void sendMess(const QString &txt_box_str);
    void sendMess2(const QString &txt_box_str2);
    void sendMess3(const QString &txt_box_str3);
    void sendMess4(const QString &txt_box_str4);
    void sendMess5(const QString &txt_box_str5);
    void sendMess6(const QString &txt_box_str6);
    void sendMess7(const QString &txt_box_str7);
    void sendMess8(const QString &txt_box_str8);
public slots:
    void MySlot();
    void func_btn_set();
    void func_btn_unset();
    void func_btn_al();
    void func_btn_up();
    void func_btn_dwn();
    void func_btn_stop();
};


#endif // MYAPP_H
