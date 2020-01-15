/********************************************************************************
** Form generated from reading UI file 'fitdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FITDIALOG_H
#define UI_FITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_fitDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *left;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *right;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *step;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *file;
    QPushButton *open;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *yes;
    QPushButton *cancel;

    void setupUi(QDialog *fitDialog)
    {
        if (fitDialog->objectName().isEmpty())
            fitDialog->setObjectName(QStringLiteral("fitDialog"));
        fitDialog->resize(280, 169);
        gridLayout = new QGridLayout(fitDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(fitDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        left = new QLineEdit(fitDialog);
        left->setObjectName(QStringLiteral("left"));

        horizontalLayout->addWidget(left);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(fitDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        right = new QLineEdit(fitDialog);
        right->setObjectName(QStringLiteral("right"));

        horizontalLayout_2->addWidget(right);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(fitDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        step = new QLineEdit(fitDialog);
        step->setObjectName(QStringLiteral("step"));

        horizontalLayout_3->addWidget(step);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(fitDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        file = new QLineEdit(fitDialog);
        file->setObjectName(QStringLiteral("file"));

        horizontalLayout_4->addWidget(file);

        open = new QPushButton(fitDialog);
        open->setObjectName(QStringLiteral("open"));

        horizontalLayout_4->addWidget(open);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        yes = new QPushButton(fitDialog);
        yes->setObjectName(QStringLiteral("yes"));

        horizontalLayout_5->addWidget(yes);

        cancel = new QPushButton(fitDialog);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout_5->addWidget(cancel);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(fitDialog);

        QMetaObject::connectSlotsByName(fitDialog);
    } // setupUi

    void retranslateUi(QDialog *fitDialog)
    {
        fitDialog->setWindowTitle(QApplication::translate("fitDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("fitDialog", "\345\267\246\350\276\271\347\225\214", nullptr));
        label_2->setText(QApplication::translate("fitDialog", "\345\217\263\350\276\271\347\225\214", nullptr));
        label_3->setText(QApplication::translate("fitDialog", "\346\255\245  \351\225\277", nullptr));
        label_4->setText(QApplication::translate("fitDialog", "\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
        open->setText(QApplication::translate("fitDialog", "\346\211\223\345\274\200", nullptr));
        yes->setText(QApplication::translate("fitDialog", "\347\241\256\345\256\232", nullptr));
        cancel->setText(QApplication::translate("fitDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fitDialog: public Ui_fitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FITDIALOG_H
