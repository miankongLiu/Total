#ifndef CALCULATE_H
#define CALCULATE_H

#include <QDialog>
#include <QTextStream>
using namespace std;
namespace Ui {
class calculate;
}

class calculate : public QDialog
{
    Q_OBJECT

public:
    explicit calculate(QWidget *parent = nullptr);
    ~calculate();
    double R_,r_m,K_,C1_,C2_,C3_,C4_,C5_,C6_,C7_,C8_,C9_,C10_,C11_,C12_,A1_,A2_,A3_;
    double angle,Lt,Dm,r_,Lb,Xbasic,Zbasic,Hcenter,Ybasic,step;//clear_single;
    QString type,face,radius,p_Name;


private:
    Ui::calculate *ui;
    void process();

private slots:
    void displatAndPro(QVector<double> d,QVector<double> m,QVector<QString >st);
    void on_pb_Yes_clicked();
    void on_pb_Cancel_clicked();
};

#endif // CALCULATE_H
