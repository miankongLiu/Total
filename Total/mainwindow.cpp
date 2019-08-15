#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cal.h"
#include "info.h"
#include <QDebug>
#include <qmath.h>
#include <QList>
#include <qalgorithms.h>
#include <QAxObject>
#include <QFileDialog>
#include <QMessageBox>
#pragma execution_character_set("utf-8")
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    t=2;
    ui->setupUi(this);
    clear_Total=0;
    clear_single=0;



    ui->actionhome->setText("主页");
    ui->actioninfoMacine->setText("机床参数");
    ui->actioninfoTool->setText("图纸参数");
    ui->actioncalculate->setText("检测模块");


 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test()
{

    qDebug()<<cal_info.size();
}

void MainWindow::test11(QVector<double> a, QVector<QString> b)
{

    R=a[0];
    r_m=a.at(1);//通光口径
    K=a.at(2);
    C1=a.at(3);
    C2=a.at(4);
    C3=a.at(5);
    C4=a.at(6);
    C5=a.at(7);
    C6=a.at(8);
    C7=a.at(9);
    C8=a.at(10);
    C9=a.at(11);
    C10=a.at(12);
    C11=a.at(13);
    C12=a.at(14);
    A1=a.at(15);
    A2=a.at(16);
    A3=a.at(17);

    p_Name=b[0];
    step=b[1].toDouble();
    face=b[2];
    type=b[3];
    radius=b[4];


}
//设置显示内容
void MainWindow::setString(QString str,QString str1)
{
    ui->lineEdit_2->setText(str);
    ui->plainTextEdit->setPlainText(str1);

}

QVector<QPointF> MainWindow::readExcel(QString s)
{      QVector<QPointF> p;
       s.replace("/","\\");
       QAxObject* excel = new QAxObject(this);
       excel->setControl("Excel.Application");  // 连接Excel控件
       excel->dynamicCall("SetVisible (bool Visible)", "false"); // 不显示窗体
       excel->setProperty("DisplayAlerts", false);
       // step2: 打开工作簿
       QAxObject* workbooks = excel->querySubObject("WorkBooks"); // 获取工作簿集合
       QAxObject* workbook = workbooks->querySubObject("Open(const QString&)", s);
       // step3: 打开sheet
       QAxObject* worksheet = workbook->querySubObject("WorkSheets(int)", 1);
       // step4: 获取行数，列数
       QAxObject* usedrange = worksheet->querySubObject("UsedRange"); // sheet范围

       QAxObject *rows, *columns;
       rows = usedrange->querySubObject("Rows");  // 行
       columns = usedrange->querySubObject("Columns");  // 列

       int intRow = rows->property("Count").toInt(); // 行数

       for(int i=0;i<intRow;i++){
           QString X = "A" + QString::number(i + 1);
           QString Z = "B" + QString::number(i + 1);
           QAxObject* cellX = worksheet->querySubObject("Range(QVariant, QVariant)", X);
           QAxObject* cellZ = worksheet->querySubObject("Range(QVariant, QVariant)", Z);
           double x=cellX->dynamicCall("Value2()").toDouble();
           double z=cellZ->dynamicCall("Value2()").toDouble();
           p<<QPointF(x,z);
}
return p;
}
//计算前先判断数据是否存在
bool MainWindow::tellData()
{
    if(R==0.0||r_m==0.0||K==0.0||Lb==0.0||Xbasic==0.0||Zbasic==0.0||Hcenter==0.0){
        warn="请仔细检查计算参数！不能为0！";
    }
    if(warn=="") return true;
    return false;
}

void MainWindow::calClear()
{   QVector<double> vec,vec_;
    QVector<QPointF> p1;

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

             temp=(qPow(t,2))/(R*(1+qSqrt(1-(1+K)*qPow(t/R,2))))+C1+C2*qPow(t,2)+C3*qPow(t,4)+C4*qPow(t,6)+C5*qPow(t,8)+C6*qPow(t,10)+C7*qPow(t,12)+C8*qPow(t,14)+C9*qPow(t,16)+C10*qPow(t,18)+C11*qPow(t,20)+C12*qPow(t,22);

            }else if(t>=r_m/2){

             temp=(qPow(t,2))/(R*(1+qSqrt(1-(1+K)*qPow(t/R,2))))+C1+C2*qPow(t,2)+C3*qPow(t,4)+C4*qPow(t,6)+C5*qPow(t,8)+C6*qPow(t,10)+C7*qPow(t,12)+C8*qPow(t,14)+C9*qPow(t,16)+C10*qPow(t,18)+C11*qPow(t,20)+C12*qPow(t,22)
                     +A1*qPow(t,2)+A2*qPow(t,3)+A3*qPow(t,4);

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

    //计算总去除量
    double t,t1,temp,R,h,H;
    h=r_m/2;
    int num=vec_.size();
    H=vec_.at(num-1);
    H=abs(H);
    R=(pow(h,2)+pow(H,2))/(2*H);
    QList<double> list;

    for(int i =0;i<vec_.size();i++){
        t=vec.at(i);
        t1=vec_.at(i);

        //非球度
        temp=qPow(t,2)/(R*(1+(sqrt(1-(qPow(t,2)/qPow(R,2))))))-qAbs(t1);

        list<<temp;
        qDebug()<<temp;
      }
    qSort(list.begin(), list.end());

    //clear_Total=list.at(list.size()-1);

    ui->edit_total->setText(QString::number(list.at(list.size()-1),'g',6));
}
/*
void MainWindow::receiveData(QVector<double> d)
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


}

void MainWindow::receiveMachine(QVector<double> m)
{
        angle=m.at(0);
        Lt=m.at(1);
        Dm=m.at(2);
        r_=m.at(3);//轮端
        Lb=m.at(4);
        Xbasic=m.at(5);
        Zbasic=m.at(6);
        Hcenter=m.at(7);
        Ybasic=m.at(8);
}*/
//机床
void MainWindow::on_actioninfoMacine_triggered()
{

   emit showInfo();

}
//砂轮
void MainWindow::on_actioninfoTool_triggered()
{

    //ui->stackedWidget->setCurrentWidget(infoT);
   emit showInfoT();
}

