#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QVector>

#include "calculate.h"
#include "info.h"
#include "infotool.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double R,r_m,K,C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11,C12,A1,A2,A3;
    double angle,Lt,Dm,r_,Lb,Xbasic,Zbasic,Hcenter,Ybasic,step,clear_single;
    double x_begin,z_begin,angle_begin;//进刀点
    double clear_Total;
    QString type,face,radius,p_Name;
    QString warn;
    QVector<QString> st;//存字符串
    QVector<double> machine,cal_info;
    QVector<QString> test1;
    int t;
    void test();
    void test11(QVector<double> a,QVector<QString> b);
    void setString(QString str,QString str1);
    QVector<QPointF> readExcel(QString s);


private:
    Ui::MainWindow *ui;

    bool tellData();
    void calClear();

signals:
    void sendString(QVector<QString> m);
    void showInfo();
    void showInfoT();
    void showCalTest(QVector<double> d,QVector<double> m);


private slots:
     void receiveData(QVector <double> d,QVector<QString> m);
     void receiveMachine(QVector<double> m);
     void receiveString(QVector<QString> m);
     void on_actioninfoMacine_triggered();
     void on_actioninfoTool_triggered();
     void on_actioncalculate_triggered();
     void receiveClear(double a);
     void receiveStr(QVector<QString> s);
     void on_pb_caculate_clicked();




     void on_open_clicked();
     void on_open1_clicked();
     void on_pb_compensation_clicked();
};

#endif // MAINWINDOW_H
