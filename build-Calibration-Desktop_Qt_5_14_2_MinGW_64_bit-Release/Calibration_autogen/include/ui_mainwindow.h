/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QListWidget *listWidget;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QGroupBox *verticalGroupBox_5;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_4;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_8;
    QSpinBox *spinBox;
    QLabel *label_7;
    QRadioButton *radioButton_2;
    QSpinBox *spinBox_2;
    QDoubleSpinBox *doubleSpinBox;
    QRadioButton *radioButton_4;
    QLabel *label_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton;
    QRadioButton *radioButton_5;
    QPushButton *pushButton_5;
    QGroupBox *verticalGroupBox_4;
    QGridLayout *gridLayout_2;
    QLabel *label_11;
    QLabel *label_15;
    QLabel *label_23;
    QLineEdit *lineEdit;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_22;
    QPushButton *pushButton_4;
    QLabel *label_14;
    QLabel *label_16;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_7;
    QDoubleSpinBox *doubleSpinBox_2;
    QCheckBox *checkBox_5;
    QLabel *label_17;
    QLabel *label_13;
    QCheckBox *checkBox_9;
    QDoubleSpinBox *doubleSpinBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_3;
    QSpinBox *spinBox_5;
    QLabel *label_21;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_3;
    QButtonGroup *buttonGroup_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(930, 780);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(253, 246, 227);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setEnabled(true);
        textBrowser->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";"));

        verticalLayout_5->addWidget(textBrowser);


        gridLayout->addLayout(verticalLayout_5, 15, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(0, 50));
        label_9->setMaximumSize(QSize(16777215, 16777215));
        label_9->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Segoe UI\";\n"
"spacing: 5px;\n"
"color: rgb(97,97,97);\n"
"background-color: rgb(243, 236, 218);"));

        verticalLayout_3->addWidget(label_9);


        gridLayout->addLayout(verticalLayout_3, 6, 1, 1, 1);

        horizontalWidget = new QWidget(centralwidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy1);
        horizontalWidget->setMinimumSize(QSize(0, 50));
        horizontalWidget->setMaximumSize(QSize(16777215, 70));
        horizontalWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 236, 218);"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_6 = new QPushButton(horizontalWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy2);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	font: 14pt \"Microsoft YaHei UI\";\n"
"	border-radius: 3px;\n"
"	background-color: rgb(172, 157, 87);\n"
"	color:rgb(246,245,237); \n"
"} \n"
"QPushButton:hover { \n"
"background-color: rgb(139,126,68); \n"
"}\n"
"QPushButton:pressed {  \n"
"\n"
"    /* \346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274 */  \n"
"    border-style:inset;  \n"
"\n"
"    /* \344\275\277\346\226\207\345\255\227\346\234\211\344\270\200\347\202\271\347\247\273\345\212\250 */  \n"
"    padding-left:3px;  \n"
"    padding-top:3px;  \n"
"}  "));

        horizontalLayout->addWidget(pushButton_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(horizontalWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMaximumSize(QSize(100, 50));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	font: 14pt \"Microsoft YaHei UI\";\n"
"	border-radius: 3px;\n"
"	background-color: rgb(172, 157, 87);\n"
"	color:rgb(246,245,237); \n"
"} \n"
"QPushButton:hover { \n"
"background-color: rgb(139,126,68); \n"
"}\n"
"QPushButton:pressed {  \n"
"\n"
"    /* \346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274 */  \n"
"    border-style:inset;  \n"
"\n"
"    /* \344\275\277\346\226\207\345\255\227\346\234\211\344\270\200\347\202\271\347\247\273\345\212\250 */  \n"
"    padding-left:3px;  \n"
"    padding-top:3px;  \n"
"}  "));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_3 = new QPushButton(horizontalWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        pushButton_3->setMaximumSize(QSize(100, 50));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	font: 14pt \"Microsoft YaHei UI\";\n"
"	border-radius: 3px;\n"
"	background-color: rgb(172, 157, 87);\n"
"	color:rgb(246,245,237); \n"
"} \n"
"QPushButton:hover { \n"
"background-color: rgb(139,126,68); \n"
"}\n"
"QPushButton:pressed {  \n"
"\n"
"    /* \346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274 */  \n"
"    border-style:inset;  \n"
"\n"
"    /* \344\275\277\346\226\207\345\255\227\346\234\211\344\270\200\347\202\271\347\247\273\345\212\250 */  \n"
"    padding-left:3px;  \n"
"    padding-top:3px;  \n"
"}  "));

        horizontalLayout->addWidget(pushButton_3);


        gridLayout->addWidget(horizontalWidget, 21, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setMinimumSize(QSize(380, 0));
        label_3->setMaximumSize(QSize(380, 50));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(97,97,97);\n"
"background-color: rgb(243, 236, 218);"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);
        label_8->setMaximumSize(QSize(16777215, 50));
        label_8->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Segoe UI\";\n"
