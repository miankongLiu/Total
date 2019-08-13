#include "calculate.h"
#include "ui_calculate.h"
#include "mainwindow.h"
#include <qmath.h>
#include <QDebug>
#include<qmath.h>
#include <QDir>
#include <QDateTime>
#include <QMessageBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include "mainwindow.h"
#pragma execution_character_set("utf-8")
//检测模块
calculate::calculate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calculate)
{
    ui->setupUi(this);
}

calculate::~calculate()
{
    delete ui;
}

void calculate::process()
{




}

void calculate::displatAndPro(QVector<double> d,QVector<double> m)
{   if(d.size()<=0||m.size()<=0){
        QMessageBox::warning(this,"警告","请检查计算参数是否输入！");
        return;
    }
    R_=d.at(0);
    r_m=d.at(1);//通光口径
    K_=d.at(2);
    C1_=d.at(3);
    C2_=d.at(4);
    C3_=d.at(5);
    C4_=d.at(6);
    C5_=d.at(7);
    C6_=d.at(8);
    C7_=d.at(9);
    C8_=d.at(10);
    C9_=d.at(11);
    C10_=d.at(12);
    C11_=d.at(13);
    C12_=d.at(14);
    A1_=d.at(15);
    A2_=d.at(16);
    A3_=d.at(17);

     angle=m.at(0);
     Lt=m.at(1);
     Dm=m.at(2);
     r_=m.at(3);//轮端
     Lb=m.at(4);
     Xbasic=m.at(5);
     Zbasic=m.at(6);
     Hcenter=m.at(7);
     Ybasic=m.at(8);


     this->show();

}

