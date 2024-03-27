#include "my_tests.h"

START_TEST(test_my_strchr_start) {
  char *str = "Test string";
  int c = 'T';
  void *system_result = strchr(str, c);
  void *my_result = my_strchr(str, c);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strchr_middle) {
  char *str = "Test string";
  int c = ' ';
  void *system_result = strchr(str, c);
  void *my_result = my_strchr(str, c);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strchr_end) {
  char *str = "Test string";
  int c = 'g';
  void *system_result = strchr(str, c);
  void *my_result = my_strchr(str, c);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strchr_no_symbol) {
  char *str = "Test string";
  int c = 'z';
  void *system_result = strchr(str, c);
  void *my_result = my_strchr(str, c);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strchr_null_terminator) {
  char *str = "Test string";
  int c = '\0';
  void *system_result = strchr(str, c);
  void *my_result = my_strchr(str, c);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

Suite *suite_strchr(void) {
  Suite *suite = suite_create("my_strchr_suite");
  TCase *tc_my_strchr;

  tc_my_strchr = tcase_create("my_strchr");
  tcase_add_test(tc_my_strchr, test_my_strchr_start);
  tcase_add_test(tc_my_strchr, test_my_strchr_middle);
  tcase_add_test(tc_my_strchr, test_my_strchr_end);
  tcase_add_test(tc_my_strchr, test_my_strchr_no_symbol);
  tcase_add_test(tc_my_strchr, test_my_strchr_null_terminator);
  suite_add_tcase(suite, tc_my_strchr);

  return suite;
}