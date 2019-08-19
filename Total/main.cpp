#include "mainwindow.h"
#include "info.h"
#include "infotool.h"
#include "calculate.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    info inf;
    infoTool inft;
    calculate cal;


    QObject::connect(&inft,SIGNAL(sendData_(QVector<double>)),&w,SLOT(receiveMachine(QVector<double>)));
    QObject::connect(&w,SIGNAL(showInfo()),&inf,SLOT(displayInfo()),Qt::UniqueConnection);
    QObject::connect(&w,SIGNAL(showInfoT()),&inft,SLOT(displayInfoTool()),Qt::UniqueConnection);
    QObject::connect(&w,SIGNAL(showCalTest(QVector<double>,QVector<double>,QVector<QString >)),&cal,SLOT(displatAndPro(QVector<double>,QVector<double>,QVector<QString>)),Qt::UniqueConnection);
    QObject::connect(&inf,SIGNAL(sendData(QVector<double>,QVector<QString>)),&w,SLOT(receiveData(QVector<double>,QVector<QString>)));
    QObject::connect(&inf,SIGNAL(sendStr(QVector<QString>)),&w,SLOT(receiveString(QVector<QString>)));

    w.show();
    return a.exec();
}
