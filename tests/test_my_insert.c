#include "my_tests.h"

START_TEST(test_insert_1) {
  const char src[40] = "Test string";
  const char *str = "?!.";
  size_t n = 11;
  char *system_result = "Test string?!.";

  void *my_result = my_insert(src, str, n);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_insert_2) {
  const char src[40] = "Test string";
  const char *str = "?!.";
  size_t n = 0;
  char *system_result = "?!.Test string";

  void *my_result = my_insert(src, str, n);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_insert_13) {
  const char src[40] = "Test string";
  const char *str = "?!.";
  size_t n = 4;
  char *system_result = "Test?!. string";

  void *my_result = my_insert(src, str, n);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_insert_3_empty_src) {
  const char src[40] = "";
  const char *str = "?!.";
  size_t n = 4;
  char *system_result = NULL;

  void *my_result = my_insert(src, str, n);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_insert_4_empty_src) {
  const char src[40] = "";
  const char *str = "?!.";
  size_t n = 0;
  char *system_result = "?!.";

  void *my_result = my_insert(src, str, n);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_insert_5_empty_str) {
  const char src[40] = "Test string";
  const char *str = "";
  size_t n = 4;
  char *system_result = "Test string";

  void *my_result = my_insert(src, str, n);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_insert_6_empty_str) {
  const char src[40] = "Test string";
  const char *str = "";
  size_t n = 0;
  char *system_result = "Test string";

  void *my_result = my_insert(src, str, n);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_insert_7_both_empty) {
  const char src[40] = "";
  const char *str = "";
  size_t n = 0;
  char *system_result = "";

  void *my_result = my_insert(src, str, n);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_insert_8_both_empty) {
  const char src[40] = "";
  const char *str = "";
  size_t n = 4;
  char *system_result = NULL;

  void *my_result = my_insert(src, str, n);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_insert_9_null_str) {
  const char src[40] = "Test string";
  const char *str = NULL;
  size_t n = 4;
  char *system_result = NULL;

  void *my_result = my_insert(src, str, n);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_insert_10_null_src) {
  const char *src = NULL;
  const char *str = ".";
  size_t n = 4;
  char *system_result = NULL;

  void *my_result = my_insert(src, str, n);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_insert_11) {
  const char src[40] = "Test string";
  const char *str = ".";
  size_t n = 12;
  char *system_result = NULL;

  void *my_result = my_insert(src, str, n);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_insert_12) {
  const char src[40] = "Test string";
  const char *str = "\'INSERT\'";
  size_t n = 4;
  char *system_result = "Test\'INSERT\' string";

  void *my_result = my_insert(src, str, n);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

Suite *suite_insert(void) {
  Suite *suite = suite_create("my_insert");
  TCase *tc_my_insert;

  tc_my_insert = tcase_create("tc_my_insert");
  tcase_add_test(tc_my_insert, test_insert_1);
  tcase_add_test(tc_my_insert, test_insert_2);
  tcase_add_test(tc_my_insert, test_insert_3_empty_src);
  tcase_add_test(tc_my_insert, test_insert_4_empty_src);
  tcase_add_test(tc_my_insert, test_insert_5_empty_str);
  tcase_add_test(tc_my_insert, test_insert_6_empty_str);
  tcase_add_test(tc_my_insert, test_insert_7_both_empty);
  tcase_add_test(tc_my_insert, test_insert_8_both_empty);
  tcase_add_test(tc_my_insert, test_insert_9_null_str);
  tcase_add_test(tc_my_insert, test_insert_10_null_src);
  tcase_add_test(tc_my_insert, test_insert_11);
  tcase_add_test(tc_my_insert, test_insert_12);
  tcase_add_test(tc_my_insert, test_insert_13);

  suite_add_tcase(suite, tc_my_insert);

  return suite;
}