"spacing: 5px;\n"
"color: rgb(97,97,97);\n"
"background-color: rgb(243, 236, 218);"));

        verticalLayout_2->addWidget(label_8);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setEnabled(true);
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(216,212,196);\n"
""));

        gridLayout->addWidget(listWidget, 4, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 15, 2, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(true);
        sizePolicy3.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy3);
        pushButton_2->setMaximumSize(QSize(385, 50));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	font: 14pt \"Microsoft YaHei UI\";\n"
"	border-radius: 3px;\n"
"	background-color: #4CAF50;; \n"
"    color: white; \n"
"    border: none;\n"
"} \n"
"QPushButton:hover { \n"
"	/*background-color: rgb(139,126,68); */\n"
"	background-color: #3e8e41;\n"
"    color: white;\n"
"	\n"
"}\n"
"\n"
"QPushButton:pressed {  \n"
"\n"
"    /* \346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274 */  \n"
"    border-style:inset;  \n"
"\n"
"    /* \344\275\277\346\226\207\345\255\227\346\234\211\344\270\200\347\202\271\347\247\273\345\212\250 */  \n"
"    padding-left:3px;  \n"
"    padding-top:3px;  \n"
"}  \n"
"QPushButton:disabled {\n"
"	border: 2px solid #f44336;\n"
"	 background-color: #f44336;\n"
"     color: white;\n"
"	 opacity: 0.9;\n"
"}"));

        gridLayout->addWidget(pushButton_2, 21, 0, 1, 1);

        verticalGroupBox_5 = new QGroupBox(centralwidget);
        verticalGroupBox_5->setObjectName(QString::fromUtf8("verticalGroupBox_5"));
        verticalGroupBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(216,212,196);"));
        gridLayout_4 = new QGridLayout(verticalGroupBox_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_2 = new QLabel(verticalGroupBox_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMaximumSize(QSize(125, 35));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(verticalGroupBox_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);
        label->setMaximumSize(QSize(16777215, 125));
        label->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_4->addWidget(label, 3, 0, 1, 1);

        label_6 = new QLabel(verticalGroupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_4->addWidget(label_6, 7, 0, 1, 1);

        label_4 = new QLabel(verticalGroupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy5.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy5);
        label_4->setMaximumSize(QSize(125, 16777215));
        label_4->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_4->addWidget(label_4, 5, 0, 1, 1);

        radioButton_3 = new QRadioButton(verticalGroupBox_5);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(radioButton_3);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setStyleSheet(QString::fromUtf8("/*RadioButton\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QRadioButton::indicator { \n"
"    width: 17px;\n"
"    height: 17px;\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\346\234\252\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::unchecked {\n"
"	image: url(:/ico/uiComponents/radiounchecked.png);\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::checked { \n"
"	image: url(:/ico/uiComponents/radiochecked.png);\n"
"}\n"
"/*RadioButton\345\222\214checkbox\345\255\227\344\275\223\345\222\214\351\227\264\350\267\235\350\256\276\347\275\256*/\n"
"QRadioButton ,QCheckBox{\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"    spacing: 5px;\n"
"}\n"
""));

        gridLayout_4->addWidget(radioButton_3, 5, 4, 1, 1);

        radioButton_8 = new QRadioButton(verticalGroupBox_5);
        buttonGroup_2->addButton(radioButton_8);
        radioButton_8->setObjectName(QString::fromUtf8("radioButton_8"));
        radioButton_8->setStyleSheet(QString::fromUtf8("/*RadioButton\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QRadioButton::indicator { \n"
"    width: 17px;\n"
"    height: 17px;\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\346\234\252\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::unchecked {\n"
"	image: url(:/ico/uiComponents/radiounchecked.png);\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::checked { \n"
"	image: url(:/ico/uiComponents/radiochecked.png);\n"
"}\n"
"/*RadioButton\345\222\214checkbox\345\255\227\344\275\223\345\222\214\351\227\264\350\267\235\350\256\276\347\275\256*/\n"
"QRadioButton ,QCheckBox{\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"    spacing: 5px;\n"
"}\n"
""));

        gridLayout_4->addWidget(radioButton_8, 5, 6, 1, 1);

        spinBox = new QSpinBox(verticalGroupBox_5);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMaximumSize(QSize(50, 20));
        spinBox->setCursor(QCursor(Qt::IBeamCursor));
        spinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	padding-right: 15px; /* make room for the arrows */\n"
"	border:1px solid black;\n"
"	border-radius:5px;\n"
"	background-color: rgb(238, 232, 213);\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"	image: url(:/ico/uiComponents/upArr.png);\n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"	image: url(:/ico/uiComponents/downArr.png);\n"
"}\n"
"\n"
"QSpinBox::up-button:pressed {\n"
"	image: url(:/ico/uiComponents/upArrPressed.png);\n"
"	margin-top:3px;\n"
"}\n"
"\n"
"QSpinBox::down-button:pressed {\n"
"	image: url(:/ico/uiComponents/downArrPressed.png);\n"
"	margin-bottom:3px;\n"
"}"));

        gridLayout_4->addWidget(spinBox, 7, 4, 1, 1);

        label_7 = new QLabel(verticalGroupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_4->addWidget(label_7, 8, 0, 1, 1);

        radioButton_2 = new QRadioButton(verticalGroupBox_5);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy6);
        radioButton_2->setStyleSheet(QString::fromUtf8("/*RadioButton\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QRadioButton::indicator { \n"
"    width: 17px;\n"
"    height: 17px;\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\346\234\252\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::unchecked {\n"
"	image: url(:/ico/uiComponents/radiounchecked.png);\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::checked { \n"
"	image: url(:/ico/uiComponents/radiochecked.png);\n"
"}\n"
"/*RadioButton\345\222\214checkbox\345\255\227\344\275\223\345\222\214\351\227\264\350\267\235\350\256\276\347\275\256*/\n"
"QRadioButton ,QCheckBox{\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"    spacing: 5px;\n"
"}\n"
""));

        gridLayout_4->addWidget(radioButton_2, 3, 4, 1, 1);

        spinBox_2 = new QSpinBox(verticalGroupBox_5);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        QSizePolicy sizePolicy7(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy7);
        spinBox_2->setMaximumSize(QSize(50, 20));
        spinBox_2->setCursor(QCursor(Qt::IBeamCursor));
        spinBox_2->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	padding-right: 15px; /* make room for the arrows */\n"
"	border:1px solid black;\n"
"	border-radius:5px;\n"
"	background-color: rgb(238, 232, 213);\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"	image: url(:/ico/uiComponents/upArr.png);\n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"	image: url(:/ico/uiComponents/downArr.png);\n"
"}\n"
"\n"
"QSpinBox::up-button:pressed {\n"
"	image: url(:/ico/uiComponents/upArrPressed.png);\n"
"	margin-top:3px;\n"
"}\n"
"\n"
"QSpinBox::down-button:pressed {\n"
"	image: url(:/ico/uiComponents/downArrPressed.png);\n"
"	margin-bottom:3px;\n"
"}"));

        gridLayout_4->addWidget(spinBox_2, 6, 4, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(verticalGroupBox_5);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        sizePolicy4.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy4);
        doubleSpinBox->setMaximumSize(QSize(75, 20));
        doubleSpinBox->setCursor(QCursor(Qt::IBeamCursor));
        doubleSpinBox->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"padding-right: 15px; /* make room for the arrows */\n"
