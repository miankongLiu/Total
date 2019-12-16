#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString fileName,fileName1,step;
    int flag,k;


    QVector<QPointF> readExcel(QString file);
    void createExcel(QVector<QPointF> A,QVector<QPointF> B);
    void drawChart(QVector<QPointF> A,QVector<QPointF> B);

private slots:
    void on_pb_open_clicked();

    void on_rb_k_pressed();

    void on_rb_spline_pressed();

    void on_rb_move_pressed();


    void on_pb_openf_clicked();

    void on_pb_fit_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
