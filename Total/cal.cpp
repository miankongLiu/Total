#include "cal.h"
#include "mainwindow.h"
#include "chartdlg.h"
#include <qmath.h>
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QDebug>

#pragma execution_character_set("utf-8")
cal::cal()
{
   dir_str="D:/comTest";
}

void cal::calculateZ(double clear, double single)
{
    vec.clear();
    vec_.clear();
    C_.clear();
    A_.clear();
    Z_1.clear();
    X_real.clear();
    Z_real.clear();
    p1.clear();

    if(radius=="半口径"){
            double num=(r_m/2)/step;
            num=ceil(num);//向上取整

            for(int i=0;i<num;i++){
                double temp;
                temp=step*i;
                vec<<temp;
            }
            vec<<r_m/2;//存取X点
        }else if(radius=="全口径"){
            double num=(r_m/2)/step;
            num=ceil(num);//向上取整

            for(int i=0;i<num;i++){
                double temp;
                temp=step*i;
                vec<<temp;
            }
            vec<<r_m/2;//存取X点
            int size=vec.size();
            for(int i=1;i>size-1;i++){
                double temp=vec.at(i);
                vec<<-temp;
            }
        }

            for (int i=0;i<vec.size();i++){
                double temp,t;
                 t=vec.at(i);
                 t=abs(t);//无论大于0或者小于0，z值关于y轴对称
                 //将t>=0修改为t>=-r_m/2
                if(t>=-r_m/2&&t<r_m/2){

                 temp=(qPow(t,2))/(R_*(1+qSqrt(1-(1+K_)*qPow(t/R_,2))))+C1_+C2_*qPow(t,2)+C3_*qPow(t,4)+C4_*qPow(t,6)+C5_*qPow(t,8)+C6_*qPow(t,10)+C7_*qPow(t,12)+C8_*qPow(t,14)+C9_*qPow(t,16)+C10_*qPow(t,18)+C11_*qPow(t,20)+C12_*qPow(t,22);

                }else if(t>=r_m/2){

                 temp=(qPow(t,2))/(R_*(1+qSqrt(1-(1+K_)*qPow(t/R_,2))))+C1_+C2_*qPow(t,2)+C3_*qPow(t,4)+C4_*qPow(t,6)+C5_*qPow(t,8)+C6_*qPow(t,10)+C7_*qPow(t,12)+C8_*qPow(t,14)+C9_*qPow(t,16)+C10_*qPow(t,18)+C11_*qPow(t,20)+C12_*qPow(t,22)
                         +A1_*qPow(t,2)+A2_*qPow(t,3)+A3_*qPow(t,4);

                }

                vec_<<temp;
            }


        for(int N=0;N<vec.size();N++){
            double t,t1;
            t=vec.at(N);
            t1=vec_.at(N);

            QPointF ex;
            ex.setX(t);
            ex.setY(t1);
            p1.push_back(ex);//存储理论点集
        }
        Z_1=calculateZD(p1);
        B_2=calculateAngle();
        QVector<double> d=calculateClear(clear,single);
        calculateInsert(vec,vec_,radius,face,type);
        QVector<QPointF> r=calculatePoint_real(type);
        total=modifyNC(vec,vec_,d,type,face,p_Name,r);

        chartDlg ch;
        ch.drawPlot(vec,vec_,"理论曲线");
        ch.drawPlot(X_real,Z_real,"实际曲线");
}

QVector<double> cal::calculateZD(QVector<QPointF> p)
{
       calculateCA(p);
       QVector<double> z1;
       double J=-(1+K_)/qPow(R_,2);

       for(int i=0;i<p.size();i++){
          //x
          double temp=p.at(i).x();
          //G
          double G=qSqrt(1-(1+K_)*qPow((temp/R_),2));
          //G_d1
          double G1=(J*temp)/G;
          //H
          double H=temp/(1+G);


          if(temp<r_m/2){
             z1<<(2*H-G1*qPow(H,2))/R_+C_.at(i);

          }else if(temp>=r_m/2){
             z1<<(2*H-G1*qPow(H,2))/R_+C_.at(i)+A_.at(i);

          }

       }
       return z1;
}

void cal::calculateCA(QVector<QPointF> p1)
{
        C_.clear();
        A_.clear();

        for(int i=0;i<p1.size();i++){
            double temp=p1.at(i).x();
            double temp1=2*C1_*temp+4*C2_*qPow(temp,3)+6*C3_*qPow(temp,5)+8*C4_*qPow(temp,7)+10*C5_*qPow(temp,9)+
            12*C6_*qPow(temp,11)+14*C7_*qPow(temp,13)+16*C8_*qPow(temp,15)+18*C9_*qPow(temp,17)+20*C10_*qPow(temp,19)+22*C11_*qPow(temp,21)+24*C12_*qPow(temp,23);
            C_<<temp1;

            double temp2=2*A1_*temp+3*A2_*qPow(temp,2)+4*A3_*qPow(temp,3);
            A_<<temp2;
        }
}