"border:1px solid black;\n"
"border-radius:5px;\n"
"background-color: rgb(238, 232, 213);\n"
"font: 10pt \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"	image: url(:/ico/uiComponents/upArr.png);\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button {\n"
"	image: url(:/ico/uiComponents/downArr.png);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button:pressed {\n"
"	image: url(:/ico/uiComponents/upArrPressed.png);\n"
"	margin-top:3px;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button:pressed {\n"
"	image: url(:/ico/uiComponents/downArrPressed.png);\n"
"	margin-bottom:3px;\n"
"}"));

        gridLayout_4->addWidget(doubleSpinBox, 8, 4, 1, 1);

        radioButton_4 = new QRadioButton(verticalGroupBox_5);
        buttonGroup_2->addButton(radioButton_4);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setStyleSheet(QString::fromUtf8("/*RadioButton\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QRadioButton::indicator { \n"
"    width: 17px;\n"
"    height: 17px;\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\346\234\252\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::unchecked {\n"
"	image: url(:/ico/uiComponents/radiounchecked.png);\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::checked { \n"
"	image: url(:/ico/uiComponents/radiochecked.png);\n"
"}\n"
"/*RadioButton\345\222\214checkbox\345\255\227\344\275\223\345\222\214\351\227\264\350\267\235\350\256\276\347\275\256*/\n"
"QRadioButton ,QCheckBox{\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"    spacing: 5px;\n"
"}\n"
""));

        gridLayout_4->addWidget(radioButton_4, 5, 5, 1, 1);

        label_5 = new QLabel(verticalGroupBox_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy5.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy5);
        label_5->setMaximumSize(QSize(125, 16777215));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_4->addWidget(label_5, 6, 0, 1, 1);

        radioButton_6 = new QRadioButton(verticalGroupBox_5);
        buttonGroup->addButton(radioButton_6);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setStyleSheet(QString::fromUtf8("/*RadioButton\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QRadioButton::indicator { \n"
"    width: 17px;\n"
"    height: 17px;\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\346\234\252\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::unchecked {\n"
"	image: url(:/ico/uiComponents/radiounchecked.png);\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::checked { \n"
"	image: url(:/ico/uiComponents/radiochecked.png);\n"
"}\n"
"/*RadioButton\345\222\214checkbox\345\255\227\344\275\223\345\222\214\351\227\264\350\267\235\350\256\276\347\275\256*/\n"
"QRadioButton ,QCheckBox{\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"    spacing: 5px;\n"
"}\n"
""));

        gridLayout_4->addWidget(radioButton_6, 3, 6, 1, 1);

        radioButton = new QRadioButton(verticalGroupBox_5);
        buttonGroup_3 = new QButtonGroup(MainWindow);
        buttonGroup_3->setObjectName(QString::fromUtf8("buttonGroup_3"));
        buttonGroup_3->addButton(radioButton);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        QSizePolicy sizePolicy8(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy8);
        radioButton->setMaximumSize(QSize(200, 16777215));
        radioButton->setStyleSheet(QString::fromUtf8("/*RadioButton\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QRadioButton::indicator { \n"
"    width: 17px;\n"
"    height: 17px;\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\346\234\252\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::unchecked {\n"
"	image: url(:/ico/uiComponents/radiounchecked.png);\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::checked { \n"
"	image: url(:/ico/uiComponents/radiochecked.png);\n"
"}\n"
"/*RadioButton\345\222\214checkbox\345\255\227\344\275\223\345\222\214\351\227\264\350\267\235\350\256\276\347\275\256*/\n"
"QRadioButton ,QCheckBox{\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"    spacing: 5px;\n"
"}\n"
""));
        radioButton->setCheckable(true);
        radioButton->setChecked(false);

        gridLayout_4->addWidget(radioButton, 0, 4, 1, 1);

        radioButton_5 = new QRadioButton(verticalGroupBox_5);
        buttonGroup->addButton(radioButton_5);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setStyleSheet(QString::fromUtf8("/*RadioButton\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QRadioButton::indicator { \n"
"    width: 17px;\n"
"    height: 17px;\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\346\234\252\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::unchecked {\n"
"	image: url(:/ico/uiComponents/radiounchecked.png);\n"
"}\n"
"/*\345\215\225\351\200\211\346\241\206\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"QRadioButton::indicator::checked { \n"
"	image: url(:/ico/uiComponents/radiochecked.png);\n"
"}\n"
"/*RadioButton\345\222\214checkbox\345\255\227\344\275\223\345\222\214\351\227\264\350\267\235\350\256\276\347\275\256*/\n"
"QRadioButton ,QCheckBox{\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"    spacing: 5px;\n"
"}\n"
""));
        radioButton_5->setCheckable(true);
        radioButton_5->setChecked(false);

        gridLayout_4->addWidget(radioButton_5, 3, 5, 1, 1);


        gridLayout->addWidget(verticalGroupBox_5, 4, 1, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setEnabled(true);
        QSizePolicy sizePolicy9(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy9);
        pushButton_5->setMaximumSize(QSize(385, 50));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	font: 14pt \"Microsoft YaHei UI\";\n"
"	border-radius: 3px;\n"
"	background-color: #4CAF50;; \n"
"    color: white; \n"
"    border: none;\n"
"} \n"
"QPushButton:hover { \n"
"	/*background-color: rgb(139,126,68); */\n"
"	background-color: #3e8e41;\n"
"    color: white;\n"
"	\n"
"}\n"
"\n"
"QPushButton:pressed {  \n"
"\n"
"    /* \346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274 */  \n"
"    border-style:inset;  \n"
"\n"
"    /* \344\275\277\346\226\207\345\255\227\346\234\211\344\270\200\347\202\271\347\247\273\345\212\250 */  \n"
"    padding-left:3px;  \n"
"    padding-top:3px;  \n"
"}  \n"
"QPushButton:disabled {\n"
"	border: 2px solid #f44336;\n"
"	 background-color: #f44336;\n"
"     color: white;\n"
"	 opacity: 0.9;\n"
"}"));

        gridLayout->addWidget(pushButton_5, 6, 0, 1, 1);

        verticalGroupBox_4 = new QGroupBox(centralwidget);
        verticalGroupBox_4->setObjectName(QString::fromUtf8("verticalGroupBox_4"));
        verticalGroupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(216,212,196);"));
        gridLayout_2 = new QGridLayout(verticalGroupBox_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_11 = new QLabel(verticalGroupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QSizePolicy sizePolicy10(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy10);
        label_11->setMaximumSize(QSize(16777215, 16777215));
        label_11->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        label_15 = new QLabel(verticalGroupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_2->addWidget(label_15, 7, 0, 1, 1);

        label_23 = new QLabel(verticalGroupBox_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_2->addWidget(label_23, 3, 0, 1, 1);

        lineEdit = new QLineEdit(verticalGroupBox_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy10.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy10);
        lineEdit->setMaximumSize(QSize(200, 16777215));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 232, 213);\n"
"font: 9pt \"Consolas\";"));

        gridLayout_2->addWidget(lineEdit, 0, 2, 1, 1);

        label_18 = new QLabel(verticalGroupBox_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_2->addWidget(label_18, 10, 0, 1, 1);

        label_19 = new QLabel(verticalGroupBox_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_2->addWidget(label_19, 11, 0, 1, 1);

        label_22 = new QLabel(verticalGroupBox_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_2->addWidget(label_22, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(verticalGroupBox_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);
        pushButton_4->setMaximumSize(QSize(75, 25));
        pushButton_4->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	border-radius: 3px;\n"
"	background-color: rgb(172, 157, 87);\n"
"	color:rgb(246,245,237); \n"
"} \n"
"QPushButton:hover { \n"
"	background-color: rgb(139,126,68); \n"
"}\n"
"QPushButton:pressed {  \n"
"\n"
"    /* \346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274 */  \n"
"    border-style:inset;  \n"
"\n"
"    /* \344\275\277\346\226\207\345\255\227\346\234\211\344\270\200\347\202\271\347\247\273\345\212\250 */  \n"
"    padding-left:3px;  \n"
"    padding-top:3px;  \n"
"}  \n"
""));
        pushButton_4->setCheckable(false);
        pushButton_4->setAutoDefault(false);

        gridLayout_2->addWidget(pushButton_4, 0, 3, 1, 1);

        label_14 = new QLabel(verticalGroupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_2->addWidget(label_14, 6, 0, 1, 1);

        label_16 = new QLabel(verticalGroupBox_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        QSizePolicy sizePolicy11(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy11);
        label_16->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_2->addWidget(label_16, 8, 0, 1, 1);

        checkBox_2 = new QCheckBox(verticalGroupBox_4);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setMaximumSize(QSize(16777215, 15));
        checkBox_2->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    spacing: 5px;\n"
"    font-size: 15px;\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"}\n"
"/*checkbox\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QCheckBox::indicator { \n"
"    width: 26px;\n"
"    height: 50px;\n"
"}\n"
"/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/ico/uiComponents/unchecked.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/ico/uiComponents/checked.png);\n"
"}"));

        gridLayout_2->addWidget(checkBox_2, 4, 2, 1, 1);

        checkBox_8 = new QCheckBox(verticalGroupBox_4);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setMaximumSize(QSize(16777215, 15));
        checkBox_8->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    spacing: 5px;\n"
"    font-size: 15px;\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"}\n"
"/*checkbox\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QCheckBox::indicator { \n"
"    width: 26px;\n"
"    height: 50px;\n"
"}\n"
"/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/ico/uiComponents/unchecked.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/ico/uiComponents/checked.png);\n"
"}"));

        gridLayout_2->addWidget(checkBox_8, 11, 2, 1, 1);

        checkBox_7 = new QCheckBox(verticalGroupBox_4);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setMaximumSize(QSize(16777215, 15));
        checkBox_7->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    spacing: 5px;\n"
