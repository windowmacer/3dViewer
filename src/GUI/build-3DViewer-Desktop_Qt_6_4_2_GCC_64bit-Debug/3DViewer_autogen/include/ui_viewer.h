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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_viewer
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widget_2;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *viewer)
    {
        if (viewer->objectName().isEmpty())
            viewer->setObjectName("viewer");
        viewer->resize(675, 482);
        centralwidget = new QWidget(viewer);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 241, 261));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 209, 25));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 40, 221, 201));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 30, 209, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 50, 209, 35));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 80, 209, 27));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 110, 201, 31));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 140, 191, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 170, 201, 31));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(300, 20, 241, 261));
        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 50, 221, 201));
        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 20, 221, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");

        verticalLayout->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName("label_10");

        verticalLayout->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName("label_11");

        verticalLayout->addWidget(label_11);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName("label_12");

        verticalLayout->addWidget(label_12);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 10, 221, 25));
        viewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(viewer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 675, 22));
        viewer->setMenuBar(menubar);
        statusbar = new QStatusBar(viewer);
        statusbar->setObjectName("statusbar");
        viewer->setStatusBar(statusbar);

        retranslateUi(viewer);

        QMetaObject::connectSlotsByName(viewer);
    } // setupUi

    void retranslateUi(QMainWindow *viewer)
    {
        viewer->setWindowTitle(QCoreApplication::translate("viewer", "viewer", nullptr));
        pushButton->setText(QCoreApplication::translate("viewer", "SELECT FILE", nullptr));
        groupBox->setTitle(QCoreApplication::translate("viewer", "FILE INFO", nullptr));
        label->setText(QCoreApplication::translate("viewer", "FIle name", nullptr));
        label_2->setText(QCoreApplication::translate("viewer", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("viewer", "Number of vertices", nullptr));
        label_4->setText(QCoreApplication::translate("viewer", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("viewer", "Number of edges", nullptr));
        label_6->setText(QCoreApplication::translate("viewer", "TextLabel", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("viewer", "FILE INFO", nullptr));
        label_7->setText(QCoreApplication::translate("viewer", "FIle name", nullptr));
        label_8->setText(QCoreApplication::translate("viewer", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("viewer", "Number of vertices", nullptr));
        label_10->setText(QCoreApplication::translate("viewer", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("viewer", "Number of edges", nullptr));
        label_12->setText(QCoreApplication::translate("viewer", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("viewer", "SELECT FILE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewer: public Ui_viewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWER_H