QVector<double> cal::calculateAngle()
{
        double a_real;
        QVector<double> b;
        for(int i=0;i<Z_1.size();i++){
            double a1=Z_1.at(i);
            double a;
            a=-atan(a1);


            //弧度
            a_real=angle+a*57.3;
            //代码中显示的角度
            //angle_real<<a_real;//角度
            b<<a_real/57.3;//弧度
        }
        return b;
}

void cal::calculateInsert(QVector<double> v, QVector<double> v1, QString radius, QString face, QString machine)
{
    double t_begin,t_beginZ,angle_,a_t;
          double J=-(1+K_)/qPow(R_,2);

              if(face=="凹面"){
                  if(radius=="半口径"){
                    t_begin=v.at(v.size()-2);
                    a_t=B_2.at(B_2.size()-1);
                  }else{
                    t_begin=v.at(v.size()-2);
                    t_begin=qAbs(t_begin);
                    a_t=B_2.at((B_2.size()-1)/2);
                  }

                   t_beginZ=v1.at(v1.size()-1);

                   angle_begin=angle+a_t*57.3;
                   angle_=angle_begin/57.3;
              }else if(face=="凸面"){
                  if(radius=="半口径"){
                   t_begin=v.at(v.size()-1)+step;

                  }else{
                   t_begin=v.at(v.size()-1)+step;
                   t_begin=qAbs(t_begin);

                  }

                  if(t_begin>=qAbs(R_)/sqrt(1+K_)){
                     t_beginZ=v1.at(v1.size()-1);
                     if(radius=="半口径"){
                         a_t=B_2.at(B_2.size()-1);
                         angle_begin=angle+a_t*57.3;
                         angle_=angle_begin/57.3;
                     }else{
                         a_t=B_2.at((B_2.size()-1)/2);
                         angle_begin=angle+a_t*57.3;
                         angle_=angle_begin/57.3;
                     }

                  }else if(t_begin<qAbs(R_)/sqrt(1+K_)){
                      t_beginZ=(qPow(t_begin,2))/(R_*(1+qSqrt(1-(1+K_)*qPow(t_begin/R_,2))))+C1_+C2_*qPow(t_begin,2)+C3_*qPow(t_begin,4)+C4_*qPow(t_begin,6)+C5_*qPow(t_begin,8)+C6_*qPow(t_begin,10)+C7_*qPow(t_begin,12)+C8_*qPow(t_begin,14)+C9_*qPow(t_begin,16)+C10_*qPow(t_begin,18)+C11_*qPow(t_begin,20)+C12_*qPow(t_begin,22)
                                        +A1_*qPow(t_begin,2)+A2_*qPow(t_begin,3)+A3_*qPow(t_begin,4);
                      //G
                       double G=qSqrt(1-(1+K_)*qPow((t_begin/R_),2));
                      //G_d1
                        double G1=(J*t_begin)/G;
                      //H
                        double H=t_begin/(1+G);
                        double t_beginC=2*C1_*t_begin+4*C2_*qPow(t_begin,3)+6*C3_*qPow(t_begin,5)+8*C4_*qPow(t_begin,7)+10*C5_*qPow(t_begin,9)+
                                12*C6_*qPow(t_begin,11)+14*C7_*qPow(t_begin,13)+16*C8_*qPow(t_begin,15)+18*C9_*qPow(t_begin,17)+20*C10_*qPow(t_begin,19)+22*C11_*qPow(t_begin,21)+24*C12_*qPow(t_begin,23);
                                double t_beginA=2*A1_*t_begin+3*A2_*qPow(t_begin,2)+4*A3_*qPow(t_begin,3);
                      //导数
                        double t_z=(2*H-G1*qPow(H,2))/R_+t_beginC+t_beginA;
                        a_t =-atan(t_z);
                        angle_begin=angle+a_t*57.3;
                        angle_=angle_begin/57.3;
                  }

              }



          if(machine=="LGS-200") a=-1;

          if(machine=="LGS-300") a=1;
          //定义信号量函数

              if(a_t>=0){
                 sign=1;
              }else{
                 sign=-1;
              }


              //切角
              double x1,x2,x3,z1,z2,z3,x,z;

              x1=-(a*Lb+Lt-r_)*sin(angle_);
              x2=-sign*Dm/2*(1-cos(angle_));
              x3=-r_*sin(a_t);
              z1=(a*Lb+Lt-r_)*(1-cos(angle_));
              z2=-sign*Dm/2*sin(angle_);
              z3=-r_*(1-cos(a_t));
              //偏差值
              x=x1+x2+x3-x0;
              z=z1+z2+z3-z0;


              x_begin=a*(t_begin-x);
              z_begin=a*(t_beginZ-z);



}

