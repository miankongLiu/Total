#include "calculate.h"
#include "ui_calculate.h"
#include "mainwindow.h"
#include <qmath.h>
#include <QDebug>
#include<qmath.h>
#include <QDir>
#include <QDateTime>
#include <QMessageBox>
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
