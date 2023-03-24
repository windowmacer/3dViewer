#include "viewer.h"
#include "./ui_viewer.h"

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
            glLineStipple(1, 0x3333); //поиграться со значениями
            glEnable(GL_LINE_STIPPLE);
        }
        else glDisable(GL_LINE_STIPPLE);
        // glDrawElements(GL_LINES, model.countLines, GL_UNSIGNED_INT, model.vertexIndex); //переработать парсер
        glDisableClientState(GL_VERTEX_ARRAY);
        if (point_visibility == 1) pointSettings();
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
