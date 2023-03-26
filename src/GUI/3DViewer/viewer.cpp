#include "viewer.h"
#include "./ui_viewer.h"

viewer::viewer(QWidget *parent) : QOpenGLWidget(parent), ui(new Ui::viewer)
{
    ui->setupUi(this);
    this->resize(1440, 1080);
    initDefaultValues();

//    scrollArea = new QScrollArea(this);
//    QWidget *widget = new QWidget(scrollArea);
    ui->verticalScrollBar->setRange(0, 0);
    // scrollArea->setVerticalScrollBar(ui->verticalScrollBar);
//    scrollArea->setWidget(widget);
//    scrollArea->setWidgetResizable(true);
//    widget->setMinimumSize(300, 500);





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

    // connecting colors
    connect(ui->pushButton_backgroundColor, SIGNAL(clicked()), this, SLOT(setColor()));
    connect(ui->pushButton_edgeColor, SIGNAL(clicked()), this, SLOT(setColor()));
    connect(ui->pushButton_vertexColor, SIGNAL(clicked()), this, SLOT(setColor()));

    // connecting buttons to synchronize model updates
    connect(ui->radioButton_parallel_type, SIGNAL(clicked()), this, SLOT(update()));
    connect(ui->radioButton_central_type, SIGNAL(clicked()), this, SLOT(update()));
    connect(ui->radioButton_edgeType_dashed, SIGNAL(clicked()), this, SLOT(update()));
    connect(ui->radioButton_edgeType_solid, SIGNAL(clicked()), this, SLOT(update()));
    connect(ui->radioButton_vertexType_circle, SIGNAL(clicked()), this, SLOT(update()));
    connect(ui->radioButton_vertexType_square, SIGNAL(clicked()), this, SLOT(update()));
    connect(ui->radioButton_vertexType_novertex, SIGNAL(clicked()), this, SLOT(update()));
    connect(ui->edgeThickness, SIGNAL(valueChanged(int)), this, SLOT(update()));
    connect(ui->vertexSize, SIGNAL(valueChanged(int)), this, SLOT(update()));

    // lastSettings = new QSettings("SAVE_3DVIEWER", "3DViewer", this);
    // restoreSettings();
}

viewer::~viewer()
{
    // saveSettings();
    // очистить все, для чего выделялась память, если выделялась
    delete ui;
}

void viewer::initDefaultValues() {
    // setting the color
    backgroundColor.setRgb(255, 255, 255);
    edgeColor.setRgb(0, 0, 255);
    vertexColor.setRgb(255, 0, 0);

    // initializing the model
    model.vertexCoord = NULL;
    model.vertexIndex = NULL;
    model.countIndex = 0;
    model.countVertex = 0;
}

void viewer::setColor() {
    QPushButton *button = (QPushButton *)sender();

    if (button == ui->pushButton_backgroundColor) {
        backgroundColor = QColorDialog::getColor();
    } else if (button == ui->pushButton_edgeColor) {
        edgeColor = QColorDialog::getColor();
    } else if (button == ui->pushButton_vertexColor) {
        vertexColor = QColorDialog::getColor();
    }

    update();
}

void viewer::on_pushButton_selectFile_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, ("Select Model"), "../models/", "3D Image Files (*.obj)");

    if (filePath != "") {
        char *path = (filePath.toLocal8Bit()).data();

        parser(path, &model); // parse function

        ui->fileName->setText((QFileInfo (filePath)).fileName());
        ui->numberOfVertices->setText(QString::number(model.countVertex));
        // ui->numberOfEdges->setText(QString::number(model.edges));

        update();
    }
}

void viewer::moving() {
    double step = ui->step->value();
    QPushButton *button = (QPushButton *)sender();

    if (button == ui->pushButton_moving_x_minus) {
        moveModel(&model, -step, 0, 0);
    } else if (button == ui->pushButton_moving_x_plus) {
        moveModel(&model, step, 0, 0);
    } else if (button == ui->pushButton_moving_y_minus) {
        moveModel(&model, 0, -step, 0);
    } else if (button == ui->pushButton_moving_y_plus) {
        moveModel(&model, 0, step, 0);
    } else if (button == ui->pushButton_moving_z_minus) {
        moveModel(&model, 0, 0, -step);
    } else if (button == ui->pushButton_moving_z_plus) {
        moveModel(&model, 0, 0, step);
    }

    update();
}

void viewer::rotation() {
    int angle = ui->angle->value();
    QPushButton *button = (QPushButton *)sender();

    if (button == ui->pushButton_rotation_x_minus) {
        rotateModel(&model, -angle, X);
    } else if (button == ui->pushButton_rotation_x_plus) {
        rotateModel(&model, angle, X);
    } else if (button == ui->pushButton_rotation_y_minus) {
        rotateModel(&model, -angle, Y);
    } else if (button == ui->pushButton_rotation_y_plus) {
        rotateModel(&model, angle, Y);
    } else if (button == ui->pushButton_rotation_z_minus) {
        rotateModel(&model, -angle, Z);
    } else if (button == ui->pushButton_rotation_z_plus) {
        rotateModel(&model, angle, Z);
    }

    update();
}

void viewer::scaling() {
    int scale = ui->scale->value();
    QPushButton *button = (QPushButton *)sender();
    QString buttonText = button->text();

    if (buttonText == "-") {
        scaleModel(&model, -scale);
    } else {
        scaleModel(&model, scale);
    }

    update();
}