"    font-size: 15px;\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"}\n"
"/*checkbox\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QCheckBox::indicator { \n"
"    width: 26px;\n"
"    height: 50px;\n"
"}\n"
"/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/ico/uiComponents/unchecked.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/ico/uiComponents/checked.png);\n"
"}"));

        gridLayout_2->addWidget(checkBox_7, 10, 2, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(verticalGroupBox_4);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setMaximumSize(QSize(75, 16777215));
        doubleSpinBox_2->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"padding-right: 15px; /* make room for the arrows */\n"
"border:1px solid black;\n"
"border-radius:5px;\n"
"background-color: rgb(238, 232, 213);\n"
"font: 10pt \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"	image: url(:/ico/uiComponents/upArr.png);\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button {\n"
"	image: url(:/ico/uiComponents/downArr.png);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button:pressed {\n"
"	image: url(:/ico/uiComponents/upArrPressed.png);\n"
"	margin-top:3px;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button:pressed {\n"
"	image: url(:/ico/uiComponents/downArrPressed.png);\n"
"	margin-bottom:3px;\n"
"}"));

        gridLayout_2->addWidget(doubleSpinBox_2, 9, 2, 1, 1);

        checkBox_5 = new QCheckBox(verticalGroupBox_4);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setMaximumSize(QSize(16777215, 15));
        checkBox_5->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    spacing: 5px;\n"
