#ifndef FITDIALOG_H
#define FITDIALOG_H

#include <QDialog>

namespace Ui {
class fitDialog;
}

class fitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit fitDialog(QWidget *parent = nullptr);
    ~fitDialog();
    QString fileName;
private:
    Ui::fitDialog *ui;
private slots:
    void displayFit();
    void on_open_clicked();
    void on_yes_clicked();
};

#endif // FITDIALOG_H
