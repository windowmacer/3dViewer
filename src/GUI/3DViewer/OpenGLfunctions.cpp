#include "viewer.h"
#include "./ui_viewer.h"

void viewer::initializeGL() {
    x_angle = 15;
    y_angle = 15;
    z_angle = 1; //хмм?
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // // // // // ?

    // инициализирую начальный цвет viewport
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void viewer::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void viewer::paintGL() {
    glClearColor(backgroundColor.redF(), backgroundColor.greenF(), backgroundColor.blueF(), 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // нужен для того чтобы обеспечить правильную очистку буфера цвета перед рисованием.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    updateValues();
    if (projectionType) {
        glVertexPointer(3, GL_DOUBLE, 0, model.vertexCoord);
        glEnableClientState(GL_VERTEX_ARRAY);
        setProjectionType();

        // поворачиваем модель, для того чтобы она не казалась плоской при загрузке
        glRotated(x_angle, 1, 0, 0);
        glRotated(y_angle, 0, 1, 0);
        glRotated(z_angle, 0, 0, 1);

        setEdges();
        if (pointVisibility == AVERTEX) setVertices();
        glDisableClientState(GL_VERTEX_ARRAY);
    }
}

void viewer::updateValues() {
    // projection type
    if (ui->radioButton_parallel_type->isChecked())
        projectionType = PARALLEL;
    else if (ui->radioButton_central_type->isChecked())
        projectionType = CENTRAL;

    // edge type
    if (ui->radioButton_edgeType_solid->isChecked())
        edgeType = SOLID;
    else
        edgeType = DASHED;

    edgeWidth = (float)ui->edgeThickness->value(); // можно флоут убрать? // нет, edgeThickness - int
    pointSize = (float)ui->vertexSize->value() * 2; // и тут флоут тоже? // и тут int

    if (ui->radioButton_vertexType_novertex->isChecked()) {
        pointVisibility = NOVERTEX;
    } else {
        pointVisibility = AVERTEX;

        if (ui->radioButton_vertexType_circle->isChecked())
            pointType = CIRCLE;
        else
            pointType = SQUARE;
    }
}

void viewer::setEdges() {
    // setting the edge type
    if (edgeType == DASHED) {
        glLineStipple(1, 0x3333); // 0x0101 - это шаблон для пунктирной линии, в котором пунктиры и промежутки имеют одинаковую длину.
        glEnable(GL_LINE_STIPPLE);
    } else if (edgeType == SOLID) {
        glDisable(GL_LINE_STIPPLE);
    }

    glLineWidth(edgeWidth); // setting the edge thickness
    glColor3f(edgeColor.redF(), edgeColor.greenF(), edgeColor.blueF()); // setting the edge color
    glDrawElements(GL_LINES, model.countIndex, GL_UNSIGNED_INT, model.vertexIndex);
}

void viewer::setVertices() {
    glPointSize(pointSize);
    glColor3f(vertexColor.redF(), vertexColor.greenF(), vertexColor.blueF());

    if (pointType == CIRCLE) {
        glEnable(GL_POINT_SMOOTH);
        glDrawArrays(GL_POINTS, 0, model.countVertex);
        glDisable(GL_POINT_SMOOTH);
    } else {
        glDrawArrays(GL_POINTS, 0, model.countVertex);
    }
}

void viewer::setProjectionType() {
    if (projectionType == PARALLEL) {
        glOrtho(-5, 5, -5, 5, 1, 15); //значения поменять? // glOrtho(-1, 1, -1, 1, -1, 1);
        glTranslated(0, 0, -10); // для чего-то муваем модель на -10 по z координате
    } else if (projectionType == CENTRAL) {
        glFrustum(-1, 1, -1, 1, 1, 15); // glFrustum(-0.1, 0.1, -0.075, 0.075, 0.1, 100.0);
        glTranslated(0, 0, -10); // для чего-то муваем модель на -10 по z координате
    }
}
