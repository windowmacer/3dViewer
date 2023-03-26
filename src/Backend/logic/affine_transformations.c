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
            model->vertexCoord[i]     = cosValue * model->vertexCoord[i] - sinValue * model->vertexCoord[i + 1];
            model->vertexCoord[i + 1] = sinValue * model->vertexCoord[i] + cosValue * model->vertexCoord[i + 1];
        } else if (axis == Y) {
            model->vertexCoord[i]     = cosValue * model->vertexCoord[i] + sinValue * model->vertexCoord[i + 2];
            model->vertexCoord[i + 2] =-sinValue * model->vertexCoord[i] + cosValue * model->vertexCoord[i + 2];
        } else if (axis == Z) {
            model->vertexCoord[i]     = cosValue * model->vertexCoord[i] - sinValue * model->vertexCoord[i + 1];
            model->vertexCoord[i + 1] = sinValue * model->vertexCoord[i] + cosValue * model->vertexCoord[i + 1];
        }
    }
}

void scaleModel(structRoot *model, double scale) {
    for (int i = 0; i < model->countVertex * 3; i++) {
        model->vertexCoord[i] += scale / 100 * model->vertexCoord[i];
    }
}