"    font-size: 15px;\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"}\n"
"/*checkbox\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QCheckBox::indicator { \n"
"    width: 26px;\n"
"    height: 50px;\n"
"}\n"
"/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/ico/uiComponents/unchecked.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/ico/uiComponents/checked.png);\n"
"}"));

        gridLayout_2->addWidget(checkBox_5, 8, 2, 1, 1);

        label_17 = new QLabel(verticalGroupBox_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_2->addWidget(label_17, 9, 0, 1, 1);

        label_13 = new QLabel(verticalGroupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_2->addWidget(label_13, 4, 0, 1, 1);

        checkBox_9 = new QCheckBox(verticalGroupBox_4);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setMaximumSize(QSize(16777215, 15));
        checkBox_9->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    spacing: 5px;\n"
"    font-size: 15px;\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"}\n"
"/*checkbox\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QCheckBox::indicator { \n"
"    width: 26px;\n"
"    height: 50px;\n"
"}\n"
"/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/ico/uiComponents/unchecked.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/ico/uiComponents/checked.png);\n"
"}"));

        gridLayout_2->addWidget(checkBox_9, 12, 2, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(verticalGroupBox_4);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setMaximumSize(QSize(75, 16777215));
        doubleSpinBox_3->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"padding-right: 15px; /* make room for the arrows */\n"
"border:1px solid black;\n"
"border-radius:5px;\n"
"background-color: rgb(238, 232, 213);\n"
"font: 10pt \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button {\n"
"	image: url(:/ico/uiComponents/upArr.png);\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button {\n"
"	image: url(:/ico/uiComponents/downArr.png);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button:pressed {\n"
"	image: url(:/ico/uiComponents/upArrPressed.png);\n"
"	margin-top:3px;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button:pressed {\n"
"	image: url(:/ico/uiComponents/downArrPressed.png);\n"
"	margin-bottom:3px;\n"
"}"));

        gridLayout_2->addWidget(doubleSpinBox_3, 3, 2, 1, 1);

        checkBox_4 = new QCheckBox(verticalGroupBox_4);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setMaximumSize(QSize(16777215, 15));
        checkBox_4->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    spacing: 5px;\n"
