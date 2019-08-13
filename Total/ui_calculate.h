/********************************************************************************
** Form generated from reading UI file 'calculate.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATE_H
#define UI_CALCULATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_calculate
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *calculate)
    {
        if (calculate->objectName().isEmpty())
            calculate->setObjectName(QStringLiteral("calculate"));
        calculate->resize(529, 400);
        label = new QLabel(calculate);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 54, 16));
        label_2 = new QLabel(calculate);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(9, 9, 54, 16));

        retranslateUi(calculate);

        QMetaObject::connectSlotsByName(calculate);
    } // setupUi

    void retranslateUi(QDialog *calculate)
    {
        calculate->setWindowTitle(QApplication::translate("calculate", "Dialog", nullptr));
        label->setText(QApplication::translate("calculate", "\346\255\245\351\225\277", nullptr));
        label_2->setText(QApplication::translate("calculate", "\346\265\213\345\244\264\345\215\212\345\276\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calculate: public Ui_calculate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATE_H
