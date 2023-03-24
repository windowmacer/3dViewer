#include "viewer.h"

void viewer::mouseMoveEvent(QMouseEvent *cursorPosition) {
    if (leftButton) {
        double rotateX = (cursorPosition->pos().x() - clickPosition.x()) / 10;
        double rotateY = (cursorPosition->pos().y() - clickPosition.y()) / 10;
        // rotateModel(&model, rotateX, X);
        // rotateModel(&model, rotateY, Y);
    } else if (rightButton) {
        double moveX = (cursorPosition->pos().x() - clickPosition.x()) / 10000.0;
        double moveY = (cursorPosition->pos().y() - clickPosition.y()) / 10000.0;
        // moveModel(&model, moveX, X);
        // moveModel(&model, moveY, Y);
    }

    // update();
}

void viewer::mousePressEvent(QMouseEvent *event) {
    clickPosition = event->pos();
    if (event->button() == Qt::LeftButton) {
        leftButton = true;
    } else if (event->button() == Qt::RightButton) {
        rightButton = true;
    }
}

void viewer::mouseReleaseEvent(QMouseEvent *cursorPosition) {
    leftButton = false;
    rightButton = false;
    cursorPosition->pos() = clickPosition;
}

void viewer::wheelEvent(QWheelEvent *event) {
    // сначала нужен прототип scaleModel()
    // double scaleValue = event->angleDelta().y() >= 0 ? 0 : 0;

    // scaleModel(&model, scaleValue);

    // update();
}

void viewer::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_G) {
        on_actionSave_as_GIF_triggered();
    } else if (event->key() == Qt::Key_J) {
        on_actionSave_as_jpeg_triggered();
    } else if (event->key() == Qt::Key_B) {
        on_actionSave_as_bmp_triggered();
    }
}
