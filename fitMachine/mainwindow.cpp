#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QVector>
#include <QAxObject>
#include <QDebug>
#include <QChartView>
#include <QChart>
#include <QSplineSeries>
#include <QScatterSeries>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/Eigenvalues>
#include <QEventLoop>
#include <QTimer>
using namespace std;
using namespace QtCharts;
using namespace Eigen;
#pragma execution_character_set("utf-8")


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

   ui->setupUi(this);
   setWindowTitle("误差拟合");
   ui->comboBox->hide();
   ui->le_file->setPlaceholderText("误差文件");
   ui->le_file_->setPlaceholderText("需拟合文件");
   flag=0;
   k=0;


   /*if(!mclInitializeApplication(nullptr,0)) {
     QMessageBox::information(nullptr,"提示：","调用环境初始化失败！");
     return;
   }
   if(!fitFuncInitialize()){
      QMessageBox::information(nullptr,"提示：","Lib初始化失败！");
      return;
    }*/

}

MainWindow::~MainWindow()
{

    delete ui;
    //fitFuncTerminate();
    //mclTerminateApplication();
}
//读取excel，两列x,z
QVector<QPointF> MainWindow::readExcel(QString file)
{

         QVector<QPointF> p;
         file.replace("/","\\");
         QAxObject* excel = new QAxObject(this);
         excel->setControl("Excel.Application");  // 连接Excel控件
         excel->dynamicCall("SetVisible (bool Visible)", "false"); // 不显示窗体
         excel->setProperty("DisplayAlerts", false);
         // step2: 打开工作簿
         QAxObject* workbooks = excel->querySubObject("WorkBooks"); // 获取工作簿集合
         QAxObject* workbook = workbooks->querySubObject("Open(const QString&)", file);
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
         if (excel != nullptr)
                   {   workbooks->dynamicCall("Close(Boolean)",false);
                       excel->dynamicCall("Quit()");
                       delete excel;
                       excel = nullptr;
                   }

  return p;
}

void MainWindow::createExcel(QVector<QPointF> A, QVector<QPointF> B)
{    drawChart(A,B);
    //A为原坐标，B为拟合新坐标
    for(int i=0;i<B.size();i++){
        //B.push_back(A.at(i));
        A.push_back(B.at(i));
    }

    QString fn=QFileDialog::getSaveFileName(this,tr("另存为："),tr("*.xlsx"));
    if(!fn.isEmpty()){
        fn.replace("/","\\");
        QAxObject *pApplication=new QAxObject();
        QAxObject* pWorkBooks;
        QAxObject* pWorkBook;
        QAxObject* pSheets;
        QAxObject* pSheet;
        QAxObject* cellA,*cellB;
        QString Aa,Bb;
        pApplication->setControl("Excel.Application");
        pApplication->dynamicCall("SetVisible(bool)",true);
        pWorkBooks=pApplication->querySubObject("Workbooks");
        QFile file(fn);
        if(file.exists()){
            pWorkBook=pWorkBooks->querySubObject("Open(const QString &)",fn);

        }else{
            pWorkBooks->dynamicCall("Add");//加载了sheet
            pWorkBook=pApplication->querySubObject("ActiveWorkBook");
            pWorkBook->dynamicCall("SaveAs(const QString&)",fn);
        }
        pSheets=pWorkBook->querySubObject("Sheets");
        pSheet=pSheets->querySubObject("Item(int)",1);

        int row=1;
        for(int i=0;i<A.size();i++){
            double t,t1;
            t=A[i].x();
            t1=A[i].y();

            Aa="A"+QString::number(row,10);
            Bb="B"+QString::number(row,10);

            cellA=pSheet->querySubObject("Range(QString)",Aa);
            cellB=pSheet->querySubObject("Range(QString)",Bb);

            QString s,s1;
            s=QString::number(t,'f',7);
            s1=QString::number(t1,'f',7);

            cellA->dynamicCall("SetValue(const QVatiant&)",s);
            cellB->dynamicCall("SetValue(const QVatiant&)",s1);
            row++;
        }

        if (pApplication != nullptr)
                  {   pWorkBooks->dynamicCall("Close(Boolean)",false);
                      pApplication->dynamicCall("Quit()");
                      delete pApplication;
                      pApplication = nullptr;
                  }
    }

}

