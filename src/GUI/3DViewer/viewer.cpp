#include "viewer.h"
#include "./ui_viewer.h"
// #include "../Backend/logic/headerCAD.h"

#include <QFileDialog>
#include <QColorDialog>
#include <QColor>

#define X 1
#define Y 2
#define Z 3

viewer::viewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::viewer)
{
    ui->setupUi(this);

    // connecting the movement buttons
    connect(ui->pushButton_moving_x_minus, SIGNAL(clicked()), this, SLOT(moving()));
    connect(ui->pushButton_moving_x_plus, SIGNAL(clicked()), this, SLOT(moving()));
    connect(ui->pushButton_moving_y_minus, SIGNAL(clicked()), this, SLOT(moving()));
    connect(ui->pushButton_moving_y_plus, SIGNAL(clicked()), this, SLOT(moving()));
    connect(ui->pushButton_moving_z_minus, SIGNAL(clicked()), this, SLOT(moving()));
    connect(ui->pushButton_moving_z_plus, SIGNAL(clicked()), this, SLOT(moving()));

    // connecting the rotation buttons
    connect(ui->pushButton_rotation_x_minus, SIGNAL(clicked()), this, SLOT(rotation()));
    connect(ui->pushButton_rotation_x_plus, SIGNAL(clicked()), this, SLOT(rotation()));
    connect(ui->pushButton_rotation_y_minus, SIGNAL(clicked()), this, SLOT(rotation()));
    connect(ui->pushButton_rotation_y_plus, SIGNAL(clicked()), this, SLOT(rotation()));
    connect(ui->pushButton_rotation_z_minus, SIGNAL(clicked()), this, SLOT(rotation()));
    connect(ui->pushButton_rotation_z_plus, SIGNAL(clicked()), this, SLOT(rotation()));

    // connecting zoom buttons
    connect(ui->pushButton_scaling_minus, SIGNAL(clicked()), this, SLOT(scaling()));
    connect(ui->pushButton_scaling_plus, SIGNAL(clicked()), this, SLOT(scaling()));
}

viewer::~viewer()
{
    delete ui;
}

void viewer::on_pushButton_selectFile_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, ("Select Model"), "../models/", "3D Image Files (*.obj)");
    char *path = (filePath.toLocal8Bit()).data();

    // parse function
	structRoot model;
	parcer(path, &model);

    ui->fileName->setText((QFileInfo (filePath)).fileName());
//    ui->numberOfVertices->setText(QString::number(model.vertices));
//    ui->numberOfEdges->setText(QString::number(model.edges));

    update();
}

void viewer::moving() {
    double step = ui->step->value();
    QPushButton *button = (QPushButton *)sender();
    QString buttonText = button->text();


    // prototype function: moveModel(struct *model, double step, int axis, int shift);
    // axis - (X, Y, Z), where X = 1, Y = 2, Z = 3;
    // shift - (1, -1), where digit = coordinate shift
    if (buttonText == "⇦") {
        // shift function
        // x-coordinate
        // moveModel(&model, step, X, -1);
    } else if (buttonText == "⇨") {
        // shift function
        // x-coordinate
        // moveModel(&model, step, X, 1);
    } else if (buttonText == "⇩") {
        // shift function
        // y-coordinate
    } else if (buttonText == "⇧") {
        // shift function
        // y-coordinate
    } else if (buttonText == "⬁") {
        // shift function
        // z-coordinate
    } else if (buttonText == "⬂") {
        // shift function
        // z-coordinate
    }

    update();
}

void viewer::rotation() {
    int angle = ui->angle->value();
    QPushButton *button = (QPushButton *)sender();
    QString buttonText = button->text();

    if (buttonText == "⇦") {
        // rotation function
    } else if (buttonText == "⇨") {
        // rotation function
    } else if (buttonText == "⇩") {
        // rotation function
    } else if (buttonText == "⇧") {
        // rotation function
    } else if (buttonText == "⬁") {
        // rotation function
    } else if (buttonText == "⬂") {
        // rotation function
    }

    update();
}

void viewer::scaling() {
    int scale = ui->scale->value();
    QPushButton *button = (QPushButton *)sender();
    QString buttonText = button->text();

    // prototype function: scaleModel(struct *model, int scale, int shift);
    // scale = (percent), the value by which the model is scaled
    // shift = (-1, 1), where digit = coordinate shift
    if (buttonText == "-") {
        // scaleModel(&model, scale, -1);
    } else {
        // scaleModel(&model, scale, 1);
    }

    update();
}

void viewer::on_testButton_clicked() {
    QColor color = QColorDialog::getColor(Qt::white, this);
}

