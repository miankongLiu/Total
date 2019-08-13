#include "infotool.h"
#include "ui_infotool.h"
#include "mainwindow.h"
#include <QTableWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#pragma execution_character_set("utf-8")

infoTool::infoTool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoTool)
{
    ui->setupUi(this);

    setWindowTitle("机床和砂轮参数设置：");
     QStringList header;
     header<<"参数名"<<"参数值";
     ui->tableWidget->setColumnCount(2);
     ui->tableWidget->setRowCount(9);
     ui->tableWidget->setHorizontalHeaderLabels(header);
     ui->tableWidget->setItem(0,0,new QTableWidgetItem("B轴偏置角"));
     ui->tableWidget->setItem(1,0,new QTableWidgetItem("砂轮长度"));
     ui->tableWidget->setItem(2,0,new QTableWidgetItem("砂轮中径"));
     ui->tableWidget->setItem(3,0,new QTableWidgetItem("轮端圆弧半径"));
     ui->tableWidget->setItem(4,0,new QTableWidgetItem("回转中心到液压夹面距离"));
     ui->tableWidget->setItem(5,0,new QTableWidgetItem("Xbasic"));
     ui->tableWidget->setItem(6,0,new QTableWidgetItem("Zbasic"));
     ui->tableWidget->setItem(7,0,new QTableWidgetItem("待加工工件在加工完成后的中心厚"));
     ui->tableWidget->setItem(8,0,new QTableWidgetItem("Ybasic"));

     ui->tableWidget->setItem(0,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(1,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(2,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(3,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(4,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(5,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(6,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(7,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(8,1,new QTableWidgetItem("0"));
}

infoTool::~infoTool()
{
    delete ui;
}

void infoTool::on_pb_ex_clicked()
{
    QFileDialog *fileDialog = new QFileDialog();
      fileDialog->setWindowTitle(tr("另存为"));
      fileDialog->setAcceptMode(QFileDialog::AcceptSave);
      fileDialog->setFileMode(QFileDialog::AnyFile);
      fileDialog->setViewMode(QFileDialog::Detail);
      fileDialog->setDirectory(".");
      fileDialog->resize(50,50);
      fileDialog->setMaximumSize(100,100);
      if(fileDialog->exec() == QDialog::Accepted) {
          QString path = fileDialog->selectedFiles()[0];//得到用户选择的文件名
          QString filePath=path+".txt";
          QFile file(filePath);//创建一个文件对象，存储用户选择的文件


           if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
           {
               QMessageBox::critical(NULL, "提示", "无法创建文件");
           }

          QTextStream in(&file);
          in<<"angle  "<<ui->tableWidget->item(0,1)->text()<<"\n";
          in<<"LT  "<<ui->tableWidget->item(1,1)->text()<<"\n";
          in<<"DM  "<<ui->tableWidget->item(2,1)->text()<<"\n";
          in<<"R  "<<ui->tableWidget->item(3,1)->text()<<"\n";
          in<<"LB  "<<ui->tableWidget->item(4,1)->text()<<"\n";
          in<<"Xbasic  "<<ui->tableWidget->item(5,1)->text()<<"\n";
          in<<"Zbasic  "<<ui->tableWidget->item(6,1)->text()<<"\n";
          in<<"Hcenter  "<<ui->tableWidget->item(7,1)->text()<<"\n";
          in<<"Ybasic  "<<ui->tableWidget->item(8,1)->text()<<"\n";
          in.flush();
          file.close();

  }
}
//导入
void infoTool::on_pb_im_clicked()
{
    QFileDialog *dlg =new QFileDialog();
      dlg->setWindowTitle("导出参数文件：");
      dlg->setAcceptMode(QFileDialog::AcceptOpen);
      dlg->setDirectory(".");
      dlg->setFileMode(QFileDialog::AnyFile);
      dlg->setViewMode(QFileDialog::Detail);

      QString s;
      if(dlg->exec()==QFileDialog::Accepted)
      {
        s=dlg->selectedFiles()[0];
      }

       QFile file(s);
       if(!file.open(QFile::ReadOnly | QFile::Text))
        QMessageBox::critical(this, "提示", "无法打开文件");

        QTextStream in(&file);
        QString temp;
        while (!in.atEnd()) {
            temp=in.readLine();
            if(temp.contains("angle")){
                angle_=temp.section("  ",1).toDouble();
              ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(angle_,'g',5)));
               }
            if(temp.contains("LT")){
                Lt_=temp.section("  ",1).toDouble();
              ui->tableWidget->setItem(1,1,new QTableWidgetItem(QString::number(Lt_,'g',5)));
               }
            if(temp.contains("DM")){
                Dm_=temp.section("  ",1).toDouble();
              ui->tableWidget->setItem(2,1,new QTableWidgetItem(QString::number(Dm_,'g',5)));
               }
            if(temp.contains("R")){
                r_=temp.section("  ",1).toDouble();
              ui->tableWidget->setItem(3,1,new QTableWidgetItem(QString::number(r_,'g',5)));
               }
            if(temp.contains("LB")){
                Lb_=temp.section("  ",1).toDouble();
              ui->tableWidget->setItem(4,1,new QTableWidgetItem(QString::number(Lb_,'g',5)));
               }
            if(temp.contains("Xbasic")){
                Xbasic_=temp.section("  ",1).toDouble();
              ui->tableWidget->setItem(5,1,new QTableWidgetItem(QString::number(Xbasic_,'g',5)));
               }
            if(temp.contains("Zbasic")){
                Zbasic_=temp.section("  ",1).toDouble();
              ui->tableWidget->setItem(6,1,new QTableWidgetItem(QString::number(Zbasic_,'g',5)));
               }

            if(temp.contains("Hcenter")){
                Hcenter_=temp.section("  ",1).toDouble();
              ui->tableWidget->setItem(7,1,new QTableWidgetItem(QString::number(Hcenter_,'g',5)));
               }
            if(temp.contains("Ybasic")){
                Ybasic_=temp.section("  ",1).toDouble();
              ui->tableWidget->setItem(8,1,new QTableWidgetItem(QString::number(Ybasic_,'g',5)));
               }
        }
}

void infoTool::on_pb_yes_clicked()
{
    QVector <double> machine;
    angle_=ui->tableWidget->item(0,1)->text().toDouble();
    Lt_=ui->tableWidget->item(1,1)->text().toDouble();
    Dm_=ui->tableWidget->item(2,1)->text().toDouble();
    r_=ui->tableWidget->item(3,1)->text().toDouble();
    Lb_=ui->tableWidget->item(4,1)->text().toDouble();
    Xbasic_=ui->tableWidget->item(5,1)->text().toDouble();
    Zbasic_=ui->tableWidget->item(6,1)->text().toDouble();
    Hcenter_=ui->tableWidget->item(7,1)->text().toDouble();
    Ybasic_=ui->tableWidget->item(8,1)->text().toDouble();
    machine<<angle_<<Lt_<<Dm_<<r_<<Lb_<<Xbasic_<<Zbasic_<<Hcenter_<<Ybasic_;

    this->hide();
    emit sendData_(machine);

}

void infoTool::on_pb_cancel_clicked()
{
    this->close();
}

void infoTool::displayInfoTool()
{
    this->show();
}