"    font-size: 15px;\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"}\n"
"/*checkbox\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QCheckBox::indicator { \n"
"    width: 26px;\n"
"    height: 50px;\n"
"}\n"
"/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/ico/uiComponents/unchecked.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/ico/uiComponents/checked.png);\n"
"}"));

        gridLayout_2->addWidget(checkBox_4, 7, 2, 1, 1);

        checkBox_3 = new QCheckBox(verticalGroupBox_4);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setMaximumSize(QSize(16777215, 15));
        checkBox_3->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    spacing: 5px;\n"
"    font-size: 15px;\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"	color: rgb(150,148,141);\n"
"}\n"
"/*checkbox\346\240\267\345\274\217\350\256\276\347\275\256*/\n"
"QCheckBox::indicator { \n"
"    width: 26px;\n"
"    height: 50px;\n"
"}\n"
"/*\346\234\252\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::unchecked {   \n"
"    image: url(:/ico/uiComponents/unchecked.png);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QCheckBox::indicator::checked { \n"
"    image: url(:/ico/uiComponents/checked.png);\n"
"}"));

        gridLayout_2->addWidget(checkBox_3, 6, 2, 1, 1);

        spinBox_5 = new QSpinBox(verticalGroupBox_4);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setMaximumSize(QSize(50, 16777215));
        spinBox_5->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	padding-right: 15px; /* make room for the arrows */\n"