void MainWindow::on_actioncalculate_triggered()
{
  emit showCalTest(cal_info,machine);
}

void MainWindow::receiveStr(QVector<QString>s)
{

    QVector<QString> res=s;
    QString s1;
    for(int i=0;i<=res.size()-1;i++){
       s1+=res[i];
       s1+="  ";
    }
    ui->lineEdit->setText(s1);

}

void MainWindow::receiveClear(double a)
{
    qDebug()<<"receive"<<a;
    clear_Total=a;


}
//计算
void MainWindow::on_pb_caculate_clicked()
{

   clear_single=ui->edit_sigle->text().toDouble();
   clear_Total=ui->edit_total->text().toDouble();


   cal cl;
   QVector<QString> ts=cl.process(cal_info,machine,st,clear_Total,clear_single);

   if(!ts.isEmpty()){
       setString(ts[1],ts[0]);}
}


void MainWindow::receiveData(QVector<double> d,QVector<QString> m)
{

    ui->edit_sigle->setText("请输入");
    cal_info.clear();
    cal_info=d;
    st=m;


    R=cal_info[0];
    r_m=cal_info.at(1);//通光口径
    K=cal_info.at(2);
    C1=cal_info.at(3);
    C2=cal_info.at(4);
    C3=cal_info.at(5);
    C4=cal_info.at(6);
    C5=cal_info.at(7);
    C6=cal_info.at(8);
    C7=cal_info.at(9);
    C8=cal_info.at(10);
    C9=cal_info.at(11);
    C10=cal_info.at(12);
    C11=cal_info.at(13);
    C12=cal_info.at(14);
    A1=cal_info.at(15);
    A2=cal_info.at(16);
    A3=cal_info.at(17);

    p_Name=st[0];
    step=st[1].toDouble();
    face=st[2];
    type=st[3];
    radius=st[4];
   calClear();

}
//接收机床参数
void MainWindow::receiveMachine(QVector<double> m)
{   machine.clear();
    machine=m;
    angle=machine.at(0);
    Lt=machine.at(1);
    Dm=machine.at(2);
    r_=machine.at(3);//轮端
    Lb=machine.at(4);
    Xbasic=machine.at(5);
    Zbasic=machine.at(6);
    Hcenter=machine.at(7);
    Ybasic=machine.at(8);


}

void MainWindow::receiveString(QVector<QString> m)
{
   p_Name=m[0];
   step=m[1].toDouble();
   face=m[2];
   type=m[3];
   radius=m[4];

  st=m;
}
//理论文件
void MainWindow::on_open_clicked()
{
  QFileDialog * dlg= new QFileDialog(this);
  dlg->setWindowTitle("导入理论文件：");
  dlg->setAcceptMode(QFileDialog::AcceptOpen);
  dlg->setDirectory(".");
  dlg->setFileMode(QFileDialog::AnyFile);
  dlg->setViewMode(QFileDialog::Detail);
  dlg->setNameFilter(QString(tr("*.xlxs")));

  QString s;
  if(dlg->exec()==QFileDialog::Accepted)
  {
    s=dlg->selectedFiles()[0];
    ui->lineEdit_3->setText(s);
  }
}

void MainWindow::on_open1_clicked()
{
    QFileDialog *dlg= new QFileDialog(this);
    dlg->setWindowTitle("导入误差数据：");
    dlg->setAcceptMode(QFileDialog::AcceptOpen);
    dlg->setFileMode(QFileDialog::AnyFile);
    dlg->setViewMode(QFileDialog::Detail);
    dlg->setDirectory(".");
    dlg->setNameFilter(tr("*xlxs"));
    QString s;
    if(dlg->exec()==QFileDialog::Accepted)
    {
      s=dlg->selectedFiles()[0];
      ui->lineEdit_4->setText(s);
    }
}
//补偿
void MainWindow::on_pb_compensation_clicked()
{
    if(ui->lineEdit_3->text()==""||ui->lineEdit_4->text()==""){
        QMessageBox::warning(this,"警告","检查路径是否为空！");
    }else{
        QString s1,s2;
        s1=ui->lineEdit_3->text();
        s2=ui->lineEdit_4->text();

        QVector<QPointF> r1=readExcel(s1);
        QVector<QPointF> r2=readExcel(s2);

        for(int i=0;i<r1.size();i++){
            double t,t1,t2,temp;
            t=r1.at(i).x();//x
            t1=r1.at(i).y();//z
            //t2=vec2.at(i);//z补偿
            t2=0;
            temp=t1+t2;
            b<<temp;
            QPointF ex(t,temp);
            p1<<ex;//理论面形

        }

    }

}
