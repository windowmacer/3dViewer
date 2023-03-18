/********************************************************************************
** Form generated from reading UI file 'viewer.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWER_H
#define UI_VIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_viewer
{
public:
    QAction *actionSave_settings;
    QAction *actionSave_as_GIF;
    QAction *actionSave_as_bmp;
    QAction *actionSave_as_jpeg;
    QWidget *centralwidget;
    QWidget *widget;
    QGroupBox *groupBox_2;
    QLabel *label_1;
    QLabel *fileName;
    QLabel *label_9;
    QLabel *numberOfVertices;
    QLabel *label_11;
    QLabel *numberOfEdges;
    QPushButton *pushButton_selectFile;
    QGroupBox *groupBox_moving;
    QLabel *label_moving_x;
    QPushButton *pushButton_moving_x_plus;
    QPushButton *pushButton_moving_x_minus;
    QLabel *label_2;
    QDoubleSpinBox *step;
    QPushButton *pushButton_moving_y_plus;
    QPushButton *pushButton_moving_z_plus;
    QPushButton *pushButton_moving_y_minus;
    QPushButton *pushButton_moving_z_minus;
    QLabel *label_moving_y;
    QLabel *label_moving_z;
    QGroupBox *groupBox_moving_2;
    QLabel *label_moving_x_2;
    QPushButton *pushButton_rotation_x_plus;
    QPushButton *pushButton_rotation_x_minus;
    QLabel *label_3;
    QPushButton *pushButton_rotation_y_plus;
    QPushButton *pushButton_rotation_z_plus;
    QPushButton *pushButton_rotation_y_minus;
    QPushButton *pushButton_rotation_z_minus;
    QLabel *label_moving_y_2;
    QLabel *label_moving_z_2;
    QSpinBox *angle;
    QGroupBox *groupBox_scaling;
    QPushButton *pushButton_scaling_minus;
    QSpinBox *scale;
    QLabel *label_scaling_factor;
    QPushButton *pushButton_scaling_plus;
    QGroupBox *groupBox_7;
    QRadioButton *radioButton_parallel_type;
    QRadioButton *radioButton_central_type;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_background_white;
    QRadioButton *radioButton_background_black;
    QRadioButton *radioButton_background_grey;
    QRadioButton *radioButton_background_green;
    QGroupBox *groupBox;
    QRadioButton *radioButton_edgeType_solid;
    QRadioButton *radioButton_edgeType_dashed;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *edgeThickness;
    QLabel *label;
    QWidget *widget_2;
    QRadioButton *radioButton_edgeColor_white;
    QRadioButton *radioButton_edgeColor_black;
    QRadioButton *radioButton_edgeColor_grey;
    QRadioButton *radioButton_edgeColor_green;
    QGroupBox *groupBox_5;
    QRadioButton *radioButton_vertexType_circle;
    QRadioButton *radioButton_vertexType_square;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *vertexSize;
    QLabel *label_8;
    QRadioButton *radioButton_vertexType_novertex;
    QWidget *widget_3;
    QRadioButton *radioButton_vertexColor_white;
    QRadioButton *radioButton_vertexColor_black;
    QRadioButton *radioButton_vertexColor_grey;
    QRadioButton *radioButton_vertexColor_green;
    QPushButton *testButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *viewer)
    {
        if (viewer->objectName().isEmpty())
            viewer->setObjectName("viewer");
        viewer->resize(1920, 1080);
        actionSave_settings = new QAction(viewer);
        actionSave_settings->setObjectName("actionSave_settings");
        actionSave_as_GIF = new QAction(viewer);
        actionSave_as_GIF->setObjectName("actionSave_as_GIF");
        actionSave_as_bmp = new QAction(viewer);
        actionSave_as_bmp->setObjectName("actionSave_as_bmp");
        actionSave_as_jpeg = new QAction(viewer);
        actionSave_as_jpeg->setObjectName("actionSave_as_jpeg");
        centralwidget = new QWidget(viewer);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 221, 947));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
""));
        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 44, 201, 171));
        groupBox_2->setStyleSheet(QString::fromUtf8("\n"
"	font: 14pt \"Pastelova Demo\";\n"
"	border: 1px solid grey;\n"
"	border-bottom: 1px solid grey;\n"
"	background-color: rgb(246, 245, 244);\n"
"	color: rgb(154, 153, 150);\n"
"	border-radius:10px;"));
        label_1 = new QLabel(groupBox_2);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(0, 20, 201, 25));
        label_1->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border-radius: 0px;\n"
"	border-bottom: 0px solid grey;\n"
"	border-top: 1px solid grey;\n"
"	color: rgb(94, 92, 100);\n"
"}"));
        fileName = new QLabel(groupBox_2);
        fileName->setObjectName("fileName");
        fileName->setGeometry(QRect(0, 45, 201, 25));
        fileName->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 14pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border-radius: 0px;\n"
"	border-top: 0px solid grey;\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(0, 70, 201, 25));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border-radius: 0px;\n"
"	border-bottom: 0px solid grey;\n"
"	border-top: 0px solid grey;\n"
"	color: rgb(94, 92, 100);\n"
"}"));
        numberOfVertices = new QLabel(groupBox_2);
        numberOfVertices->setObjectName("numberOfVertices");
        numberOfVertices->setGeometry(QRect(0, 95, 201, 25));
        numberOfVertices->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 14pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border-radius: 0px;\n"
"	border-top: 0px solid grey;\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(0, 120, 201, 25));
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border-radius: 0px;\n"
"	border-bottom: 0px solid grey;\n"
"	border-top: 0px solid grey;\n"
"	color: rgb(94, 92, 100);\n"
"}"));
        numberOfEdges = new QLabel(groupBox_2);
        numberOfEdges->setObjectName("numberOfEdges");
        numberOfEdges->setGeometry(QRect(0, 146, 201, 25));
        numberOfEdges->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 14pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border-top: 0px solid grey;\n"
"	border-bottom: 1px solid grey;\n"
"	border-top-right-radius:0px;\n"
"	border-top-left-radius:0px;\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        pushButton_selectFile = new QPushButton(widget);
        pushButton_selectFile->setObjectName("pushButton_selectFile");
        pushButton_selectFile->setGeometry(QRect(10, 10, 201, 31));
        pushButton_selectFile->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(224, 170, 255);\n"
"	color: rgb(94, 92, 100);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(226, 179, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        groupBox_moving = new QGroupBox(widget);
        groupBox_moving->setObjectName("groupBox_moving");
        groupBox_moving->setGeometry(QRect(10, 217, 201, 96));
        QFont font;
        font.setFamilies({QString::fromUtf8("Pastelova Demo")});
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        groupBox_moving->setFont(font);
        groupBox_moving->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	font: 14pt \"Pastelova Demo\";\n"
"	border: 1px solid grey;\n"
"	background-color: rgb(246, 245, 244);\n"
"	color: rgb(154, 153, 150);\n"
"\n"
"	border-radius:10px;\n"
"	border-bottom-right-radius:0px;\n"
"	border-bottom-left-radius:0px;\n"
"}"));
        label_moving_x = new QLabel(groupBox_moving);
        label_moving_x->setObjectName("label_moving_x");
        label_moving_x->setGeometry(QRect(85, 20, 25, 25));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Pastelova Demo")});
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(false);
        label_moving_x->setFont(font1);
        label_moving_x->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border: 1px solid grey;\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_moving_x_plus = new QPushButton(groupBox_moving);
        pushButton_moving_x_plus->setObjectName("pushButton_moving_x_plus");
        pushButton_moving_x_plus->setGeometry(QRect(155, 20, 45, 25));
        pushButton_moving_x_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(94, 92, 100);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_moving_x_minus = new QPushButton(groupBox_moving);
        pushButton_moving_x_minus->setObjectName("pushButton_moving_x_minus");
        pushButton_moving_x_minus->setGeometry(QRect(110, 20, 45, 25));
        pushButton_moving_x_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(94, 92, 100);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        label_2 = new QLabel(groupBox_moving);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 20, 85, 25));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	border: 1px solid grey;\n"
"	color: rgb(94, 92, 100);\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        step = new QDoubleSpinBox(groupBox_moving);
        step->setObjectName("step");
        step->setGeometry(QRect(0, 43, 85, 54));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Pastelova Demo")});
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        step->setFont(font2);
        step->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Pastelova Demo\";\n"
"background-color: rgb(246, 245, 244);"));
        step->setMinimum(0.100000000000000);
        step->setMaximum(10.000000000000000);
        step->setSingleStep(0.500000000000000);
        step->setValue(0.500000000000000);
        pushButton_moving_y_plus = new QPushButton(groupBox_moving);
        pushButton_moving_y_plus->setObjectName("pushButton_moving_y_plus");
        pushButton_moving_y_plus->setGeometry(QRect(155, 45, 45, 25));
        pushButton_moving_y_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(119, 118, 123);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_moving_z_plus = new QPushButton(groupBox_moving);
        pushButton_moving_z_plus->setObjectName("pushButton_moving_z_plus");
        pushButton_moving_z_plus->setGeometry(QRect(155, 70, 45, 25));
        pushButton_moving_z_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(154, 153, 150);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_moving_y_minus = new QPushButton(groupBox_moving);
        pushButton_moving_y_minus->setObjectName("pushButton_moving_y_minus");
        pushButton_moving_y_minus->setGeometry(QRect(110, 45, 45, 25));
        pushButton_moving_y_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(119, 118, 123);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_moving_z_minus = new QPushButton(groupBox_moving);
        pushButton_moving_z_minus->setObjectName("pushButton_moving_z_minus");
        pushButton_moving_z_minus->setGeometry(QRect(110, 70, 45, 25));
        pushButton_moving_z_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(154, 153, 150);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        label_moving_y = new QLabel(groupBox_moving);
        label_moving_y->setObjectName("label_moving_y");
        label_moving_y->setGeometry(QRect(85, 45, 25, 25));
        label_moving_y->setFont(font1);
        label_moving_y->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border: 1px solid grey;\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        label_moving_z = new QLabel(groupBox_moving);
        label_moving_z->setObjectName("label_moving_z");
        label_moving_z->setGeometry(QRect(85, 70, 25, 25));
        label_moving_z->setFont(font1);
        label_moving_z->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border: 1px solid grey;\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        groupBox_moving_2 = new QGroupBox(widget);
        groupBox_moving_2->setObjectName("groupBox_moving_2");
        groupBox_moving_2->setGeometry(QRect(10, 312, 201, 96));
        groupBox_moving_2->setFont(font);
        groupBox_moving_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	font: 14pt \"Pastelova Demo\";\n"
"	border: 1px solid grey;\n"
"	background-color: rgb(246, 245, 244);\n"
"	color: rgb(154, 153, 150);\n"
"}"));
        label_moving_x_2 = new QLabel(groupBox_moving_2);
        label_moving_x_2->setObjectName("label_moving_x_2");
        label_moving_x_2->setGeometry(QRect(85, 20, 25, 25));
        label_moving_x_2->setFont(font1);
        label_moving_x_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border: 1px solid grey;\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_rotation_x_plus = new QPushButton(groupBox_moving_2);
        pushButton_rotation_x_plus->setObjectName("pushButton_rotation_x_plus");
        pushButton_rotation_x_plus->setGeometry(QRect(155, 20, 45, 25));
        pushButton_rotation_x_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(94, 92, 100);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_rotation_x_minus = new QPushButton(groupBox_moving_2);
        pushButton_rotation_x_minus->setObjectName("pushButton_rotation_x_minus");
        pushButton_rotation_x_minus->setGeometry(QRect(110, 20, 45, 25));
        pushButton_rotation_x_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(94, 92, 100);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        label_3 = new QLabel(groupBox_moving_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 20, 85, 25));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	border: 1px solid grey;\n"
"	color: rgb(94, 92, 100);\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_rotation_y_plus = new QPushButton(groupBox_moving_2);
        pushButton_rotation_y_plus->setObjectName("pushButton_rotation_y_plus");
        pushButton_rotation_y_plus->setGeometry(QRect(155, 45, 45, 25));
        pushButton_rotation_y_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(119, 118, 123);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_rotation_z_plus = new QPushButton(groupBox_moving_2);
        pushButton_rotation_z_plus->setObjectName("pushButton_rotation_z_plus");
        pushButton_rotation_z_plus->setGeometry(QRect(155, 70, 45, 25));
        pushButton_rotation_z_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(154, 153, 150);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_rotation_y_minus = new QPushButton(groupBox_moving_2);
        pushButton_rotation_y_minus->setObjectName("pushButton_rotation_y_minus");
        pushButton_rotation_y_minus->setGeometry(QRect(110, 45, 45, 25));
        pushButton_rotation_y_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(119, 118, 123);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        pushButton_rotation_z_minus = new QPushButton(groupBox_moving_2);
        pushButton_rotation_z_minus->setObjectName("pushButton_rotation_z_minus");
        pushButton_rotation_z_minus->setGeometry(QRect(110, 70, 45, 25));
        pushButton_rotation_z_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(154, 153, 150);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        label_moving_y_2 = new QLabel(groupBox_moving_2);
        label_moving_y_2->setObjectName("label_moving_y_2");
        label_moving_y_2->setGeometry(QRect(85, 45, 25, 25));
        label_moving_y_2->setFont(font1);
        label_moving_y_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border: 1px solid grey;\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        label_moving_z_2 = new QLabel(groupBox_moving_2);
        label_moving_z_2->setObjectName("label_moving_z_2");
        label_moving_z_2->setGeometry(QRect(85, 70, 25, 25));
        label_moving_z_2->setFont(font1);
        label_moving_z_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border: 1px solid grey;\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        angle = new QSpinBox(groupBox_moving_2);
        angle->setObjectName("angle");
        angle->setGeometry(QRect(0, 43, 85, 54));
        angle->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Pastelova Demo\";\n"
"background-color: rgb(246, 245, 244);"));
        angle->setValue(5);
        groupBox_scaling = new QGroupBox(widget);
        groupBox_scaling->setObjectName("groupBox_scaling");
        groupBox_scaling->setGeometry(QRect(10, 407, 201, 45));
        groupBox_scaling->setFont(font);
        groupBox_scaling->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: rgb(246, 245, 244);\n"
"	font: 14pt \"Pastelova Demo\";\n"
"	border: 1px solid grey;\n"
"	border-radius: 10px;\n"
"	border-top-right-radius:0px;\n"
"	border-top-left-radius:0px;\n"
"	color: rgb(154, 153, 150);\n"
"}"));
        pushButton_scaling_minus = new QPushButton(groupBox_scaling);
        pushButton_scaling_minus->setObjectName("pushButton_scaling_minus");
        pushButton_scaling_minus->setGeometry(QRect(110, 20, 45, 25));
        pushButton_scaling_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	background-color: rgb(94, 92, 100);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        scale = new QSpinBox(groupBox_scaling);
        scale->setObjectName("scale");
        scale->setGeometry(QRect(0, 19, 85, 25));
        scale->setFont(font2);
        scale->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	font: 700 12pt \"Pastelova Demo\";\n"
"background-color: rgb(246, 245, 244);\n"
"border: 1px solid grey;\n"
"border-bottom:  0px;\n"
"border-radius:10px;\n"
"border-top-right-radius:0px;\n"
"border-top-left-radius:0px;\n"
"border-bottom-right-radius:0px;\n"
"}\n"
""));
        scale->setMinimum(1);
        scale->setMaximum(99);
        scale->setSingleStep(5);
        scale->setValue(10);
        label_scaling_factor = new QLabel(groupBox_scaling);
        label_scaling_factor->setObjectName("label_scaling_factor");
        label_scaling_factor->setGeometry(QRect(85, 20, 25, 25));
        label_scaling_factor->setFont(font1);
        label_scaling_factor->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	border: 1px solid grey;\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_scaling_plus = new QPushButton(groupBox_scaling);
        pushButton_scaling_plus->setObjectName("pushButton_scaling_plus");
        pushButton_scaling_plus->setGeometry(QRect(155, 20, 45, 25));
        pushButton_scaling_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(94, 92, 100);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"	border-radius:10px;\n"
"	border-top-right-radius:0px;\n"
"	border-top-left-radius:0px;\n"
"	border-bottom-left-radius:0px;\n"
"}\n"
"\n"
" QPushButton:hover {\n"
"	background-color: rgb(154, 153, 150)\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"											  stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        groupBox_7 = new QGroupBox(widget);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(10, 455, 201, 47));
        groupBox_7->setFont(font);
        groupBox_7->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"background-color: rgb(246, 245, 244);\n"
"font: 14pt \"Pastelova Demo\";\n"
"border: 1px solid grey;\n"
"border-radius: 10px;\n"
"color: rgb(154, 153, 150);\n"
"}"));
        radioButton_parallel_type = new QRadioButton(groupBox_7);
        radioButton_parallel_type->setObjectName("radioButton_parallel_type");
        radioButton_parallel_type->setGeometry(QRect(0, 20, 104, 27));
        radioButton_parallel_type->setFont(font1);
        radioButton_parallel_type->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-right: 0px;\n"
"	border-radius: 10px;\n"
"	border-top-right-radius:0px;\n"
"	border-top-left-radius:0px;\n"
"	border-bottom-right-radius:0px;\n"
"}"));
        radioButton_parallel_type->setChecked(true);
        radioButton_central_type = new QRadioButton(groupBox_7);
        radioButton_central_type->setObjectName("radioButton_central_type");
        radioButton_central_type->setGeometry(QRect(104, 20, 96, 27));
        radioButton_central_type->setFont(font1);
        radioButton_central_type->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-left: 0px;\n"
"	border-radius: 10px;\n"
"	border-top-right-radius:0px;\n"
"	border-top-left-radius:0px;\n"
"	border-bottom-left-radius: 0px;\n"
"}"));
        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 505, 201, 68));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"background-color: rgb(246, 245, 244);\n"
"font: 14pt \"Pastelova Demo\";\n"
"border: 1px solid grey;\n"
"border-radius: 10px;\n"
"color: rgb(154, 153, 150);\n"
"}"));
        radioButton_background_white = new QRadioButton(groupBox_3);
        radioButton_background_white->setObjectName("radioButton_background_white");
        radioButton_background_white->setGeometry(QRect(0, 20, 100, 23));
        radioButton_background_white->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-right: 0px;\n"
"	border-bottom: 0px;\n"
"}"));
        radioButton_background_white->setChecked(true);
        radioButton_background_black = new QRadioButton(groupBox_3);
        radioButton_background_black->setObjectName("radioButton_background_black");
        radioButton_background_black->setGeometry(QRect(100, 20, 101, 23));
        radioButton_background_black->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-left: 0px;\n"
"	border-bottom: 0px;\n"
"}"));
        radioButton_background_grey = new QRadioButton(groupBox_3);
        radioButton_background_grey->setObjectName("radioButton_background_grey");
        radioButton_background_grey->setGeometry(QRect(0, 45, 91, 23));
        radioButton_background_grey->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-right: 0px;\n"
"	border-top: 0px;\n"
"	border-radius: 10px;\n"
"	border-top-right-radius:0px;\n"
"	border-top-left-radius:0px;\n"
"	border-bottom-right-radius:0px;\n"
"}"));
        radioButton_background_green = new QRadioButton(groupBox_3);
        radioButton_background_green->setObjectName("radioButton_background_green");
        radioButton_background_green->setGeometry(QRect(100, 45, 101, 23));
        radioButton_background_green->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-left: 0px;\n"
"	border-top: 0px;\n"
"	border-radius: 10px;\n"
"	border-top-right-radius:0px;\n"
"	border-top-left-radius:0px;\n"
"	border-bottom-left-radius: 0px;\n"
"}"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 575, 201, 169));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"background-color: rgb(246, 245, 244);\n"
"font: 14pt \"Pastelova Demo\";\n"
"border: 1px solid grey;\n"
"border-radius: 10px;\n"
"color: rgb(154, 153, 150);\n"
"}"));
        radioButton_edgeType_solid = new QRadioButton(groupBox);
        radioButton_edgeType_solid->setObjectName("radioButton_edgeType_solid");
        radioButton_edgeType_solid->setGeometry(QRect(0, 44, 100, 23));
        radioButton_edgeType_solid->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-top: 0px;\n"
"	border-right: 0px;\n"
"}"));
        radioButton_edgeType_solid->setChecked(true);
        radioButton_edgeType_dashed = new QRadioButton(groupBox);
        radioButton_edgeType_dashed->setObjectName("radioButton_edgeType_dashed");
        radioButton_edgeType_dashed->setGeometry(QRect(100, 44, 101, 23));
        radioButton_edgeType_dashed->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-top: 0px;\n"
"	border-left: 0px;\n"
"}"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(6, 70, 191, 20));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	color: rgb(94, 92, 100);\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 138, 101, 31));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-right: 0px;\n"
"	border-radius: 10px;\n"
"	border-top-right-radius:0px;\n"
"	border-top-left-radius:0px;\n"
"	border-bottom-right-radius:0px;\n"
"}"));
        edgeThickness = new QSpinBox(groupBox);
        edgeThickness->setObjectName("edgeThickness");
        edgeThickness->setGeometry(QRect(100, 138, 101, 31));
        edgeThickness->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	font: 700 12pt \"Pastelova Demo\";\n"
"background-color: rgb(246, 245, 244);\n"
"border: 1px solid grey;\n"
"border-radius:10px;\n"
"border-top-right-radius:0px;\n"
"border-top-left-radius:0px;\n"
"border-bottom-left-radius:0px;\n"
"}\n"
""));
        edgeThickness->setValue(1);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 20, 201, 21));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	color: rgb(94, 92, 100);\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-bottom: 0px;\n"
"}"));
        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 90, 191, 47));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 245, 244);"));
        radioButton_edgeColor_white = new QRadioButton(widget_2);
        radioButton_edgeColor_white->setObjectName("radioButton_edgeColor_white");
        radioButton_edgeColor_white->setGeometry(QRect(0, 0, 100, 23));
        radioButton_edgeColor_white->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-right: 0px;\n"
"	border-bottom: 0px;\n"
"	border-top: 0px;\n"
"}"));
        radioButton_edgeColor_white->setChecked(true);
        radioButton_edgeColor_white->setAutoExclusive(true);
        radioButton_edgeColor_black = new QRadioButton(widget_2);
        radioButton_edgeColor_black->setObjectName("radioButton_edgeColor_black");
        radioButton_edgeColor_black->setGeometry(QRect(100, 0, 101, 23));
        radioButton_edgeColor_black->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-left: 0px;\n"
"	border-bottom: 0px;\n"
"	border-top: 0px;\n"
"}"));
        radioButton_edgeColor_grey = new QRadioButton(widget_2);
        radioButton_edgeColor_grey->setObjectName("radioButton_edgeColor_grey");
        radioButton_edgeColor_grey->setGeometry(QRect(0, 25, 100, 23));
        radioButton_edgeColor_grey->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-top: 0px;\n"
"	border-right: 0px;\n"
"}"));
        radioButton_edgeColor_green = new QRadioButton(widget_2);
        radioButton_edgeColor_green->setObjectName("radioButton_edgeColor_green");
        radioButton_edgeColor_green->setGeometry(QRect(100, 25, 101, 23));
        radioButton_edgeColor_green->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-top: 0px;\n"
"	border-left: 0px;\n"
"}"));
        groupBox_5 = new QGroupBox(widget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(10, 746, 201, 191));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"background-color: rgb(246, 245, 244);\n"
"font: 14pt \"Pastelova Demo\";\n"
"border: 1px solid grey;\n"
"border-radius: 10px;\n"
"color: rgb(154, 153, 150);\n"
"}"));
        radioButton_vertexType_circle = new QRadioButton(groupBox_5);
        radioButton_vertexType_circle->setObjectName("radioButton_vertexType_circle");
        radioButton_vertexType_circle->setGeometry(QRect(0, 44, 100, 23));
        radioButton_vertexType_circle->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-top: 0px;\n"
"	border-right: 0px;\n"
"	border-bottom: 0px;\n"
"}"));
        radioButton_vertexType_circle->setChecked(true);
        radioButton_vertexType_square = new QRadioButton(groupBox_5);
        radioButton_vertexType_square->setObjectName("radioButton_vertexType_square");
        radioButton_vertexType_square->setGeometry(QRect(100, 44, 101, 23));
        radioButton_vertexType_square->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-top: 0px;\n"
"	border-left: 0px;\n"
"	border-bottom: 0px;\n"
"}"));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(6, 95, 191, 20));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	color: rgb(94, 92, 100);\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 160, 101, 31));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-right: 0px;\n"
"	border-radius: 10px;\n"
"	border-top-right-radius:0px;\n"
"	border-top-left-radius:0px;\n"
"	border-bottom-right-radius:0px;\n"
"}"));
        vertexSize = new QSpinBox(groupBox_5);
        vertexSize->setObjectName("vertexSize");
        vertexSize->setGeometry(QRect(100, 160, 101, 31));
        vertexSize->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	font: 700 12pt \"Pastelova Demo\";\n"
"background-color: rgb(246, 245, 244);\n"
"border: 1px solid grey;\n"
"border-radius:10px;\n"
"border-top-right-radius:0px;\n"
"border-top-left-radius:0px;\n"
"border-bottom-left-radius:0px;\n"
"}\n"
""));
        vertexSize->setValue(1);
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 20, 201, 21));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"	color: rgb(94, 92, 100);\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-bottom: 0px;\n"
"}"));
        radioButton_vertexType_novertex = new QRadioButton(groupBox_5);
        radioButton_vertexType_novertex->setObjectName("radioButton_vertexType_novertex");
        radioButton_vertexType_novertex->setGeometry(QRect(0, 70, 201, 23));
        radioButton_vertexType_novertex->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-top: 0px;\n"
"}"));
        widget_3 = new QWidget(groupBox_5);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 111, 201, 46));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 245, 244);"));
        radioButton_vertexColor_white = new QRadioButton(widget_3);
        radioButton_vertexColor_white->setObjectName("radioButton_vertexColor_white");
        radioButton_vertexColor_white->setGeometry(QRect(0, 0, 100, 23));
        radioButton_vertexColor_white->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-right: 0px;\n"
"	border-bottom: 0px;\n"
"	border-top: 0px;\n"
"}"));
        radioButton_vertexColor_white->setChecked(true);
        radioButton_vertexColor_black = new QRadioButton(widget_3);
        radioButton_vertexColor_black->setObjectName("radioButton_vertexColor_black");
        radioButton_vertexColor_black->setGeometry(QRect(100, 0, 101, 23));
        radioButton_vertexColor_black->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-left: 0px;\n"
"	border-bottom: 0px;\n"
"	border-top: 0px;\n"
"}"));
        radioButton_vertexColor_grey = new QRadioButton(widget_3);
        radioButton_vertexColor_grey->setObjectName("radioButton_vertexColor_grey");
        radioButton_vertexColor_grey->setGeometry(QRect(0, 25, 100, 23));
        radioButton_vertexColor_grey->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-top: 0px;\n"
"	border-right: 0px;\n"
"}"));
        radioButton_vertexColor_green = new QRadioButton(widget_3);
        radioButton_vertexColor_green->setObjectName("radioButton_vertexColor_green");
        radioButton_vertexColor_green->setGeometry(QRect(100, 25, 101, 23));
        radioButton_vertexColor_green->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 700 16pt \"Pastelova Demo\";\n"
"	background-color: rgb(246, 245, 244);\n"
"	border: 1px solid grey;\n"
"	border-top: 0px;\n"
"	border-left: 0px;\n"
"}"));
        testButton = new QPushButton(centralwidget);
        testButton->setObjectName("testButton");
        testButton->setGeometry(QRect(500, 280, 89, 25));
        viewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(viewer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        viewer->setMenuBar(menubar);
        statusbar = new QStatusBar(viewer);
        statusbar->setObjectName("statusbar");
        viewer->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave_settings);
        menuFile->addAction(actionSave_as_GIF);
        menuFile->addAction(actionSave_as_bmp);
        menuFile->addAction(actionSave_as_jpeg);

        retranslateUi(viewer);

        QMetaObject::connectSlotsByName(viewer);
    } // setupUi

    void retranslateUi(QMainWindow *viewer)
    {
        viewer->setWindowTitle(QCoreApplication::translate("viewer", "viewer", nullptr));
        actionSave_settings->setText(QCoreApplication::translate("viewer", "Save settings", nullptr));
        actionSave_as_GIF->setText(QCoreApplication::translate("viewer", "Save as GIF", nullptr));
        actionSave_as_bmp->setText(QCoreApplication::translate("viewer", "Save as .bmp", nullptr));
        actionSave_as_jpeg->setText(QCoreApplication::translate("viewer", "Save as .jpeg", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("viewer", " FILE INFO", nullptr));
        label_1->setText(QCoreApplication::translate("viewer", "FIle name", nullptr));
        fileName->setText(QString());
        label_9->setText(QCoreApplication::translate("viewer", "Number of vertices", nullptr));
        numberOfVertices->setText(QString());
        label_11->setText(QCoreApplication::translate("viewer", "Number of edges", nullptr));
        numberOfEdges->setText(QString());
        pushButton_selectFile->setText(QCoreApplication::translate("viewer", "SELECT MODEL", nullptr));
        groupBox_moving->setTitle(QCoreApplication::translate("viewer", " MOVING", nullptr));
        label_moving_x->setText(QCoreApplication::translate("viewer", "X", nullptr));
        pushButton_moving_x_plus->setText(QCoreApplication::translate("viewer", "\342\207\250", nullptr));
        pushButton_moving_x_minus->setText(QCoreApplication::translate("viewer", "\342\207\246", nullptr));
        label_2->setText(QCoreApplication::translate("viewer", "Step:", nullptr));
        pushButton_moving_y_plus->setText(QCoreApplication::translate("viewer", "\342\207\247", nullptr));
        pushButton_moving_z_plus->setText(QCoreApplication::translate("viewer", "\342\254\202", nullptr));
        pushButton_moving_y_minus->setText(QCoreApplication::translate("viewer", "\342\207\251", nullptr));
        pushButton_moving_z_minus->setText(QCoreApplication::translate("viewer", "\342\254\201 ", nullptr));
        label_moving_y->setText(QCoreApplication::translate("viewer", "Y", nullptr));
        label_moving_z->setText(QCoreApplication::translate("viewer", "Z", nullptr));
        groupBox_moving_2->setTitle(QCoreApplication::translate("viewer", " ROTATION", nullptr));
        label_moving_x_2->setText(QCoreApplication::translate("viewer", "X", nullptr));
        pushButton_rotation_x_plus->setText(QCoreApplication::translate("viewer", "\342\207\250", nullptr));
        pushButton_rotation_x_minus->setText(QCoreApplication::translate("viewer", "\342\207\246", nullptr));
        label_3->setText(QCoreApplication::translate("viewer", "Angle\302\260:", nullptr));
        pushButton_rotation_y_plus->setText(QCoreApplication::translate("viewer", "\342\207\247", nullptr));
        pushButton_rotation_z_plus->setText(QCoreApplication::translate("viewer", "\342\254\202", nullptr));
        pushButton_rotation_y_minus->setText(QCoreApplication::translate("viewer", "\342\207\251", nullptr));
        pushButton_rotation_z_minus->setText(QCoreApplication::translate("viewer", "\342\254\201 ", nullptr));
        label_moving_y_2->setText(QCoreApplication::translate("viewer", "Y", nullptr));
        label_moving_z_2->setText(QCoreApplication::translate("viewer", "Z", nullptr));
        groupBox_scaling->setTitle(QCoreApplication::translate("viewer", " SCALING", nullptr));
        pushButton_scaling_minus->setText(QCoreApplication::translate("viewer", "-", nullptr));
        label_scaling_factor->setText(QCoreApplication::translate("viewer", "%", nullptr));
        pushButton_scaling_plus->setText(QCoreApplication::translate("viewer", "+", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("viewer", "PROJECTION TYPE", nullptr));
        radioButton_parallel_type->setText(QCoreApplication::translate("viewer", "Parallel", nullptr));
        radioButton_central_type->setText(QCoreApplication::translate("viewer", "Central", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("viewer", "BACKGROUND COLOR", nullptr));
        radioButton_background_white->setText(QCoreApplication::translate("viewer", "White", nullptr));
        radioButton_background_black->setText(QCoreApplication::translate("viewer", "Black", nullptr));
        radioButton_background_grey->setText(QCoreApplication::translate("viewer", "Grey", nullptr));
        radioButton_background_green->setText(QCoreApplication::translate("viewer", "Green", nullptr));
        groupBox->setTitle(QCoreApplication::translate("viewer", "EDGE SETTINGS", nullptr));
        radioButton_edgeType_solid->setText(QCoreApplication::translate("viewer", "Solid", nullptr));
        radioButton_edgeType_dashed->setText(QCoreApplication::translate("viewer", "Dashed", nullptr));
        label_4->setText(QCoreApplication::translate("viewer", "Color", nullptr));
        label_5->setText(QCoreApplication::translate("viewer", "Thickness", nullptr));
        label->setText(QCoreApplication::translate("viewer", "Type", nullptr));
        radioButton_edgeColor_white->setText(QCoreApplication::translate("viewer", "White", nullptr));
        radioButton_edgeColor_black->setText(QCoreApplication::translate("viewer", "Black", nullptr));
        radioButton_edgeColor_grey->setText(QCoreApplication::translate("viewer", "Grey", nullptr));
        radioButton_edgeColor_green->setText(QCoreApplication::translate("viewer", "Green", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("viewer", "VERTEX SETTINGS", nullptr));
        radioButton_vertexType_circle->setText(QCoreApplication::translate("viewer", "Circle", nullptr));
        radioButton_vertexType_square->setText(QCoreApplication::translate("viewer", "Square", nullptr));
        label_6->setText(QCoreApplication::translate("viewer", "Color", nullptr));
        label_7->setText(QCoreApplication::translate("viewer", "Size", nullptr));
        label_8->setText(QCoreApplication::translate("viewer", "Type", nullptr));
        radioButton_vertexType_novertex->setText(QCoreApplication::translate("viewer", "No Vertex", nullptr));
        radioButton_vertexColor_white->setText(QCoreApplication::translate("viewer", "White", nullptr));
        radioButton_vertexColor_black->setText(QCoreApplication::translate("viewer", "Black", nullptr));
        radioButton_vertexColor_grey->setText(QCoreApplication::translate("viewer", "Grey", nullptr));
        radioButton_vertexColor_green->setText(QCoreApplication::translate("viewer", "Green", nullptr));
        testButton->setText(QCoreApplication::translate("viewer", "PushButton", nullptr));
        menuFile->setTitle(QCoreApplication::translate("viewer", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewer: public Ui_viewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWER_H