"	border:1px solid black;\n"
"	border-radius:5px;\n"
"	background-color: rgb(238, 232, 213);\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"	image: url(:/ico/uiComponents/upArr.png);\n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"	image: url(:/ico/uiComponents/downArr.png);\n"
"}\n"
"\n"
"QSpinBox::up-button:pressed {\n"
"	image: url(:/ico/uiComponents/upArrPressed.png);\n"
"	margin-top:3px;\n"
"}\n"
"\n"
"QSpinBox::down-button:pressed {\n"
"	image: url(:/ico/uiComponents/downArrPressed.png);\n"
"	margin-bottom:3px;\n"
"}"));

        gridLayout_2->addWidget(spinBox_5, 2, 2, 1, 1);

        label_21 = new QLabel(verticalGroupBox_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Microsoft YaHei UI\";\n"
"color: rgb(150,148,141);\n"
"background-color: rgb(216,212,196);"));

        gridLayout_2->addWidget(label_21, 12, 0, 1, 1);


        gridLayout->addWidget(verticalGroupBox_4, 15, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 930, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        textBrowser->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_9->setText(QCoreApplication::translate("MainWindow", "Advanced Calibrate Settings", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "ENG/\344\270\255", nullptr));
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Reset all parameters above</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_3->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Exit program</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Images Output                                                      ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Basic Settings", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Start calibrate</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Calibrate", nullptr));
#if QT_CONFIG(tooltip)
        verticalGroupBox_5->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_2->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_2->setText(QCoreApplication::translate("MainWindow", "Picture Source", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Select the resolution of pictures</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("MainWindow", "Resolution", nullptr));
#if QT_CONFIG(tooltip)
        label_6->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("MainWindow", "Board Height", nullptr));
