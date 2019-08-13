/********************************************************************************
** Form generated from reading UI file 'infotool.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOTOOL_H
#define UI_INFOTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_infoTool
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *pb_im;
    QPushButton *pb_ex;
    QPushButton *pb_yes;
    QPushButton *pb_cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *infoTool)
    {
        if (infoTool->objectName().isEmpty())
            infoTool->setObjectName(QStringLiteral("infoTool"));
        infoTool->resize(446, 459);
        gridLayout = new QGridLayout(infoTool);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableWidget = new QTableWidget(infoTool);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout_2->addWidget(tableWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pb_im = new QPushButton(infoTool);
        pb_im->setObjectName(QStringLiteral("pb_im"));

        verticalLayout->addWidget(pb_im);

        pb_ex = new QPushButton(infoTool);
        pb_ex->setObjectName(QStringLiteral("pb_ex"));

        verticalLayout->addWidget(pb_ex);

        pb_yes = new QPushButton(infoTool);
        pb_yes->setObjectName(QStringLiteral("pb_yes"));

        verticalLayout->addWidget(pb_yes);

        pb_cancel = new QPushButton(infoTool);
        pb_cancel->setObjectName(QStringLiteral("pb_cancel"));

        verticalLayout->addWidget(pb_cancel);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(infoTool);

        QMetaObject::connectSlotsByName(infoTool);
    } // setupUi

    void retranslateUi(QDialog *infoTool)
    {
        infoTool->setWindowTitle(QApplication::translate("infoTool", "Dialog", nullptr));
        pb_im->setText(QApplication::translate("infoTool", "\345\257\274\345\205\245", nullptr));
        pb_ex->setText(QApplication::translate("infoTool", "\345\257\274\345\207\272", nullptr));
        pb_yes->setText(QApplication::translate("infoTool", "\347\241\256\350\256\244", nullptr));
        pb_cancel->setText(QApplication::translate("infoTool", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class infoTool: public Ui_infoTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOTOOL_H