QVector<QString> cal::modifyNC(QVector<double> v, QVector<double> v1, QVector<double> p, QString machine, QString face, QString p_Name, QVector<QPointF> p_)
{
    QVector<QString> res;
        double R,h,H;
        h=r_m/2;
        int num=v1.size();
        H=v1.at(num-1);
        H=abs(H);
        R=(pow(h,2)+pow(H,2))/(2*H);

       double clear_single,surplus;
       surplus=0;
       clear_single=0;
       int num_clear;
       clear_single=p.at(1);//单次去除
       num_clear=p.at(2);//去除次数
       surplus=p.at(3);//余量


           //凹凸面
           double z_safe=0.0;
           if(face=="凸面"){

               z_safe=-10;


           }else if(face=="凹面"){

               z_safe=-(10+H);
           }

           QDateTime datetime;
           QString NC;
           QString timestr=datetime.currentDateTime().toString("yyyyMMddHHmmss");
           NC = dir_str+ "/"+timestr+p_Name+".nc";//假设指定文件夹路径为D盘根目录
           NC.replace("/","\\");

           QFile file(NC);
           if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
           {   MainWindow *m=new MainWindow;
               QMessageBox::critical(m, "提示", "无法创建文件");
           }

           QTextStream in(&file);

           if(clear_single==0.0){
           MainWindow *m=new MainWindow;
           QMessageBox::information(m,"提示：","请输入单次去除量！",QMessageBox::Yes);
           return  res;
           }else

               in<<"%"<<"\n";
               in<<p_Name<<"\n";
               in<<"N10 "<<"G90"<<"\n";
               in<<"N20 "<<"G01 "<<"Z0"<<" F400"<<"\n";
               in<<"N30 "<<"G01 "<<"B0"<<" F200"<<"\n";
               in<<"N40 "<<"G01 "<<"X0"<<" F500"<<"\n";
               in<<"N50 "<<"M17"<<"\n";
               in<<"N60 "<<"M23 "<<"S3500 "<<"\n";
               in<<"N70 "<<"G01 "<<"X"<<x_cal<<" F500"<<"\n";
               if(machine=="LGS-300"){
               in<<"N75 "<<"G01 "<<"Y"<<Ybasic<<" F500"<<"\n";
               }

               in<<"N76 "<<"B"<<angle<<" F100\n";
               in<<"N80 "<<"M08"<<"\n";
               in<<"N85 "<<"M03 S40"<<"\n";
               in<<"N90 G04 F10000"<<"\n";
               in<<"N95 G01 Z"<<z_cal<<" F400"<<"\n";
               in<<"N100 "<<"G04"<<" F1000"<<"\n";
               in<<"N105 "<<"G92 X0 Z0  \n";
               in<<"*N110 P200=1 \n";
               in<<"N115 G01 Z"<<z_safe<< " F100\n";
               in<<"N120 X"<<x_begin<<"  B"<<angle_begin<<"\n";
               //in<<"N125 Z"<<z_begin+clear_single<<"\n";
               in<<"N125 Z"<<z_begin-clear_single<<"\n";
               in<<"N130 G01 F20\n";
               int m=0;
               int j=1;

               for(int i=p.size()-1;i>=0;i--){
                   m=130+j*5;
                   //in<<"N"<<m<<" X"<<p_.at(i).x()<<"  Z"<<p_.at(i).y()+clear_single<<"  B"<<angle_real.at(i)<<"\n";
                   in<<"N"<<m<<" X"<<p_.at(i).x()<<"  Z"<<p_.at(i).y()-a*clear_single<<"  B"<<B_2.at(i)*57.3<<"\n";
                   j++;
               }
               in<<"N"<<m+1<<" G92 X0 Z0\n";
               in<<"*N"<<m+2<<" P200=P200+1\n";
               in<<"*N"<<m+3<<" IF P200<"<<num_clear+1<<" GO 115 \n";

               if(surplus!=0.0){
               in<<"N"<<m+4<<" Z"<<z_safe<<" F100\n";
               in<<"N"<<m+5<<" X"<<x_begin<<" B"<<angle_begin<<"\n";
               //in<<"N"<<m+6<<" Z"<<z_begin+surplus<<"\n";
               in<<"N"<<m+6<<" Z"<<z_begin-surplus<<"\n";
               in<<"N"<<m+7<<" G01 F20\n";
               int j_=1;
               int m_=0;
               int n_=m+7;

               for(int i=p_.size()-1;i>=0;i--){
                   m_=n_+j_*5;
                   //in<<"N"<<m_<<" X"<<p_.at(i).x()<<"  Z"<<p_.at(i).y()+surplus<<"  B"<<angle_real.at(i)<<"\n";
                   in<<"N"<<m_<<" X"<<p_.at(i).x()<<"  Z"<<p_.at(i).y()-surplus<<"  B"<<B_2.at(i)*57.3<<"\n";
                   j_++;

               }
               m=m_;
               }
               in<<"N"<<m+5<<" Z"<<z_safe<<" F200"<<"\n";
               in<<"N"<<m+10<<" M25 \n";
               in<<"N"<<m+15<<" M05 \n";
               in<<"N"<<m+20<<" M09 \n";
               in<<"N"<<m+25<<" G92 \n";
               in<<"N"<<m+30<<" G01 Z0 F400 M18 \n";
               in<<"N"<<m+35<<" G01 B0 F200\n";
               in<<"N"<<m+40<<" G01 X0 F500\n";
               in<<"N"<<m+35<<" M30\n";

               QString text=in.readAll();
               in.flush();
               file.close();


               QString  displayString;
               QFile file_(NC);
                      if(!file_.open(QIODevice::ReadOnly | QIODevice::Text))
                      {
                          qDebug()<<"不能打开文件";
                      }
                      while(!file_.atEnd())
                      {
                          QByteArray line = file_.readLine();
                          QString str(line);
                          displayString.append(str);
                      }
                      res<<displayString<<NC;
                      return res;
}