void calculate::on_pb_Yes_clicked()
{
    QString p_N,p_T,p_F;
    double r,step,free;
    QVector<double> x_test;
    QVector<double> z_test;
    QVector<double> test_C;
    QVector<double> test_A;
    QVector<double> z1;
    QVector<double> ang;
    QVector<QPointF> end;

    int a;
    if(p_T=="LGS-200"){
        a=1;
    }else{
        a=-1;
    }

    p_N=ui->p_Name->text();
    p_F=ui->comboBox->currentText();
    //暂时不要
    p_T=ui->comboBox_2->currentText();
    ui->comboBox_2->hide();
    ui->label_6->hide();

    r=ui->p_r->text().toDouble();
    step=ui->p_step->text().toDouble();
    free=ui->p_free->text().toDouble();

    //减去免测后的x
    double num=((r_m/2)-(free/2))/step;
    num=ceil(num);
    for(int i=0;i<num;i++){
      double temp;
      temp=step*i;
      x_test<<temp;
    }
     x_test<<(r_m/2)-(free/2);
     //计算z
     for (int i=0;i<x_test.size();i++){
          double temp,t;
          t=x_test.at(i);
          t=abs(t);//无论大于0或者小于0，z值关于y轴对称
          //将t>=0修改为t>=-r_m/2
         if(t>=-r_m/2&&t<r_m/2){

          temp=(qPow(t,2))/(R_*(1+qSqrt(1-(1+K_)*qPow(t/R_,2))))+C1_+C2_*qPow(t,2)+C3_*qPow(t,4)+C4_*qPow(t,6)+C5_*qPow(t,8)+C6_*qPow(t,10)+C7_*qPow(t,12)+C8_*qPow(t,14)+C9_*qPow(t,16)+C10_*qPow(t,18)+C11_*qPow(t,20)+C12_*qPow(t,22);

         }else if(t>=r_m/2){

          temp=(qPow(t,2))/(R_*(1+qSqrt(1-(1+K_)*qPow(t/R_,2))))+C1_+C2_*qPow(t,2)+C3_*qPow(t,4)+C4_*qPow(t,6)+C5_*qPow(t,8)+C6_*qPow(t,10)+C7_*qPow(t,12)+C8_*qPow(t,14)+C9_*qPow(t,16)+C10_*qPow(t,18)+C11_*qPow(t,20)+C12_*qPow(t,22)
                  +A1_*qPow(t,2)+A2_*qPow(t,3)+A3_*qPow(t,4);

         }

         z_test<<temp;
     }

     for(int i=0;i<x_test.size();i++){
     //计算C&A
     double temp=x_test.at(i);
     double temp1=2*C1_*temp+4*C2_*qPow(temp,3)+6*C3_*qPow(temp,5)+8*C4_*qPow(temp,7)+10*C5_*qPow(temp,9)+
            12*C6_*qPow(temp,11)+14*C7_*qPow(temp,13)+16*C8_*qPow(temp,15)+18*C9_*qPow(temp,17)+20*C10_*qPow(temp,19)+22*C11_*qPow(temp,21)+24*C12_*qPow(temp,23);
             test_C<<temp1;

     double temp2=2*A1_*temp+3*A2_*qPow(temp,2)+4*A3_*qPow(temp,3);
             test_A<<temp2;
      }
     //计算导数


     double J=-(1+K_)/qPow(R_,2);

     for(int i=0;i<x_test.size();i++){
        //x
        double temp=x_test[i];
        //G
        double G=qSqrt(1-(1+K_)*qPow((temp/R_),2));
        //G_d1
        double G1=(J*temp)/G;
        //H
        double H=temp/(1+G);


        if(temp<r_m/2){
           z1<<(2*H-G1*qPow(H,2))/R_+test_C.at(i);

        }else if(temp>=r_m/2){
           z1<<(2*H-G1*qPow(H,2))/R_+test_C.at(i)+test_A.at(i);

        }

     }

     //计算角度
     double a_real;

     for(int i=0;i<z1.size();i++){
         double a1=z1.at(i);
         double a;
         a=-atan(a1);
         //弧度
         a_real=angle+a*57.3;
         ang<<a_real/57.3;//弧度
     }

     for(int i=0;i<ang.size();i++){
        double an=ang[i];
        double x,z;
        x=x_test[i];
        z=z_test[i];
        int sign;
        if(an>=0) sign=1;
        if(an<0) sign=-1;
        int t;
        if(p_F=="凹面")t=1;
        else{
            t=-1;
        }

        double x1=-r*qSin(an);
        double z1=r*(1-qCos(an));
        QPointF ex;
        ex.setX(x+t*x1);
        ex.setY(-z-t*z1);
        end<<ex;
     }

     //零点绝对坐标
      double x=0,z=0;
      double x_0,z_0;
      double G_=qSqrt(1+J*qPow(x,2));
      //G_d1
      double G1_=(J*x)/G_;
      //H
      double H_=x/(1+G_);
      double z1_=(2*H_-G1_*qPow(H_,2))/R_;
      //弧度转度
      double degree =-atan(z1_)*57.3;
      double x0,z0;
      x0=0;
      z0=0;
      double x3,z3,z_a,x_a;
      x3=-r*qSin(0);
      z3=r*(qCos(0)-1);
      x_0=Xbasic+(0-x3);
      z_0=Zbasic-Hcenter+(0-z3);
      QString NC;
      QString dir_str="D:/comTest";
      NC = dir_str+ "/"+"检测"+p_N+".nc";//假设指定文件夹路径为D盘根目录
                 NC.replace("/","\\");

                 QFile file(NC);
                 if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
                 {
                     QMessageBox::critical(this, "提示", "无法创建文件");
                 }


                 QTextStream in(&file);
                 in<<"%"<<"\n";
                 in<<p_N<<"\n";
                 in<<"N10 G90 \n";
                 in<<"N20 G04 F3000 \n";
                 in<<"N30 G01 X"<<x_0<<"F1000 \n";
                 in<<"N40 G04 F3000 \n";
                 in<<"N50 G01 Z"<<z_0<<"F500 \n";
                 in<<"N60 G04 F3000 \n";
                 in<<"N70 G92 X0 Z0 \n";
                 in<<"N80 G04 F3000 \n";
                 in<<"*N85 P80=1 \n";
                 int n=90;
                 int j=0;
                 int m=x_test.size();

                 for(int i=x_test.size()-1;i>=0;i--){
                 in<<"N"<<n+10*j<<" G01 X"<<end[i].x()<<" Z"<<end[i].y()<<"\n";
                 in<<"N"<<n+10*(j+1)<<" G04 F2000 \n";
                 j+=2;
                 }


                 in<<"N"<<n+10*j<<" M30";

                 in.flush();
                 file.close();

}

void calculate::on_pb_Cancel_clicked()
{
    this->close();
}
