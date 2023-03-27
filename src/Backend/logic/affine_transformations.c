#include <stdio.h>
#include <math.h>

#include "parser_obj.h"

void moveModel(structRoot *model, double stepX, double stepY, double stepZ) {
    for (int i = 0; i < model->countVertex * 3; i += 3) {
        model->vertexCoord[i] += stepX;
        model->vertexCoord[i + 1] += stepY;
        model->vertexCoord[i + 2] += stepZ;
    }
}

void rotateModel(structRoot *model, double angle, int axis) {
    angle *= PI / 180;
    double cosValue = cos(angle);
    double sinValue = sin(angle);
    
    for (int i = (axis == X) ? 1 : 0; i < model->countVertex * 3; i += 3) {
        if (axis == X) {
            double y = model->vertexCoord[i];

            model->vertexCoord[i]     = cosValue * y - sinValue * model->vertexCoord[i + 1];
            model->vertexCoord[i + 1] = sinValue * y + cosValue * model->vertexCoord[i + 1];
        } else if (axis == Y) {
            double x = model->vertexCoord[i];

            model->vertexCoord[i]     = cosValue * x + sinValue * model->vertexCoord[i + 2];
            model->vertexCoord[i + 2] =-sinValue * x + cosValue * model->vertexCoord[i + 2];
        } else if (axis == Z) {
            double x = model->vertexCoord[i];

            model->vertexCoord[i]     = cosValue * x - sinValue * model->vertexCoord[i + 1];
            model->vertexCoord[i + 1] = sinValue * x + cosValue * model->vertexCoord[i + 1];
        }
    }
}

void scaleModel(structRoot *model, double scale) {
    for (int i = 0; i < model->countVertex * 3; i++) {
        model->vertexCoord[i] += scale / 100 * model->vertexCoord[i];
    }
}
