/********************************************************************************
** Form generated from reading UI file 'chartdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTDLG_H
#define UI_CHARTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_chartDlg
{
public:

    void setupUi(QDialog *chartDlg)
    {
        if (chartDlg->objectName().isEmpty())
            chartDlg->setObjectName(QStringLiteral("chartDlg"));
        chartDlg->resize(516, 411);

        retranslateUi(chartDlg);

        QMetaObject::connectSlotsByName(chartDlg);
    } // setupUi

    void retranslateUi(QDialog *chartDlg)
    {
        chartDlg->setWindowTitle(QApplication::translate("chartDlg", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chartDlg: public Ui_chartDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTDLG_H
