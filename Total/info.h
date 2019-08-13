#ifndef INFO_H
#define INFO_H

#include <QDialog>

namespace Ui {
class info;
}

class info : public QDialog
{
    Q_OBJECT

public:
    explicit info(QWidget *parent = nullptr);
    ~info();
     QString w;

     QVector<QString> st;
     QVector <double> d_;
     void tellData();

signals:
    void sendData(QVector <double> d,QVector<QString> m);
    void sendStr(QVector<QString> s);

private slots:
    void on_pb_ex_clicked();
    void on_pb_im_clicked();
    void on_pb_yes_clicked();
    void on_pb_cancel_clicked();
    void displayInfo();


private:
    Ui::info *ui;
    double R1,r1,K1,C1_,C2_,C3_,C4_,C5_,C6_,C7_,C8_,C9_,C10_,C11_,C12_,A1_,A2_,A3_;
};

#endif // INFO_H
