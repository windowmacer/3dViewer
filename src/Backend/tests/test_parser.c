#include "test_core.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <check.h>

START_TEST(parseCubeVertex) {
    structRoot object;
    int result = parser("/home/lunarskii/project/3dViewer/src/GUI/models/cottage.obj", &object);

    ck_assert_int_eq(object.countVertex, 353);
    ck_assert_int_eq(result, 0);

    free(object.vertexCoord);
	free(object.vertexIndex);
}
END_TEST

START_TEST(parseCubeFacets) {
    structRoot object;
    int result = parser("/home/lunarskii/project/3dViewer/src/GUI/models/cube.obj", &object);

    ck_assert_int_eq(object.countVertex, 8);
    ck_assert_int_eq(result, 0);

    free(object.vertexCoord);
	free(object.vertexIndex);
}
END_TEST

START_TEST(parseCubeInvalid) {
    structRoot object;
    int result = parser("models/testCubeInvalid", &object); 

    ck_assert_int_eq(result, ERROR_WRONG_FILENAME_EXTENSION);
}
END_TEST

START_TEST(parseCubeInvalidOBG) {
    structRoot object;
    int result = parser("models/testCubeInvalid.obj", &object);

    ck_assert_int_eq(result, ERROR_WRONG_FILENAME);
}
END_TEST

Suite *st_parse(void) {
    Suite *s = suite_create("st_parse");
    TCase *tc = tcase_create("parse_tc");

    tcase_add_test(tc, parseCubeVertex);
    tcase_add_test(tc, parseCubeFacets);
    tcase_add_test(tc, parseCubeInvalid);
    tcase_add_test(tc, parseCubeInvalidOBG);

    suite_add_tcase(s, tc);
    return s;
}