#if QT_CONFIG(tooltip)
        label_4->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Choose a calibrate pattern</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_4->setText(QCoreApplication::translate("MainWindow", "Calibrate Patterns", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Chessboard", nullptr));
        radioButton_8->setText(QCoreApplication::translate("MainWindow", "Asymmetrice Circle Grid", nullptr));
#if QT_CONFIG(tooltip)
        spinBox->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Heigh of a chessboard or a circle grid</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_7->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_7->setText(QCoreApplication::translate("MainWindow", "Board Size", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "320*240", nullptr));
#if QT_CONFIG(tooltip)
        spinBox_2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Width of a chessboard or a circle grid</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        doubleSpinBox->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Size of a square or a circle</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "Circles Grid", nullptr));
#if QT_CONFIG(tooltip)
        label_5->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("MainWindow", "Board Width", nullptr));
        radioButton_6->setText(QCoreApplication::translate("MainWindow", "1280*720", nullptr));
#if QT_CONFIG(tooltip)
        radioButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Calibrate a camera from local picture files.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        radioButton->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        radioButton->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        radioButton->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        radioButton->setText(QCoreApplication::translate("MainWindow", "Image Files ", nullptr));
        radioButton_5->setText(QCoreApplication::translate("MainWindow", "640*480", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_5->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Add to Imagelist.yaml", nullptr));
#if QT_CONFIG(tooltip)
        verticalGroupBox_4->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_11->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_11->setText(QCoreApplication::translate("MainWindow", "Calibrate File Output", nullptr));
#if QT_CONFIG(tooltip)
        label_15->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_15->setText(QCoreApplication::translate("MainWindow", "Write Refined 3D Object Points", nullptr));
#if QT_CONFIG(tooltip)
        label_23->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_23->setText(QCoreApplication::translate("MainWindow", "Distance", nullptr));
#if QT_CONFIG(tooltip)
        label_18->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_18->setText(QCoreApplication::translate("MainWindow", "Fix the Principal Point", nullptr));
#if QT_CONFIG(tooltip)
        label_19->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_19->setText(QCoreApplication::translate("MainWindow", "Flip the Captured Images", nullptr));
#if QT_CONFIG(tooltip)
        label_22->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_22->setText(QCoreApplication::translate("MainWindow", "Window Size", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_4->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
#if QT_CONFIG(tooltip)
        label_14->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_14->setText(QCoreApplication::translate("MainWindow", "Write Extrinsic Parameters", nullptr));
#if QT_CONFIG(tooltip)
        label_16->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_16->setText(QCoreApplication::translate("MainWindow", "Assume Zero Tangential Distortion", nullptr));
        checkBox_2->setText(QString());
        checkBox_8->setText(QString());
        checkBox_7->setText(QString());
        checkBox_5->setText(QString());
#if QT_CONFIG(tooltip)
        label_17->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_17->setText(QCoreApplication::translate("MainWindow", "Fix Aspect Ratio(fx/fy)", nullptr));
#if QT_CONFIG(tooltip)
        label_13->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_13->setText(QCoreApplication::translate("MainWindow", "Write Detected Feature Points", nullptr));
        checkBox_9->setText(QString());
        checkBox_4->setText(QString());
        checkBox_3->setText(QString());
#if QT_CONFIG(tooltip)
        label_21->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_21->setText(QCoreApplication::translate("MainWindow", "Show Undistorted Images", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
