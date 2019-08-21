#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cal.h"
#include "info.h"
#include "chartdlg.h"
#include <QDebug>
#include <qmath.h>
#include <QList>
#include <qalgorithms.h>
#include <QAxObject>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <QDialog>
#include <QTextBrowser>
#include <QUrl>
#include <QHBoxLayout>
#include <QVBoxLayout>
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


    dir_str="D:/comTest";
    QDir* dir = new QDir();
    if(!dir->exists(dir_str)){
        dir->mkpath(dir_str);
    }
    ui->mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

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
    ui->plainTextEdit->setEnabled(false);
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
{   warn="";
    clear_single=ui->edit_sigle->text().toDouble();
    clear_Total=ui->edit_total->text().toDouble();
    if(R==0.0||r_m==0.0||K==0.0||Lb==0.0){
        warn="请仔细检查计算参数！不能为0！";
    }
    if(clear_single==0.0){
        warn+="\n";
        warn+="单次去除量不能为0！";
    }
    if(clear_Total==0.0){
        warn+="\n";
        warn+="总去除量不能为0！";
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
  emit showCalTest(cal_info,machine,st);
}

void MainWindow::receiveStr(QVector<QString>s)
{

    QVector<QString> res=s;
    QString s1;
    for(int i=0;i<=res.size()-1;i++){
       s1+=res[i];
       s1+="  ";
    }
    //ui->lineEdit->setText(s1);

}

void MainWindow::receiveClear(double a)
{
    qDebug()<<"receive"<<a;
    clear_Total=a;


}
//计算
void MainWindow::on_pb_caculate_clicked()
{

   //clear_single=ui->edit_sigle->text().toDouble();
   //clear_Total=ui->edit_total->text().toDouble();

    if(tellData()==true){
        cal cl;
        QVector<QString> ts=cl.process(cal_info,machine,st,clear_Total,clear_single,dir_str);

        if(!ts.isEmpty()){
            setString(ts[1],ts[0]);}
    }else{
        QMessageBox::warning(this,"警告",warn,QMessageBox::Yes);
    }

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
   //face=m[2];
   //type=m[3];
   type=m[2];
   face=m[3];
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
  dlg->setNameFilter(QString(tr("*.xlsx *.xls")));

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
    dlg->setNameFilter(QString(tr("*.xlsx *.xls")));
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
        if(s1==nullptr||s2==nullptr){
            QMessageBox::warning(this,"警告","选择路径不能为空！",QMessageBox::Yes);
            return;
        }


        if(tellData()==true){
            cal cl;
         QVector<QString> total=cl.processCom(r1,r2,cal_info,machine,st,clear_Total,clear_single,dir_str);

         if(!total.isEmpty()){
             setString(total[1],total[0]);}
        }else{
            QMessageBox::warning(this,"警告",warn,QMessageBox::Yes);
        }

    }

}
//txt转excel
void MainWindow::on_actionTransfer_triggered()
{
    QVector<double>x_Test;
        QFileDialog *dlg=new QFileDialog(this);
        dlg->setWindowTitle("导入检测文件：");
        dlg->setAcceptMode(QFileDialog::AcceptOpen);
        dlg->setDirectory(".");
        dlg->setFileMode(QFileDialog::AnyFile);
        dlg->setViewMode(QFileDialog::Detail);
        dlg->setNameFilter(QString(tr("*.txt")));
        QString root;
        if(dlg->exec()==QFileDialog::Accepted)
        {
            root=dlg->selectedFiles()[0];
        }
        root.replace("/","\\");



        //存储x与误差值
        QVector<double> V1,V2;


        if(root!=nullptr){
            QFile file(root);
                if (file.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    while (!file.atEnd())
                    {
                        QByteArray line = file.readLine();
                        QString str(line);

                        //把中间多余的空格转换为一个空格
                        str=str.simplified();
                        QStringList lst;
                        lst=str.split(" ");
                        QString a = lst[0];
                        QString b = lst[1];




                        b=b.left(b.length()-1);//去除\n
                        double b1;
                        b1=b.toDouble()/1000;
                        V1<<a.toDouble();
                        V2<<b1;






                    }
                    file.close();

                }


            QDateTime datetime;
            QString  fileName;
            QString timestr=datetime.currentDateTime().toString("yyyy-MM-dd-HH-mm-ss");
            fileName = dir_str+ "/"+timestr +"误差"+".xlsx";//假设指定文件夹路径为D盘根目录
            fileName.replace("/","\\");


            QAxObject *pApplication=new QAxObject();
            QAxObject* pWorkBooks;
            QAxObject* pWorkBook;
            QAxObject* pSheets;
            QAxObject* pSheet;
            QAxObject* cellA,*cellB;
            QString A,B;
             pApplication->setControl("Excel.Application");//连接Excel控件
             pApplication->dynamicCall("SetVisible(bool)",true);//false显示窗体,启动excel，但是却没有sheet页面
             pWorkBooks=pApplication->querySubObject("Workbooks");
             QFile file_(fileName);
             if(file_.exists())
                 {
                    pWorkBook=pWorkBooks->querySubObject("Open(const QString &)",fileName);

                 }
                else
                 {
                pWorkBooks->dynamicCall("Add");//加载了sheet
                pWorkBook=pApplication->querySubObject("ActiveWorkBook");
                pWorkBook->dynamicCall("SaveAs(const QString&)",fileName);//文件另存为
                 }

                pSheets=pWorkBook->querySubObject("Sheets");
                pSheet=pSheets->querySubObject("Item(int)",1);



              int row=1;
             for(int N=0;N<V1.size();N++){
                   double t,t1;
                   t=V1.at(N);
                   t1=V2.at(N);


                   A="A"+QString::number(row,10);
                   B="B"+QString::number(row,10);

                   cellA= pSheet->querySubObject("Range(QString)", A);
                   cellB= pSheet->querySubObject("Range(QString)", B);
                   QString s,s1;

                   s=QString::number(t,'f',20);
                   s1=QString::number(t1,'f',20);

                   cellA->dynamicCall("SetValue(conts QVariant&)", s);
                   cellB->dynamicCall("SetValue(conts QVariant&)", s1);
                   row++;


              }
             if (pApplication != nullptr)
                 {   pWorkBooks->dynamicCall("Close(Boolean)",false);
                     pApplication->dynamicCall("Quit()");
                     delete pApplication;
                     pApplication = nullptr;
                 }
            QMessageBox::information(this,"提示","转换成功！",QMessageBox::Yes);
        }else{
            QMessageBox::warning(this,"警告","输入文件不能为空！",QMessageBox::Yes);
        }
}
//误差累加处理
void MainWindow::on_actionPlus_triggered()
{
       QString s_,s__;
       QFileDialog *dlg=new QFileDialog(this);
       dlg->setWindowTitle("导入文件对话框A：");
       dlg->setAcceptMode(QFileDialog::AcceptOpen);
       dlg->setDirectory(".");
       dlg->setFileMode(QFileDialog::AnyFile);
       dlg->setViewMode(QFileDialog::Detail);
       dlg->setNameFilter(QString(tr("*.xlsx *.xls")));

       if(dlg->exec()==QFileDialog::Accepted)
       {
           s_=dlg->selectedFiles()[0];

       }


       QFileDialog *dlg1=new QFileDialog(this);
       dlg1->setWindowTitle("导入文件对话框B：");
       dlg1->setAcceptMode(QFileDialog::AcceptOpen);
       dlg1->setDirectory(".");
       dlg1->setFileMode(QFileDialog::AnyFile);
       dlg1->setViewMode(QFileDialog::Detail);
       dlg1->setNameFilter(QString(tr("*.xlsx *.xls")));

       if(dlg1->exec()==QFileDialog::Accepted)
       {
           s__=dlg1->selectedFiles()[0];

       }
       if(s_==nullptr||s__==nullptr){
          QMessageBox::warning(this,"警告","选择路径不能为空！",QMessageBox::Yes);
          return;
       }
      QVector<QPointF> r1=readExcel(s_);
      QVector<QPointF> r2=readExcel(s__);
      QVector<QPointF> plus;

      if((r1.size()==r2.size())&&(!(r1.size()==0))&&(!(r2.size()==0))){

          for(int i=0;i<r1.size();i++){
             double t1,t2,x;
             t1=r1.at(i).y();
             t2=r2.at(i).y();
             x=r1.at(i).x();
             plus<<QPointF(x,t1+t2);
          }
          cal cl;
          cl.createExcel(plus,"累加误差");
          QMessageBox::information(this,"提示","处理成功！");
      }else{
          QMessageBox::warning(this,"警告","检查excel文档是否符合要求！");
      }
}
//编辑
void MainWindow::on_pb_edit_clicked()
{
   ui->plainTextEdit->setEnabled(true);
}