void MainWindow::drawChart(QVector<QPointF> A, QVector<QPointF> B)
{
    //A为误差点
    //图表

            QSplineSeries *series = new QSplineSeries();
            QSplineSeries *series1 = new QSplineSeries();

            //画笔颜色
            QPen pen;
            pen.setColor(Qt::blue);
            pen.setWidth(2);

            QPen pen1;
            pen1.setColor(Qt::red);
            pen1.setWidth(2);


            for(int i=0;i<A.size();i++){
                series->append(A[i].x(),A[i].y());
            }
             series->setPen(pen);
            for(int i=0;i<B.size();i++){
                //series1->append(B[i].x(),B[i].y());
                series->append(B[i].x(),B[i].y());
            }
            //series1->setPen(pen1);

            QChart *chart = new QChart();
            chart->legend()->hide();
            chart->addSeries(series);
            chart->addSeries(series1);

            chart->createDefaultAxes();
            chart->setTitle("拟合后");

            ui->graphicsView->setChart(chart);
            ui->graphicsView->setRenderHint(QPainter::Antialiasing);

}

QVector<double> MainWindow::TDMA(size_t n, QVector<double> A, QVector<double> B, QVector<double> C, QVector<double> D)
{
    QVector<double> X(n+1,0);
    size_t i;
    double tmp;

    //上三角矩阵
    C[0] = C[0] / B[0];
    D[0] = D[0] / B[0];

   for(i = 1; i<n; i++)
    {
        tmp = (B[i] - A[i] * C[i-1]);
        C[i] = C[i] / tmp;
        D[i] = (D[i] - A[i] * D[i-1]) / tmp;
    }

   //直接求出X的最后一个值
    X[n-1] = D[n-1];

    //逆向迭代， 求出X
    for(i = n-2; i>0; i--)
    {
        X[i] = D[i] - C[i] * X[i+1];
    }
    return X;
}


//打开文件夹
void MainWindow::on_pb_open_clicked()
{
QFileDialog *dlg = new QFileDialog(this);
dlg->setWindowTitle("导入拟合数据");
dlg->setViewMode(QFileDialog::Detail);
dlg->setFileMode(QFileDialog::AnyFile);
dlg->setAcceptMode(QFileDialog::AcceptOpen);
dlg->setNameFilter(QString(tr("*.xlsx *.xls")));

dlg->show();

if(dlg->exec()==QFileDialog::Accepted){
    fileName=dlg->selectedFiles()[0];
    ui->le_file->setText(fileName);
}
}

void MainWindow::on_rb_k_pressed()
{
ui->comboBox->show();
flag=2;
}

void MainWindow::on_rb_spline_pressed()
{
 ui->comboBox->hide();
 flag=1;
 k=0;
}

void MainWindow::on_rb_move_pressed()
{
  ui->comboBox->hide();
  flag=3;
  k=0;
}


void MainWindow::on_pb_openf_clicked()
{
QFileDialog *dlg= new QFileDialog(this);
dlg->setWindowTitle("导入误差文件：");
dlg->setViewMode(QFileDialog::Detail);
dlg->setFileMode(QFileDialog::AnyFile);
dlg->setAcceptMode(QFileDialog::AcceptOpen);
dlg->setNameFilter(QString(tr("*xls *xlsx")));
dlg->show();

if(dlg->exec()==QFileDialog::Accepted){
    fileName1=dlg->selectedFiles()[0];
    ui->le_file_->setText(fileName1);
}


}

void MainWindow::on_pb_fit_clicked()
{

/*
    //filename误差filename1拟合
    string str=fileName.toStdString();
    const char*p=str.data();
    string str1=fileName1.toStdString();
    const char*p1=str1.data();

   mwArray a(1,1,mxINT8_CLASS);
   mwArray b(1,1,mxINT8_CLASS);
   mwArray s(p);
   mwArray s1(p1);
   a(1,1)=flag;
   b(1,1)=k;

    //输出值
   mwArray xx(4000,1,mxDOUBLE_CLASS);
   mwArray zz(4000,1,mxDOUBLE_CLASS);

   //运行函数

 fitFunc(2,xx,zz,a,b,s1,s);


QVector<QPointF> point;
for(mwSize i=1;i<=xx.NumberOfElements();i++){

   double x,z;
   x=xx.Get(i,i);
   z=zz.Get(i,i);
   point<<QPointF(x,z);
}
QVector<QPointF> res=readExcel(fileName);
createExcel(res,point);*/
    QVector<QPointF> res=readExcel(fileName);
    QVector<QPointF> res_=readExcel(fileName1);
    QVector<double> x,y;
    //取六个点
    for(int i=res.size()-1;i>=res.size()-6;i--){
        double t,t1;
        t=res[i].x();
        t1=res[i].y();
       x.push_back(t);
       y.push_back(t1);
    }


    //拟合值数组
    QVector<double>x0;

    for(int i=0;i<res_.size();i++){
       x0.push_back(res_[i].x());
    }
   qDebug()<<"x0"<<x0.size();
    QVector<QPointF> point;
    //三次样条
    if(flag==1){
     point=splineFit(x,y,x0);
    }
    //最小二乘法
    if(flag==2){
     k=ui->comboBox->currentText().toInt();
     point=polyFit(x,y,x0,k);

    }
    if(flag==3){
     point=mediaFit(x,y,x0);
    }

    createExcel(res,point);
}






