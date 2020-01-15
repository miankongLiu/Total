#include "chartdlg.h"
#include "ui_chartdlg.h"
#include <QChartView>
#include <QChart>
#include <QScatterSeries>
chartDlg::chartDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chartDlg)
{
    ui->setupUi(this);
}

chartDlg::~chartDlg()
{
    delete ui;
}

void chartDlg::drawPlot(QVector<double> a, QVector<double> b, QString s)
{
        QPointF pf;
        //图表的数据源
        QScatterSeries *series = new QScatterSeries();

        for(int i=0;i<a.size();i++){
           pf.setX(a.at(i));
           pf.setY(b.at(i));
           series->append(pf);

        }
         series->setPen(QPen(Qt::NoPen));
        // 构建图表

         QChart *chart = new QChart();

         chart->legend()->hide();  // 隐藏图例

         chart->addSeries(series);  // 将 series 添加至图表中

         chart->createDefaultAxes();  // 基于已添加到图表的 series 来创轴

         chart->setTitle(s);  // 设置图表的标题


         // 构建 QChartView，并设置抗锯齿、标题、大小

         QChartView *chartView = new QChartView(chart);

         chartView->setRenderHint(QPainter::Antialiasing);

         chartView->setWindowTitle(s);

         chartView->resize(500, 500);

         chartView->show();

}