void MainWindow::on_pb_save_clicked()
{
    QString str;
    str=ui->lineEdit_2->text();
    QFile file(str);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {   MainWindow *m=new MainWindow;
        QMessageBox::critical(m, "提示", "无法创建文件");
    }

    QTextStream in(&file);
    QString text=ui->plainTextEdit->toPlainText();
    in<<text;
    in.flush();
    file.close();

    ui->plainTextEdit->setEnabled(false);
    QMessageBox::information(this,"提示","已将修改过的代码保存至"+str,QMessageBox::Yes);
}
//修改文件路径
void MainWindow::on_actionFile_triggered()
{
   QString file_path = QFileDialog::getExistingDirectory(this, "请选择文件路径...", "./");
    if(file_path.isEmpty())
    {
        return;
    }
    dir_str=file_path;
   QMessageBox::information(this,"提示","当前路径修改为："+file_path,QMessageBox::Yes);

}

void MainWindow::on_actionhelp_triggered()
{

    QWidget *w=new QWidget;
    QVBoxLayout *vb=new QVBoxLayout;
    QTextBrowser *b=new QTextBrowser;
    vb->addWidget(b);
    w->setLayout(vb);

    QFile file(".\\help.htm");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("打不开文件"));
    QTextStream textStream(&file);
    b->setHtml(textStream.readAll());

    w->setWindowTitle("帮助文档");
    w->resize(500,500);
    w->show();


}

void MainWindow::on_actionroot_triggered()
{
    QWidget *w=new QWidget;
    QVBoxLayout *vb=new QVBoxLayout;
    QTextBrowser *b=new QTextBrowser;
    vb->addWidget(b);
    w->setLayout(vb);

    QFile file(".\\root.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("打不开文件"));
    QTextStream textStream(&file);
    b->setText(textStream.readAll());

    w->setWindowTitle("路径说明");
    w->resize(500,500);
    w->show();
}
