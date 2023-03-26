#include "test_core.h"

START_TEST(MOVING1) {
    structRoot model;
    structRoot testModel;
    parser("/home/lunarskii/project/3dViewer/src/GUI/models/cube.obj", &model);
    parser("/home/lunarskii/project/3dViewer/src/GUI/models/cube.obj", &testModel);

    moveModel(&model, 1, 2, 3);

    for (int i = 0; i < testModel.countVertex * 3; i += 3) {
        testModel.vertexCoord[i] += 1;
        testModel.vertexCoord[i + 1] += 2;
        testModel.vertexCoord[i + 2] += 3;
    }

    for (int i = 0; i < model.countVertex * 3; i++) {
        // printf("i = %d, model = %f, testModel = %f\n", i, model.vertexCoord[i], testModel.vertexCoord[i]);
        ck_assert_double_eq(model.vertexCoord[i], testModel.vertexCoord[i]);
    }

    free(model.vertexCoord);
	free(model.vertexIndex);
    free(testModel.vertexCoord);
	free(testModel.vertexIndex);
} END_TEST

START_TEST(ROTATION1) {
    structRoot model;
    structRoot testModel;
    double angle = 15;
    parser("/home/lunarskii/project/3dViewer/src/GUI/models/cube.obj", &model);
    parser("/home/lunarskii/project/3dViewer/src/GUI/models/cube.obj", &testModel);

    rotateModel(&model, angle, 1);

    angle *= PI / 180;
    for (int i = 1; i < testModel.countVertex * 3; i += 3) {
        double cosValue = cos(angle);
        double sinValue = sin(angle);

        testModel.vertexCoord[i]     = cosValue * testModel.vertexCoord[i] - sinValue * testModel.vertexCoord[i + 1];
        testModel.vertexCoord[i + 1] = sinValue * testModel.vertexCoord[i] + cosValue * testModel.vertexCoord[i + 1];
    }

    for (int i = 0; i < model.countVertex * 3; i++) {
        ck_assert_double_eq(model.vertexCoord[i], testModel.vertexCoord[i]);
    }

    free(model.vertexCoord);
	free(model.vertexIndex);
    free(testModel.vertexCoord);
	free(testModel.vertexIndex);
} END_TEST

START_TEST(ROTATION2) {
    structRoot model;
    structRoot testModel;
    double angle = 15;
    parser("/home/lunarskii/project/3dViewer/src/GUI/models/cube.obj", &model);
    parser("/home/lunarskii/project/3dViewer/src/GUI/models/cube.obj", &testModel);

    rotateModel(&model, angle, 2);

    angle *= PI / 180;
    for (int i = 0; i < testModel.countVertex * 3; i += 3) {
        double cosValue = cos(angle);
        double sinValue = sin(angle);

        testModel.vertexCoord[i]     = cosValue * testModel.vertexCoord[i] + sinValue * testModel.vertexCoord[i + 2];
        testModel.vertexCoord[i + 2] =-sinValue * testModel.vertexCoord[i] + cosValue * testModel.vertexCoord[i + 2];
    }

    for (int i = 0; i < model.countVertex * 3; i++) {
        ck_assert_double_eq(model.vertexCoord[i], testModel.vertexCoord[i]);
    }

    free(model.vertexCoord);
	free(model.vertexIndex);
    free(testModel.vertexCoord);
	free(testModel.vertexIndex);
} END_TEST

START_TEST(ROTATION3) {
    structRoot model;
    structRoot testModel;
    double angle = 15;
    parser("/home/lunarskii/project/3dViewer/src/GUI/models/cube.obj", &model);
    parser("/home/lunarskii/project/3dViewer/src/GUI/models/cube.obj", &testModel);

    rotateModel(&model, angle, 3);

    angle *= PI / 180;
    for (int i = 0; i < testModel.countVertex * 3; i += 3) {
        double cosValue = cos(angle);
        double sinValue = sin(angle);

        testModel.vertexCoord[i]     = cosValue * testModel.vertexCoord[i] - sinValue * testModel.vertexCoord[i + 1];
        testModel.vertexCoord[i + 1] = sinValue * testModel.vertexCoord[i] + cosValue * testModel.vertexCoord[i + 1];
    }

    for (int i = 0; i < model.countVertex * 3; i++) {
        ck_assert_double_eq(model.vertexCoord[i], testModel.vertexCoord[i]);
    }

    free(model.vertexCoord);
	free(model.vertexIndex);
    free(testModel.vertexCoord);
	free(testModel.vertexIndex);
} END_TEST

START_TEST(SCALING1) {
    structRoot model;
    structRoot testModel;
    double scale = 10;
    parser("/home/lunarskii/project/3dViewer/src/GUI/models/cube.obj", &model);
    parser("/home/lunarskii/project/3dViewer/src/GUI/models/cube.obj", &testModel);

    scaleModel(&model, scale);

    for (int i = 0; i < testModel.countVertex * 3; i++) {
        testModel.vertexCoord[i] += scale / 100 * testModel.vertexCoord[i];
    }

    for (int i = 0; i < model.countVertex * 3; i++) {
        ck_assert_double_eq(model.vertexCoord[i], testModel.vertexCoord[i]);
    }

    free(model.vertexCoord);
	free(model.vertexIndex);
    free(testModel.vertexCoord);
	free(testModel.vertexIndex);
} END_TEST

START_TEST(SCALING2) {
    structRoot model;
    structRoot testModel;
    double scale = -10;
    parser("/home/lunarskii/project/3dViewer/src/GUI/models/cube.obj", &model);
    parser("/home/lunarskii/project/3dViewer/src/GUI/models/cube.obj", &testModel);

    scaleModel(&model, scale);

    for (int i = 0; i < testModel.countVertex * 3; i++) {
        testModel.vertexCoord[i] += scale / 100 * testModel.vertexCoord[i];
    }

    for (int i = 0; i < model.countVertex * 3; i++) {
        ck_assert_double_eq(model.vertexCoord[i], testModel.vertexCoord[i]);
    }

    free(model.vertexCoord);
	free(model.vertexIndex);
    free(testModel.vertexCoord);
	free(testModel.vertexIndex);
} END_TEST

Suite *st_affine(void) {
    Suite *s = suite_create("st_affine");
    TCase *tc = tcase_create("affine_tc");

    tcase_add_test(tc, MOVING1);
    tcase_add_test(tc, ROTATION1);
    tcase_add_test(tc, ROTATION2);
    tcase_add_test(tc, ROTATION3);
    tcase_add_test(tc, SCALING1);
    tcase_add_test(tc, SCALING2);

    suite_add_tcase(s, tc);
    return s;
}