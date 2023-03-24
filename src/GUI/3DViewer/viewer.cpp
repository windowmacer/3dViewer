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





//     connecting the movement buttons
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
}

void viewer::setColor() {
    QPushButton *button = (QPushButton *)sender();

    if (button == ui->pushButton_backgroundColor) {
        backgroundColor = QColorDialog::getColor(Qt::white);
    } else if (button == ui->pushButton_edgeColor) {
        edgeColor = QColorDialog::getColor(Qt::white);
    } else if (button == ui->pushButton_vertexColor) {
        vertexColor = QColorDialog::getColor(Qt::white);
    }

    update();
}

// сделать обработку ошибки при отмене открытия файла
void viewer::on_pushButton_selectFile_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, ("Select Model"), "../models/", "3D Image Files (*.obj)");
    char *path = (filePath.toLocal8Bit()).data();

    // parse function
    parcer(path, &model);

    ui->fileName->setText((QFileInfo (filePath)).fileName());
//    ui->numberOfVertices->setText(QString::number(model.vertices));
//    ui->numberOfEdges->setText(QString::number(model.edges));
    paint_mode = 0;

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
