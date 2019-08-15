#ifndef CAL_H
#define CAL_H
#include <QVector>

class cal
{
public:
    cal();
    QString calculateZ(double clear,double single);
     QVector<double> calculateZD(QVector<QPointF> p);
    void calculateCA(QVector<QPointF> p1);
    QVector<double> calculateAngle();
    void calculateInsert(QVector<double> v,QVector<double> v1,QString radius,QString face,QString machine);
    //生成NC代码
     QVector<QString>  modifyNC(QVector<double> v,QVector<double> v1,QVector<double> p,QString machine,QString face,QString p_Name,QVector<QPointF> p_);
    //r_m为口径，r_为轮端半径
    QVector<QPointF> calculatePoint(QString type,QVector<double>p);
    QVector<QPointF> calculatePoint_real(QString type);
    QVector<double> calculateClear(double clear,double single);
    QVector<QString>  process(QVector<double>& d,QVector<double>& m,QVector<QString>& str,double clear,double single);

    QVector<double> vec,vec_,C_,A_,Z_1,B,angle_real,X_real,Z_real;
    QVector<QPointF> p1;
    QVector<QVector<double>> ve_ve;
    QVector<QString> total;
    double x0,z0;    //顶点，x取值为0
    double x_cal,z_cal;//对刀点
    int a,sign;//a为机型判定符，sign为偏置角判定符
    QString dir_str;
    QVector<double> B_1,B_2;//弧度值

private:

    double R_,r_m,K_,C1_,C2_,C3_,C4_,C5_,C6_,C7_,C8_,C9_,C10_,C11_,C12_,A1_,A2_,A3_;
    double angle,Lt,Dm,r_,Lb,Xbasic,Zbasic,Hcenter,Ybasic,step;//clear_single;
    double x_begin,z_begin,angle_begin;//进刀点
    double clearT;
    QString type,face,radius,single,p_Name;

    QString tellAngle(QVector<double> a);

    void createExcel(QVector<QPointF> p,QString name);

};

#endif // CAL_H
