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
        QIcon icon;
        icon.addFile(QStringLiteral(":/F:/OCX/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        info->setWindowIcon(icon);
        info->setStyleSheet(QLatin1String("QPalette{background:#F5F5F5;}QGroupBox#gboxDevicePanel>QLabel{color:#000000;}\n"
"\n"
"QWidget#frmMain,QWidget[Form=\"true\"]{\n"
"border:1px solid #B2B6B9;\n"
"border-radius:0px;\n"
"}\n"
"\n"
".QFrame{\n"
"border:1px solid #B2B6B9;\n"
"border-radius:5px;\n"
"}\n"
"\n"
"QLabel,QLineEdit,QTextEdit,QPlainTextEdit,QSpinBox,QGroupBox,QComboBox,QDateEdit,QTimeEdit,QDateTimeEdit,QSpinBox,QTreeView,QListView,QTableView,QTabWidget::pane{\n"
"color:#000000;\n"
"}\n"
"\n"
"QWidget#widget_title{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #E1E4E6,stop:1 #CCD3D9);\n"
"}\n"
"\n"
"QLabel#lab_Ico,QLabel#lab_Title{\n"
"border-radius:0px;\n"
"color:#000000;\n"
"background-color:rgba(0,0,0,0);\n"
"border-style:none;\n"
"}\n"
"\n"
"QToolButton::menu-indicator{\n"
"image:None;\n"
"}\n"
"\n"
"QToolButton,QWidget#widget_frm>QLabel{\n"
"border-style:none;\n"
"padding:10px;\n"
"color:#000000;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #E1E4E6,stop:1 #CCD3D9);\n"
"}\n"
"\n"
"QToolBut"
                        "ton:hover,QWidget#widget_frm>QLabel:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #F2F3F4,stop:1 #E7E9EB);\n"
"}\n"
"\n"
"QLabel[labVideo=\"true\"]{\n"
"color:#000000;\n"
"border:1px solid #B2B6B9;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #E1E4E6,stop:1 #CCD3D9);\n"
"}\n"
"\n"
"QLabel[labVideo=\"true\"]:focus{\n"
"border:1px solid #FF0000;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #F2F3F4,stop:1 #E7E9EB);\n"
"}\n"
"\n"
"QLineEdit,QTextEdit,QPlainTextEdit,QSpinBox{\n"
"border:1px solid #B2B6B9;\n"
"border-radius:5px;\n"
"padding:2px;\n"
"background:none;\n"
"selection-background-color:#E1E4E6;\n"
"selection-color:#000000;\n"
"}\n"
"\n"
"QLineEdit[echoMode=\"2\"]{\n"
"lineedit-password-character:9679;\n"
"}\n"
"\n"
".QGroupBox{\n"
"border:1px solid #B2B6B9;\n"
"border-radius:5px;\n"
"}\n"
"\n"
".QPushButton{\n"
"border-style:none;\n"
"border:1px solid #B2B6B9;\n"
"color:#000000;\n"
"padding:5px;\n"
"min-height:20px;\n"
"border-r"
                        "adius:5px;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #E1E4E6,stop:1 #CCD3D9);\n"
"}\n"
"\n"
".QPushButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #F2F3F4,stop:1 #E7E9EB);\n"
"}\n"
"\n"
".QPushButton:pressed{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #E1E4E6,stop:1 #CCD3D9);\n"
"}\n"
"\n"
".QPushButton:disabled{\n"
"color:#838383;\n"
"background:#F4F4F4;\n"
"}\n"
"\n"
"QPushButton#btnSplitterH{\n"
"padding:2px;\n"
"min-height:8px;\n"
"}\n"
"\n"
"QPushButton#btnMenu,QPushButton#btnMenu_Min,QPushButton#btnMenu_Max,QPushButton#btnMenu_Close,QPushButton#btnSplitterV,QPushButton#btnSplitterH{\n"
"border-radius:0px;\n"
"color:#000000;\n"
"background-color:rgba(0,0,0,0);\n"
"border-style:none;\n"
"}\n"
"\n"
"QPushButton#btnMenu:hover,QPushButton#btnMenu_Min:hover,QPushButton#btnMenu_Max:hover,QPushButton#btnSplitterV:hover,QPushButton#btnSplitterH:hover{\n"
"background-color:qlineargradient(spread:pad,x1:0,y1:1,x2:0,y2:0,stop:0 r"
                        "gba(25,134,199,0),stop:1 #F2F3F4);\n"
"}\n"
"\n"
"QPushButton#btnMenu_Close:hover{\n"
"background-color:qlineargradient(spread:pad,x1:0,y1:1,x2:0,y2:0,stop:0 rgba(238,0,0,128),stop:1 rgba(238,44,44,255));\n"
"}\n"
"\n"
"QCheckBox{\n"
"color:#000000;\n"
"spacing:2px;\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"width:20px;\n"
"height:20px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked{\n"
"image:url(:/image/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked{\n"
"image:url(:/image/checkbox_checked.png);\n"
"}\n"
"\n"
"QRadioButton{\n"
"color:#000000;\n"
"spacing:2px;\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"width:15px;\n"
"height:15px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"image:url(:/image/radio_normal.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{\n"
"image:url(:/image/radio_selected.png);\n"
"}\n"
"\n"
"QSpinBox::up-button,QDateEdit::up-button,QTimeEdit::up-button,QDateTimeEdit::up-button{\n"
"image:url(:/image/add_top.png);\n"
"}\n"
"\n"
"QSpinBox::down-button,QDateE"
                        "dit::down-button,QTimeEdit::down-button,QDateTimeEdit::down-button{\n"
"image:url(:/image/add_bottom.png);\n"
"}\n"
"\n"
"QComboBox,QDateEdit,QTimeEdit,QDateTimeEdit,QSpinBox{\n"
"border-radius:3px;\n"
"padding:3px 5px 3px 5px;\n"
"border:1px solid #B2B6B9;\n"
"background:none;\n"
"selection-background-color:#E1E4E6;\n"
"selection-color:#000000;\n"
"}\n"
"\n"
"QComboBox::drop-down,QDateEdit::drop-down,QTimeEdit::drop-down,QDateTimeEdit::drop-down{\n"
"subcontrol-origin:padding;\n"
"subcontrol-position:top right;\n"
"width:15px;\n"
"border-left-width:1px;\n"
"border-left-style:solid;\n"
"border-top-right-radius:3px;\n"
"border-bottom-right-radius:3px;\n"
"border-left-color:#B2B6B9;\n"
"}\n"
"\n"
"QComboBox::down-arrow,QDateEdit::down-arrow,QTimeEdit::down-arrow,QDateTimeEdit::down-arrow{\n"
"image:url(:/image/add_bottom.png);\n"
"}\n"
"\n"
"QMenu{\n"
"color:#000000;\n"
"background-color:#E1E4E6;\n"
"margin:2px;\n"
"}\n"
"\n"
"QMenu::item{\n"
"padding:3px 20px 3px 20px;\n"
"}\n"
"\n"
"QMenu::indicator{\n"
"width"
                        ":13px;\n"
"height:13px;\n"
"}\n"
"\n"
"QMenu::item:selected{\n"
"color:#000000;\n"
"border:0px solid #B2B6B9;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #E1E4E6,stop:1 #CCD3D9);\n"
"}\n"
"\n"
"QMenu::separator{\n"
"height:1px;\n"
"background:#B2B6B9;\n"
"}\n"
"\n"
"QProgressBar{\n"
"background:#E1E4E6;\n"
"border-radius:5px;\n"
"text-align:center;\n"
"border:1px solid #B2B6B9;\n"
"}\n"
"\n"
"QProgressBar::chunk{\n"
"width:5px;\n"
"margin:0.5px;\n"
"background-color:#B2B6B9;\n"
"}\n"
"\n"
"QSlider::groove:horizontal,QSlider::add-page:horizontal{\n"
"height:8px;\n"
"border-radius:3px;\n"
"background:#B2B6B9;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal{\n"
"height:8px;\n"
"border-radius:3px;\n"
"background:#787878;\n"
"}\n"
"\n"
"QSlider::handle:horizontal{\n"
"width:13px;\n"
"margin-top:-3px;\n"
"margin-bottom:-3px;\n"
"border-radius:6px;\n"
"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #FFFFFF,stop:0.8 #B2B6B9);\n"
"}\n"
"\n"
"QSlider::groove:ve"
                        "rtical,QSlider::sub-page:vertical{\n"
"width:8px;\n"
"border-radius:3px;\n"
"background:#B2B6B9;\n"
"}\n"
"\n"
"QSlider::add-page:vertical{\n"
"width:8px;\n"
"border-radius:3px;\n"
"background:#787878;\n"
"}\n"
"\n"
"QSlider::handle:vertical{\n"
"height:13px;\n"
"margin-left:-2px;\n"
"margin-right:-3px;\n"
"border-radius:6px;\n"
"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #FFFFFF,stop:0.8 #B2B6B9);\n"
"}\n"
"\n"
"QScrollBar:vertical{\n"
"width:10px;\n"
"background-color:rgba(0,0,0,0%);\n"
"padding-top:10px;\n"
"padding-bottom:10px;\n"
"}\n"
"\n"
"QScrollBar:horizontal{\n"
"height:10px;\n"
"background-color:rgba(0,0,0,0%);\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical,QScrollBar::handle:horizontal{\n"
"width:10px;\n"
"background:#CCD3D9;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover,QScrollBar::handle:horizontal:hover{\n"
"width:10px;\n"
"background:#E7E9EB;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical{\n"
"height:10px;\n"
""
                        "width:10px;\n"
"subcontrol-position:bottom;\n"
"subcontrol-origin:margin;\n"
"border-border-image:url(:/image/add_bottom.png);\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal{\n"
"height:10px;\n"
"width:10px;\n"
"subcontrol-position:right;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_right.png);\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical{\n"
"height:10px;\n"
"width:10px;\n"
"subcontrol-position:top;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_top.png);\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal{\n"
"height:10px;\n"
"width:10px;\n"
"subcontrol-position:left;\n"
"subcontrol-origin:margin;\n"
"image:url(:/image/add_left.png);\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical,QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal{\n"
"width:10px;\n"
"background:#B2B6B9;\n"
"}\n"
"\n"
"QScrollArea{\n"
"border:0px;\n"
"}\n"
"\n"
"QTreeView,QListView,QTableView,QTabWidget::pane{\n"
"border:1px solid #B2B6B9;\n"
"selection-background-color:#F2"
                        "F3F4;\n"
"selection-color:#000000;\n"
"alternate-background-color:#E7E9EB;\n"
"}\n"
"\n"
"QTableView::item:selected,QListView::item:selected,QTreeView::item:selected{\n"
"color:#000000;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #E1E4E6,stop:1 #CCD3D9);\n"
"}\n"
"\n"
"QTableView::item:hover,QListView::item:hover,QTreeView::item:hover{\n"
"color:#000000;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #F2F3F4,stop:1 #E7E9EB);\n"
"}\n"
"\n"
"QTableView::item,QListView::item,QTreeView::item{\n"
"padding:5px;\n"
"margin:0px;\n"
"}\n"
"\n"
"QHeaderView::section,QTableCornerButton:section{\n"
"padding:3px;\n"
"margin:0px;\n"
"color:#000000;\n"
"border:1px solid #B2B6B9;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #F2F3F4,stop:1 #E7E9EB);\n"
"}\n"
"\n"
"QTabBar::tab{\n"
"border-radius:5px;\n"
"border:1px solid #B2B6B9;\n"
"color:#000000;\n"
"min-width:55px;\n"
"min-height:20px;\n"
"padding:3px 8px 3px 8px;\n"
"margin:1px;\n"
"background:qlineargr"
                        "adient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #F2F3F4,stop:1 #E7E9EB);\n"
"}\n"
"\n"
"QTabBar::tab:selected,QTabBar::tab:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #E1E4E6,stop:1 #CCD3D9);\n"
"}\n"
"\n"
"QStatusBar::item{\n"
"border:0px solid #E1E4E6;\n"
"border-radius:3px;\n"
"}\n"
"\n"
"QToolBox::tab,QToolTip,QGroupBox#gboxDevicePanel{\n"
"padding:3px;\n"
"border-radius: 5px;\n"
"color:#000000;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #E1E4E6,stop:1 #CCD3D9);\n"
"}\n"
"\n"
"QToolBox::tab:selected{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #F2F3F4,stop:1 #E7E9EB);\n"
"}\n"
""));
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