void MainWindow::on_pb_stop_clicked()
{
    this->close();
}
//最小二乘法
QVector<QPointF> MainWindow::polyFit(QVector<double> x, QVector<double> y, QVector<double> x0,const int N)
{

    // 创建A矩阵
    Eigen::MatrixXd A(x.size(), N + 1);

    for (unsigned int i = 0; i < x.size(); ++i) {  // 遍历所有点

        for (int n = N, dex = 0; n >= 1; --n, ++dex) {  // 遍历N到1阶
            A(i, dex) = pow(x[i], n);
        }

        A(i, N) = 1;  //
    }

    // 创建B矩阵
    Eigen::MatrixXd B(y.size(), 1);

    for (unsigned int i = 0; i < y.size(); ++i) {
        B(i, 0) = y[i];
    }

    // 创建矩阵W
    Eigen::MatrixXd W;
    W = (A.transpose() * A).inverse() * A.transpose() * B;


   QVector<QPointF> res;
        if(N==2){
          double a,b,c;
          a=W(0,0);
          b=W(1,0);
          c=W(2,0);
         qDebug()<<a<<b<<c;
          for(int i=0;i<x0.size();i++){
            double temp=a*pow(x0[i],2)+b*x0[i]+c;
            QPointF point(x0[i],temp);
            res<<point;
          }
        }
        if(N==3){
            double a,b,c,d;
            a=W(0,0);
            b=W(1,0);
            c=W(2,0);
            d=W(3,0);
            qDebug()<<a<<b<<c<<d;
            for(int i=0;i<x0.size();i++){
              double temp=a*pow(x0[i],3)+b*pow(x0[i],2)+c*pow(x0[i],1)+d;
              QPointF point(x0[i],temp);
              res<<point;
            }
        }
        if(N==4){
            double a,b,c,d,e;

            a=W(0,0);
            b=W(1,0);
            c=W(2,0);
            d=W(3,0);
            e=W(4,0);
            qDebug()<<a<<b<<c<<d<<e;
            for(int i=0;i<x0.size();i++){
              double temp=a*pow(x0[i],4)+b*pow(x0[i],3)+c*pow(x0[i],2)+d*x0[i]+e;
              QPointF point(x0[i],temp);
              res<<point;
            }
        }

qDebug()<<res.size();
return res;
}
//三次B样条近似拟合
QVector<QPointF> MainWindow::splineFit(QVector<double> x, QVector<double> y,QVector<double> x0)
{
    /*int Num=x.size();
    QVector<QPointF> pos;
    QVector<QPointF> temp(Num+2);
    for(int i=0;i<Num;i++){
        QPointF point;
        point.setX(x[i]);
        point.setY(y[i]);
        pos.push_back(point);
    }
   for(int i=0;i<Num;i++)
         temp[i+1]=pos[i];

    QPointF p0(2*temp[1].x()-temp[2].x(),2*temp[1].y()-temp[2].y());
    QPointF p1(2*temp[Num].x()-temp[Num-1].x(),2*temp[Num].y()-temp[Num-1].y());
    temp[0]=p0;
    temp[Num+1]=p1;*/


    // 创建A矩阵
    /*Eigen::MatrixXd A(x.size(), N);
    for(unsigned int  i=0;i<x.size();i++){
     double temp=x[i];
     double f0,f1,f2,f3;
     f0=pow((1-temp),3)/6;
     f1=(3*pow(temp,3)-6*pow(temp,2)+4)/6;
     f2=(-3*pow(temp,3)+3*pow(temp,2)+3*temp+1)/6;
     f3=pow(temp,3)/6;

     A(i, 0) = f0;
     A(i, 1) = f1;
     A(i, 2) = f2;
     A(i, 3) = f3;
     }

    // 创建B矩阵
    Eigen::MatrixXd B(y.size(), 1);

    for (unsigned int i = 0; i < y.size(); ++i) {
        B(i, 0) = y[i];
    }

    // 创建矩阵W
    Eigen::MatrixXd W;
    W = (A.transpose() * A).inverse() * A.transpose() * B;

    //计算结果
   QVector<QPointF> res;
   double p0,p1,p2,p3;
   p0=W(0,0);
   p1=W(1,0);
   p2=W(2,0);
   p3=W(3,0);*/
   /*for(int i=0;i<x0.size();i++){
       double temp=x0[i];
       double f0,f1,f2,f3;
       f0=pow((1-temp),3)/6;
       f1=(3*pow(temp,3)-6*pow(temp,2)+4)/6;
       f2=(-3*pow(temp,3)+3*pow(temp,2)+3*temp+1)/6;
       f3=pow(temp,3)/6;
       double zz=p0*f0+p1*f1+p2*f2+p3*f3;
       QPointF point(x0[i],zz);
       res.push_back(point);
   }*/
    int n=x.size();
    //曲线系数
    QVector<double>ai(n-1,0);
    QVector<double>bi(n-1,0);
    QVector<double>ci(n-1,0);
    QVector<double>di(n-1,0);
    QVector<double>h(n-1,0);

    /* M矩阵的系数
         *[B0, C0, ...
         *[A1, B1, C1, ...
         *[0,  A2, B2, C2, ...
         *[0, ...             An-1, Bn-1]
         */
    QVector<double>A(n-2,0);
    QVector<double>B(n-2,0);
    QVector<double>C(n-2,0);
    QVector<double>D(n-2,0);
    QVector<double>E(n-2,0);
    QVector<double>M(n,0);

   //计算x的步长
    for(int j=0;j<n-1;j++){
      h[j] = x[j + 1] - x[j];
    }
   //指定系数
        for(int i = 0; i< n-3; i++)
       {
            A[i] = h[i]; //忽略A[0]
            B[i] = 2 * (h[i] + h[i+1]);
            C[i] = h[i+1]; //忽略C(n-1)
   }

    //指定常数D
     for (int i = 0; i<n - 3; i++)
      {
         D[i] = 6 * ((y[i + 2] - y[i + 1]) / h[i + 1] - (y[ i + 1] - y[ i]) / h[i]);


     }
       //求解三对角矩阵，结果赋值给E

       E=TDMA(n-3,A, B, C, D);

       M[0] = 0; //自然边界的首端M为0
       M[n-1] = 0;  //自然边界的末端M为0
       for(int i=1; i<n-1; i++)
       {
           M[i] = E[i-1]; //其它的M值
       }
      //三次样条系数
          for(int i = 0; i < n-1; i++)
          {
              ai[i] = y[ i];
              bi[i] = (y[i + 1] - y[i]) / h[i] - (2 * h[i] * M[i] + h[i] * M[i + 1]) / 6;
              ci[i] = M[i] / 2;
              di[i] = (M[i + 1] - M[i]) / (6 * h[i]);
          }
   int size=ai.size();
   double a,b,c,d;
   a=ai[size-1];
   b=bi[size-1];
   c=ci[size-1];
   d=di[size-1];
   double xi=x[x.size()-2];
   QVector<QPointF> res;
   for(int i=0;i<x0.size();i++){
       double y0=a+b*pow((x0[i]-xi),1)+c*pow((x0[i]-xi),2)+d*pow((x0[i]-xi),3);
       QPointF po(x0[i],y0);
       res.push_back(po);
   }

   return res;
}
//均值拟合
QVector<QPointF> MainWindow::mediaFit(QVector<double> x, QVector<double> y,QVector<double> x0)
{
    //取四个点
    double media;
    double total=0.0;
    for(size_t i=0;i<y.size();i++){
       total+=y[i];
    }
    media=total/y.size();
    QVector<QPointF> res;
    for(int i=0;i<x0.size();i++){
        double temp=x0[i];
        QPointF point(temp,y[0]);
        res.push_back(point);
    }

    return res;
}
