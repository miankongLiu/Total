#ifndef CHARTDLG_H
#define CHARTDLG_H
#include <QChart>
#include <QChartView>
#include <QHBoxLayout>
#include <QDialog>
using namespace QtCharts;

namespace Ui {
class chartDlg;
}

class chartDlg : public QDialog
{
    Q_OBJECT

public:
    explicit chartDlg(QWidget *parent = nullptr);
    ~chartDlg();
    void drawPlot(QVector<double> a,QVector<double> b,QString s);

private:
    Ui::chartDlg *ui;
};

#endif // CHARTDLG_H
