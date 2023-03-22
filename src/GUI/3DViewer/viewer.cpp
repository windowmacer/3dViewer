#include "viewer.h"
#include "./ui_viewer.h"

#define X 1
#define Y 2
#define Z 3

viewer::viewer(QWidget *parent) : QOpenGLWidget(parent), ui(new Ui::viewer)
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

    // connecting colors
    connect(ui->pushButton_backgroundColor, SIGNAL(clicked()), this, SLOT(setColor()));
    connect(ui->pushButton_edgeColor, SIGNAL(clicked()), this, SLOT(setColor()));
    connect(ui->pushButton_vertexColor, SIGNAL(clicked()), this, SLOT(setColor()));
}

viewer::~viewer()
{
    delete ui;
}

void viewer::initializeGL() {
    x_angle = 15;
    y_angle = 15;
    z_angle = 1; //хмм?
    paint_mode = 0;
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void viewer::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void viewer::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glVertexPointer(3, GL_FLOAT, 0, model.vertexCoord);
	glEnableClientState(GL_VERTEX_ARRAY);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (paint_mode == 0) applyNewSettings();
	else if (paint_mode == 1 || paint_mode == 2) {
		if (paint_mode == 1) {
			glOrtho(-5, 5, -5, 5, 1, 15); //значения поменять?
			glTranslated(0, 0, -10);
		} 
		else if (paint_mode == 2) {
			glFrustum(-1, 1, -1, 1, 1, 15);
			glTranslated(0, 0, -10);
		}
		glRotated(x_angle, 1, 0, 0);
		glRotated(y_angle, 0, 1, 0);
		glRotated(z_angle, 0, 0, 1);
		glClearColor(backgroundColor.red(), backgroundColor.green(), backgroundColor.blue(), 1.0);
		glColor3f(edgeColor.red(), edgeColor.green(), edgeColor.blue());
		glLineWidth(edge_width);
		if (edge_type == 1) {
			glLineStripple(1, 0x3333); //поиграться со значениями
			glEnable(GL_LINE_STRIPPLE);
		}
		else glDisable(GL_LINE_STRIPPLE);
		glDrawElements(GL_LINES, model.countLines, GL_UNSIGNED_INT, model.vertexIndex); //переработать парсер
		glDisableClientState(Gl_VERTEX_ARRAY);
		if (vertex_visibility == 1) pointSettings();
	}
}

void viewer::pointSettings() {
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(vertexColor.red(), vertexColor.green(), vertexColor.blue());
    //glPointSize(point_size);
    if (point_type == 1) {
        glEnable(GL_POINT_SMOOTH);
        glDrawArrays(GL_POINTS, 0, model.countVertex);
        glDisable(GL_POINT_SMOOTH);
    }
    else glDrawArrays(GL_POINTS, 0, model.countVertex);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void viewer::applyNewSettings() {
    if (ui->radioButton_parallel_type->isChecked())
        paint_mode = 1;
    else if (ui->radioButton_central_type->isChecked())
        paint_mode = 2;
    glClearColor(backgroundColor.red(), backgroundColor.green(), backgroundColor.blue(), 1.0);
    glColor3f(edgeColor.red(), edgeColor.green(), edgeColor.blue());
    edge_width = (float)ui->edgeThickness->value(); // можно флоут убрать?
    glLineWidth(edge_width);
    if (ui->radioButton_edgeType_solid->isChecked())
        edge_type = 0;
    else
        edge_type = 1;
    if (ui->radioButton_vertexType_novertex->isChecked()) {
		point_visibility = 0;
	} else
		point_visibility = 1;
		glColor3f(edgeColor.red(), edgeColor.green(), edgeColor.blue());
		point_size = (float)ui->vertexSize->value() * 2; // и тут флоут тоже?
		glPointSize(point_size);
		if (ui->radioButton_vertexType_circle->isChecked())
			point_size = 1;
		else
			point_size = 2;
    update();
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
}

void viewer::on_pushButton_selectFile_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, ("Select Model"), "../models/", "3D Image Files (*.obj)");
    char *path = (filePath.toLocal8Bit()).data();

    // parse function
    parcer(path, &model);

    ui->fileName->setText((QFileInfo (filePath)).fileName());
//    ui->numberOfVertices->setText(QString::number(model.vertices));
//    ui->numberOfEdges->setText(QString::number(model.edges));
    paint_mode = 0;

    // update();
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
