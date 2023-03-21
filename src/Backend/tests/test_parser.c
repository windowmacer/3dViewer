#include "test_core.h"

START_TEST(TEST_PARSE1) {
    // здесь тесты

    // например:
    // int x = 5;
    // x += 5;
    // ck_assert_int_eq(x, 10); где int - тип данных для сравнения, eq - equal(проверка на равенство)
} END_TEST

START_TEST(TEST_PARSE2) {
    // здесь тесты
} END_TEST

Suite *st_parse(void) {
  Suite *s = suite_create("st_parse");
  TCase *tc = tcase_create("parse_tc");

    // tc - название группы тестов, TEST_PARSE* - название теста
  tcase_add_test(tc, TEST_PARSE1);
  tcase_add_test(tc, TEST_PARSE2);

  suite_add_tcase(s, tc);
  return s;
}
