#include "fitdialog.h"
#include "ui_fitdialog.h"
#include "fitFunc.h"
#include <QFileDialog>


using namespace  std;
fitDialog::fitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fitDialog)
{
    ui->setupUi(this);
}

fitDialog::~fitDialog()
{
    delete ui;
}

void fitDialog::displayFit()
{
    this->show();
}

void fitDialog::on_open_clicked()
{
        QFileDialog *dlg=new QFileDialog(this);
        dlg->setWindowTitle("选择拟合文件：");
        dlg->setAcceptMode(QFileDialog::AcceptOpen);
        dlg->setDirectory(".");
        dlg->setFileMode(QFileDialog::AnyFile);
        dlg->setViewMode(QFileDialog::Detail);
        dlg->setNameFilter(QString(tr("*.xlsx *.xls")));

        QString fit_file;
        if(dlg->exec()==QFileDialog::Accepted)
        {
            fileName=dlg->selectedFiles()[0];

        }
}

void fitDialog::on_yes_clicked()
{
    double a ,b,c;
    a=ui->left->text().toDouble();
    b=ui->right->text().toDouble();
    c=ui->step->text().toDouble();
    if(fileName!=nullptr){
        /*int num=(b-a)/c;
        num=ceil(num);//向上取整

        double vala[]={a};
        double valb[]={b};
        double valc[]={c};

        //matlab输入参数
        mwArray ma(1,1,mxDOUBLE_CLASS);
        mwArray mb(1,1,mxDOUBLE_CLASS);
        mwArray mc(1,1,mxDOUBLE_CLASS);
        mwArray ms(1,1,mxCHAR_CLASS);
        ma.SetData(vala,1);
        mb.SetData(valb,1);
        mc.SetData(valc,1);*/



    }
}
