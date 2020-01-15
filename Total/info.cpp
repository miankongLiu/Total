#include "info.h"
#include "ui_info.h"
#include "calculate.h"
#include "mainwindow.h"
#include <QTableWidget>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <qmath.h>
#pragma execution_character_set("utf-8")

info::info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);

    setWindowTitle("参数设置：");
     QStringList header;
     header<<"参数名"<<"参数值";
     ui->tableWidget->setColumnCount(2);
     ui->tableWidget->setRowCount(18);
     ui->tableWidget->setHorizontalHeaderLabels(header);
     ui->tableWidget->setItem(0,0,new QTableWidgetItem("曲率半径"));
     ui->tableWidget->setItem(1,0,new QTableWidgetItem("实际口径"));
     ui->tableWidget->setItem(2,0,new QTableWidgetItem("K"));
     ui->tableWidget->setItem(3,0,new QTableWidgetItem("C1  0次方"));
     ui->tableWidget->setItem(4,0,new QTableWidgetItem("C2  2次方"));
     ui->tableWidget->setItem(5,0,new QTableWidgetItem("C3  4次方"));
     ui->tableWidget->setItem(6,0,new QTableWidgetItem("C4  6次方"));
     ui->tableWidget->setItem(7,0,new QTableWidgetItem("C5  8次方"));
     ui->tableWidget->setItem(8,0,new QTableWidgetItem("C6  10次方"));
     ui->tableWidget->setItem(9,0,new QTableWidgetItem("C7  12次方"));
     ui->tableWidget->setItem(10,0,new QTableWidgetItem("C8  14次方"));
     ui->tableWidget->setItem(11,0,new QTableWidgetItem("C9  16次方"));
     ui->tableWidget->setItem(12,0,new QTableWidgetItem("C10  18次方"));
     ui->tableWidget->setItem(13,0,new QTableWidgetItem("C11  20次方"));
     ui->tableWidget->setItem(14,0,new QTableWidgetItem("C12  22次方"));
     ui->tableWidget->setItem(15,0,new QTableWidgetItem("A1"));
     ui->tableWidget->setItem(16,0,new QTableWidgetItem("A2"));
     ui->tableWidget->setItem(17,0,new QTableWidgetItem("A3"));


     ui->tableWidget->setItem(3,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(4,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(5,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(6,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(7,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(8,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(9,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(10,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(11,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(12,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(13,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(14,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(15,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(16,1,new QTableWidgetItem("0"));
     ui->tableWidget->setItem(17,1,new QTableWidgetItem("0"));


}

info::~info()
{
    delete ui;
}

void info::tellData()
{
    if(ui->tableWidget->item(0,1) == NULL ||
       (ui->tableWidget->item(0,1) && ui->tableWidget->item(0,1)->text() == "")){
     w="曲率半径不能为0！";
    }
    if(ui->tableWidget->item(1,1) == NULL ||
       (ui->tableWidget->item(1,1) && ui->tableWidget->item(1,1)->text() == "")){
     w=w+"\n"+"实际口径不能为0！";
    }
    if(ui->tableWidget->item(2,1) == NULL ||
       (ui->tableWidget->item(2,1) && ui->tableWidget->item(2,1)->text() == "")){
     w=w+"\n"+"K不能为0！";
    }
}


//导出
void info::on_pb_ex_clicked()
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
           in<<"R0  "<<ui->tableWidget->item(0,1)->text()<<"\n";
           in<<"Q  "<<ui->tableWidget->item(1,1)->text()<<"\n";
           in<<"K  "<<ui->tableWidget->item(2,1)->text()<<"\n";
           in<<"C1  "<<ui->tableWidget->item(3,1)->text()<<"\n";
           in<<"C2  "<<ui->tableWidget->item(4,1)->text()<<"\n";
           in<<"C3  "<<ui->tableWidget->item(5,1)->text()<<"\n";
           in<<"C4  "<<ui->tableWidget->item(6,1)->text()<<"\n";
           in<<"C5  "<<ui->tableWidget->item(7,1)->text()<<"\n";
           in<<"C6  "<<ui->tableWidget->item(8,1)->text()<<"\n";
           in<<"C7  "<<ui->tableWidget->item(9,1)->text()<<"\n";
           in<<"C8  "<<ui->tableWidget->item(10,1)->text()<<"\n";
           in<<"C9  "<<ui->tableWidget->item(11,1)->text()<<"\n";
           in<<"C10  "<<ui->tableWidget->item(12,1)->text()<<"\n";
           in<<"C11  "<<ui->tableWidget->item(13,1)->text()<<"\n";
           in<<"C12  "<<ui->tableWidget->item(14,1)->text()<<"\n";
           in<<"A1  "<<ui->tableWidget->item(15,1)->text()<<"\n";
           in<<"A2  "<<ui->tableWidget->item(16,1)->text()<<"\n";
           in<<"A3  "<<ui->tableWidget->item(17,1)->text()<<"\n";

           in.flush();
           file.close();

   }
}
//导入
void info::on_pb_im_clicked()
{

       QString S_;
       QFileDialog *dlg=new QFileDialog(this);
       dlg->setWindowTitle("参数文件：");
       dlg->setAcceptMode(QFileDialog::AcceptOpen);
       dlg->setDirectory(".");
       dlg->setFileMode(QFileDialog::AnyFile);
       dlg->setViewMode(QFileDialog::Detail);
       dlg->setNameFilter(QString(tr("*.txt")));

       if(dlg->exec()==QFileDialog::Accepted)
       {
         S_=dlg->selectedFiles()[0];

       }

        QFile file(S_);
        if(!file.open(QFile::ReadOnly | QFile::Text))
         qDebug() << "Can not open";

         QTextStream in(&file);
         QString temp;
         while(!in.atEnd()){
         temp=in.readLine();

         if(temp.contains("Q")){
           r1=temp.section("  ",1).toDouble();
            }
         if(temp.contains("R0")){
           R1=temp.section("  ",1).toDouble();
           }
          if(temp.contains("K")){
           K1=temp.section("  ",1).toDouble();
            }
          if(temp.contains("A1")){
           A1_=temp.section("  ",1).toDouble();
           }
          if(temp.contains("A2")){
           A2_=temp.section("  ",1).toDouble();
           }
           if(temp.contains("A3")){
           A3_=temp.section("  ",1).toDouble();
            }
           if(temp.contains("C1")){
            C1_=temp.section("  ",1).toDouble();
             }
            if(temp.contains("C2")){
             C2_=temp.section("  ",1).toDouble();
             }
            if(temp.contains("C3")){
             C3_=temp.section("  ",1).toDouble();
              }
            if(temp.contains("C4")){
             C4_=temp.section("  ",1).toDouble();
               }
            if(temp.contains("C5")){
             C5_=temp.section("  ",1).toDouble();
              }
            if(temp.contains("C6")){
             C6_=temp.section("  ",1).toDouble();
              }
            if(temp.contains("C7")){
             C7_=temp.section("  ",1).toDouble();
             }
            if(temp.contains("C8")){
             C8_=temp.section("  ",1).toDouble();
              }
            if(temp.contains("C9")){
             C9_=temp.section("  ",1).toDouble();
               }
             if(temp.contains("C10")){
               C10_=temp.section("  ",1).toDouble();
               }
              if(temp.contains("C11")){
               C11_=temp.section("  ",1).toDouble();
                }
               if(temp.contains("C12")){
                C12_=temp.section("  ",1).toDouble();
                    }
                 }


       ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(R1,'g',10)));
       ui->tableWidget->setItem(1,1,new QTableWidgetItem(QString::number(r1,'g',15)));
       ui->tableWidget->setItem(2,1,new QTableWidgetItem(QString::number(K1,'g',15)));
       ui->tableWidget->setItem(3,1,new QTableWidgetItem(QString::number(C1_,'g',10)));
       ui->tableWidget->setItem(4,1,new QTableWidgetItem(QString::number(C2_,'g',10)));
       ui->tableWidget->setItem(5,1,new QTableWidgetItem(QString::number(C3_,'g',10)));
       ui->tableWidget->setItem(6,1,new QTableWidgetItem(QString::number(C4_,'g',10)));
       ui->tableWidget->setItem(7,1,new QTableWidgetItem(QString::number(C5_,'g',10)));
       ui->tableWidget->setItem(8,1,new QTableWidgetItem(QString::number(C6_,'g',10)));
       ui->tableWidget->setItem(9,1,new QTableWidgetItem(QString::number(C7_,'g',10)));
       ui->tableWidget->setItem(10,1,new QTableWidgetItem(QString::number(C8_,'g',10)));
       ui->tableWidget->setItem(11,1,new QTableWidgetItem(QString::number(C9_,'g',10)));
       ui->tableWidget->setItem(12,1,new QTableWidgetItem(QString::number(C10_,'g',10)));
       ui->tableWidget->setItem(13,1,new QTableWidgetItem(QString::number(C11_,'g',10)));
       ui->tableWidget->setItem(14,1,new QTableWidgetItem(QString::number(C12_,'g',10)));
       ui->tableWidget->setItem(15,1,new QTableWidgetItem(QString::number(A1_,'g',10)));
       ui->tableWidget->setItem(16,1,new QTableWidgetItem(QString::number(A2_,'g',10)));
       ui->tableWidget->setItem(17,1,new QTableWidgetItem(QString::number(A3_,'g',10)));

}

void info::on_pb_yes_clicked()
{
       tellData();
       if(w!=""){
          QMessageBox::warning(this, "warning", w, QMessageBox::Yes );
       }else{


           R1=ui->tableWidget->item(0,1)->text().toDouble();
           r1=ui->tableWidget->item(1,1)->text().toDouble();
           K1=ui->tableWidget->item(2,1)->text().toDouble();
           C1_=ui->tableWidget->item(3,1)->text().toDouble();
           C2_=ui->tableWidget->item(4,1)->text().toDouble();
           C3_=ui->tableWidget->item(5,1)->text().toDouble();
           C4_=ui->tableWidget->item(6,1)->text().toDouble();
           C5_=ui->tableWidget->item(7,1)->text().toDouble();
           C6_=ui->tableWidget->item(8,1)->text().toDouble();
           C7_=ui->tableWidget->item(9,1)->text().toDouble();
           C8_=ui->tableWidget->item(10,1)->text().toDouble();
           C9_=ui->tableWidget->item(11,1)->text().toDouble();
           C10_=ui->tableWidget->item(12,1)->text().toDouble();
           C11_=ui->tableWidget->item(13,1)->text().toDouble();
           C12_=ui->tableWidget->item(14,1)->text().toDouble();
           A1_=ui->tableWidget->item(15,1)->text().toDouble();
           A2_=ui->tableWidget->item(16,1)->text().toDouble();
           A3_=ui->tableWidget->item(17,1)->text().toDouble();

           d_<<R1<<r1<<K1<<C1_<<C2_<<C3_<<C4_<<C5_<<C6_<<C7_<<C8_<<C9_<<C10_<<C11_<<C12_<<A1_<<A2_<<A3_;

           QString type,face,radius,p_Name,step;

           p_Name=ui->edit_pName->text();
           step=ui->edit_step->text();
           face=ui->box_face->currentText();
           radius=ui->box_q->currentText();
           type=ui->box_machine->currentText();


           st<<p_Name<<step<<type<<face<<radius;
           emit sendData(d_,st);
           this->hide();

       }


   //this->close();
}

void info::on_pb_cancel_clicked()
{
    this->close();
}

void info::displayInfo()
{
    this->show();
}





