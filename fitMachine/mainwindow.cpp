#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QVector>
#include <QAxObject>
#include "fitFunc.h"
#include <mclmcrrt.h>
#include <mclcppclass.h>
#include <QDebug>
#include <QChartView>
#include <QChart>
#include <QSplineSeries>
#include <QScatterSeries>
using namespace std;
using namespace QtCharts;
#pragma execution_character_set("utf-8")


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->hide();
    ui->le_file->setPlaceholderText("误差文件");
    ui->le_file_->setPlaceholderText("需拟合文件");
    flag=0;
    k=0;


}

MainWindow::~MainWindow()
{
    delete ui;
}
//读取excel，两列x,z
QVector<QPointF> MainWindow::readExcel(QString file)
{
    QVector<QPointF> res;

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

        res<<QPointF(x,z);
}

    if (excel != nullptr)
              {   workbooks->dynamicCall("Close(Boolean)",false);
                  excel->dynamicCall("Quit()");
                  delete excel;
                  excel = nullptr;
              }
    return res;
}

void MainWindow::createExcel(QVector<QPointF> A, QVector<QPointF> B)
{    drawChart(A,B);
    //A为原坐标，B为拟合新坐标
    for(int i=0;i<A.size();i++){
        B.push_back(A.at(i));
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
        for(int i=0;i<B.size();i++){
            double t,t1;
            t=B[i].x();
            t1=B[i].y();

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
            QScatterSeries *series1 = new QScatterSeries();

            for(int i=0;i<A.size();i++){
                series->append(A[i].x(),A[i].y());
            }
            for(int i=0;i<B.size();i++){
                series1->append(B[i].x(),B[i].y());
            }

            QChart *chart = new QChart();
            chart->legend()->hide();
            chart->addSeries(series);
            chart->addSeries(series1);

            chart->createDefaultAxes();
            chart->setTitle("Simple line chart example");

            ui->graphicsView->setChart(chart);
            ui->graphicsView->setRenderHint(QPainter::Antialiasing);

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
k=ui->comboBox->currentText().toInt();
}

void MainWindow::on_rb_spline_pressed()
{
 ui->comboBox->hide();
 flag=1;
}

void MainWindow::on_rb_move_pressed()
{
  ui->comboBox->hide();
  flag=3;
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


    //初始化
    if(!fitFuncInitialize()){
    qDebug()<<"failed";
    return;
     }
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
fitFuncTerminate();

QVector<QPointF> point;
for(mwSize i=1;i<=xx.NumberOfElements();i++){

   double x,z;
   x=xx.Get(i,i);
   z=zz.Get(i,i);
   point<<QPointF(x,z);
}
QVector<QPointF> res=readExcel(fileName);
createExcel(res,point);
}





