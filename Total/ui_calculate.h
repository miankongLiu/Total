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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_calculate
{
public:
    QGridLayout *gridLayout;
    QPushButton *pb_Yes;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *p_Name;
    QLineEdit *p_r;
    QLineEdit *p_step;
    QLineEdit *p_free;
    QLineEdit *p_face;
    QLineEdit *p_type;
    QLineEdit *p_radius;
    QPushButton *pb_Cancel;

    void setupUi(QDialog *calculate)
    {
        if (calculate->objectName().isEmpty())
            calculate->setObjectName(QStringLiteral("calculate"));
        calculate->resize(241, 255);
        QIcon icon;
        icon.addFile(QStringLiteral(":/F:/OCX/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        calculate->setWindowIcon(icon);
        calculate->setStyleSheet(QLatin1String("QPalette{background:#F5F5F5;}QGroupBox#gboxDevicePanel>QLabel{color:#000000;}\n"
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
        gridLayout = new QGridLayout(calculate);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pb_Yes = new QPushButton(calculate);
        pb_Yes->setObjectName(QStringLiteral("pb_Yes"));

        gridLayout->addWidget(pb_Yes, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(calculate);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(calculate);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(calculate);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(calculate);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(calculate);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(calculate);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(calculate);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        p_Name = new QLineEdit(calculate);
        p_Name->setObjectName(QStringLiteral("p_Name"));

        verticalLayout_2->addWidget(p_Name);

        p_r = new QLineEdit(calculate);
        p_r->setObjectName(QStringLiteral("p_r"));

        verticalLayout_2->addWidget(p_r);

        p_step = new QLineEdit(calculate);
        p_step->setObjectName(QStringLiteral("p_step"));

        verticalLayout_2->addWidget(p_step);

        p_free = new QLineEdit(calculate);
        p_free->setObjectName(QStringLiteral("p_free"));

        verticalLayout_2->addWidget(p_free);

        p_face = new QLineEdit(calculate);
        p_face->setObjectName(QStringLiteral("p_face"));

        verticalLayout_2->addWidget(p_face);

        p_type = new QLineEdit(calculate);
        p_type->setObjectName(QStringLiteral("p_type"));

        verticalLayout_2->addWidget(p_type);

        p_radius = new QLineEdit(calculate);
        p_radius->setObjectName(QStringLiteral("p_radius"));

        verticalLayout_2->addWidget(p_radius);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        pb_Cancel = new QPushButton(calculate);
        pb_Cancel->setObjectName(QStringLiteral("pb_Cancel"));

        gridLayout->addWidget(pb_Cancel, 1, 1, 1, 1);


        retranslateUi(calculate);

        QMetaObject::connectSlotsByName(calculate);
    } // setupUi

    void retranslateUi(QDialog *calculate)
    {
        calculate->setWindowTitle(QApplication::translate("calculate", "Dialog", nullptr));
        pb_Yes->setText(QApplication::translate("calculate", "\347\241\256\350\256\244", nullptr));
        label->setText(QApplication::translate("calculate", "\347\250\213\345\272\217\345\220\215", nullptr));
        label_2->setText(QApplication::translate("calculate", "\346\265\213\345\244\264\345\215\212\345\276\204", nullptr));
        label_3->setText(QApplication::translate("calculate", "\346\265\213\351\207\217\346\255\245\351\225\277", nullptr));
        label_4->setText(QApplication::translate("calculate", "\345\205\215\346\265\213\350\267\235\347\246\273", nullptr));
        label_5->setText(QApplication::translate("calculate", "\345\207\271\345\207\270\351\235\242", nullptr));
        label_6->setText(QApplication::translate("calculate", "\346\234\272\345\236\213", nullptr));
        label_7->setText(QApplication::translate("calculate", "\345\217\243\345\276\204", nullptr));
        pb_Cancel->setText(QApplication::translate("calculate", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calculate: public Ui_calculate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATE_H
