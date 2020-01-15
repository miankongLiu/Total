#ifndef INFOTOOL_H
#define INFOTOOL_H

#include <QDialog>

namespace Ui {
class infoTool;
}

class infoTool : public QDialog
{
    Q_OBJECT

public:
    explicit infoTool(QWidget *parent = nullptr);
    ~infoTool();



signals:
   void sendData_(QVector <double> d);


private slots:
   void on_pb_ex_clicked();
   void on_pb_im_clicked();
   void on_pb_yes_clicked();
   void on_pb_cancel_clicked();
   void displayInfoTool();

private:
    Ui::infoTool *ui;
    double angle_,Lt_,Dm_,r_,Lb_,Xbasic_,Zbasic_,Hcenter_,Ybasic_;
};

#endif // INFOTOOL_H