QVector<QPointF> cal::calculatePoint(QString type, QVector<double> p)
{
    double ang,x1,x2,x3,z1,z2,z3,x,z;
        QVector<QPointF> position;
        //判断符号
        if(type=="LGS-200") a=-1;

        if(type=="LGS-300") a=1;
        //定义信号量函数
        for(int i=0;i<p.size();i++){
            //ang=p.at(i)/57.3;
            ang=p.at(i);
            if(ang>=0){
               sign=1;
            }else{
               sign=-1;
            }
            //顶点处，b=0
            double ang1=angle/57.3;
            x0=-(a*Lb+Lt-r_)*sin(ang1)-sign*Dm/2*(1-cos(ang1))-r_*sin(0);
            z0=(a*Lb+Lt-r_)*(1-cos(ang1))-sign*Dm/2*sin(ang1)-r_*(1-cos(0));
            //对刀点
            x_cal=Xbasic-a*(sign*(Dm/2)+x0);
            z_cal=Zbasic-Hcenter-a*(0+z0);
            //切角
           double b=ang-angle/57.3;
            x1=-(a*Lb+Lt-r_)*sin(ang);
            x2=-sign*Dm/2*(1-cos(ang));
            x3=-r_*sin(b);
            z1=(a*Lb+Lt-r_)*(1-cos(ang));
            z2=-sign*Dm/2*sin(ang);
            z3=-r_*(1-cos(b));
            //偏差值
            x=x1+x2+x3;
            z=z1+z2+z3;
            position<<QPointF(x,z);
        }
        return position;
}

QVector<QPointF> cal::calculatePoint_real(QString type)
{
       QVector<QPointF> real;
       QVector<QPointF> position;

       //偏差x，z
       position=calculatePoint(type,B_2);

       for(int i=0;i<position.size();i++){
           double x_a,z_a;
           double x_real,z_real;
           x_a=position.at(i).x()-x0;
           z_a=position.at(i).y()-z0;
           x_real=a*(vec.at(i)-x_a);
           z_real=a*(vec_.at(i)-z_a);
           X_real<<x_real;
           Z_real<<z_real;
           real<<QPointF(x_real,z_real);

       }
       return real;
}

QVector<double> cal::calculateClear(double clear, double single)
{
    //fmod取模运算,floor向下去整
          int num_clear;//去除次数
          double surplus;//余数
          QVector<double>res;//存取结果，依次是总去除量、单去除、去除次数、余量


          if(single>=(-1e-6)&&single<=(1e-6)){
            if(fmod(clear,single)==0){
               num_clear=clear/single;
               surplus=0;
            }else{
               surplus=fmod(clear,single);
               num_clear=floor(clear/single);

            }
            res<<clear<<single<<num_clear<<surplus;//总去除、单次去除、去除次数、余量

          }
          return res;
}

QVector<QString> cal::process(QVector<double> &d, QVector<double> &m, QVector<QString> &str, double clear, double single)
{
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

       //字符串参数
       p_Name=str[0];
       step=str[1].toDouble();
       type=str[2];
       face=str[3];
       radius=str[4];


        angle=m.at(0);
        Lt=m.at(1);
        Dm=m.at(2);
        r_=m.at(3);//轮端
        Lb=m.at(4);
        Xbasic=m.at(5);
        Zbasic=m.at(6);
        Hcenter=m.at(7);
        Ybasic=m.at(8);


       calculateZ(clear,single);

       return total;

}
