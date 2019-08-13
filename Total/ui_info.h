/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_info
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *edit_pName;
    QLabel *label_4;
    QLineEdit *edit_step;
    QLabel *label_2;
    QComboBox *box_face;
    QLabel *label_3;
    QComboBox *box_machine;
    QLabel *label_7;
    QComboBox *box_q;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *pb_im;
    QPushButton *pb_ex;
    QPushButton *pb_yes;
    QPushButton *pb_cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *info)
    {
        if (info->objectName().isEmpty())
            info->setObjectName(QStringLiteral("info"));
        info->resize(657, 467);
        gridLayout_2 = new QGridLayout(info);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableWidget = new QTableWidget(info);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout_2->addWidget(tableWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(info);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(9);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        edit_pName = new QLineEdit(info);
        edit_pName->setObjectName(QStringLiteral("edit_pName"));

        gridLayout->addWidget(edit_pName, 0, 1, 1, 1);

        label_4 = new QLabel(info);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        edit_step = new QLineEdit(info);
        edit_step->setObjectName(QStringLiteral("edit_step"));

        gridLayout->addWidget(edit_step, 1, 1, 1, 1);

        label_2 = new QLabel(info);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        box_face = new QComboBox(info);
        box_face->addItem(QString());
        box_face->addItem(QString());
        box_face->setObjectName(QStringLiteral("box_face"));

        gridLayout->addWidget(box_face, 2, 1, 1, 1);

        label_3 = new QLabel(info);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        box_machine = new QComboBox(info);
        box_machine->addItem(QString());
        box_machine->addItem(QString());
        box_machine->setObjectName(QStringLiteral("box_machine"));

        gridLayout->addWidget(box_machine, 3, 1, 1, 1);

        label_7 = new QLabel(info);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        box_q = new QComboBox(info);
        box_q->addItem(QString());
        box_q->addItem(QString());
        box_q->setObjectName(QStringLiteral("box_q"));

        gridLayout->addWidget(box_q, 4, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pb_im = new QPushButton(info);
        pb_im->setObjectName(QStringLiteral("pb_im"));

        verticalLayout->addWidget(pb_im);

        pb_ex = new QPushButton(info);
        pb_ex->setObjectName(QStringLiteral("pb_ex"));

        verticalLayout->addWidget(pb_ex);

        pb_yes = new QPushButton(info);
        pb_yes->setObjectName(QStringLiteral("pb_yes"));

        verticalLayout->addWidget(pb_yes);

        pb_cancel = new QPushButton(info);
        pb_cancel->setObjectName(QStringLiteral("pb_cancel"));

        verticalLayout->addWidget(pb_cancel);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(info);

        QMetaObject::connectSlotsByName(info);
    } // setupUi

    void retranslateUi(QDialog *info)
    {
        info->setWindowTitle(QApplication::translate("info", "Dialog", nullptr));
        label->setText(QApplication::translate("info", "\347\250\213\345\272\217\345\220\215", nullptr));
        label_4->setText(QApplication::translate("info", "\346\255\245\351\225\277", nullptr));
        label_2->setText(QApplication::translate("info", "\345\207\271\345\207\270\351\235\242", nullptr));
        box_face->setItemText(0, QApplication::translate("info", "\345\207\271\351\235\242", nullptr));
        box_face->setItemText(1, QApplication::translate("info", "\345\207\270\351\235\242", nullptr));

        label_3->setText(QApplication::translate("info", "\346\234\272\345\236\213", nullptr));
        box_machine->setItemText(0, QApplication::translate("info", "LGS-200", nullptr));
        box_machine->setItemText(1, QApplication::translate("info", "LGS-300", nullptr));

        label_7->setText(QApplication::translate("info", "\350\256\241\347\256\227\345\217\243\345\276\204", nullptr));
        box_q->setItemText(0, QApplication::translate("info", "\345\215\212\345\217\243\345\276\204", nullptr));
        box_q->setItemText(1, QApplication::translate("info", "\345\205\250\345\217\243\345\276\204", nullptr));

        pb_im->setText(QApplication::translate("info", "\345\257\274\345\205\245", nullptr));
        pb_ex->setText(QApplication::translate("info", "\345\257\274\345\207\272", nullptr));
        pb_yes->setText(QApplication::translate("info", "\347\241\256\350\256\244", nullptr));
        pb_cancel->setText(QApplication::translate("info", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class info: public Ui_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
