#include "my_tests.h"

START_TEST(test_my_strncpy_equal_length) {
  const char *src = "Test string";
  my_size_t n = strlen(src);
  char dest[n];
  void *system_result = strncpy(dest, src, n);
  void *my_result = my_strncpy(dest, src, n);
  ck_assert_ptr_eq(system_result, my_result);
  ck_assert_str_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strncpy_undo_length) {
  const char *src = "Test string";
  my_size_t n = strlen(src) / 2;
  char dest[n * 2];
  void *system_result = strncpy(dest, src, n);
  void *my_result = my_strncpy(dest, src, n);
  ck_assert_ptr_eq(system_result, my_result);
  ck_assert_str_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strncpy_over_length) {
  const char *src = "Test string";
  my_size_t n = strlen(src) * 2;
  char dest[n];
  void *system_result = strncpy(dest, src, n);
  void *my_result = my_strncpy(dest, src, n);
  ck_assert_ptr_eq(system_result, my_result);
  ck_assert_str_eq(system_result, my_result);
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *suite = suite_create("my_strncpy_suite");
  TCase *tc_my_strncpy;

  tc_my_strncpy = tcase_create("my_strncpy");
  tcase_add_test(tc_my_strncpy, test_my_strncpy_equal_length);
  tcase_add_test(tc_my_strncpy, test_my_strncpy_undo_length);
  tcase_add_test(tc_my_strncpy, test_my_strncpy_over_length);
  suite_add_tcase(suite, tc_my_strncpy);

  return suite;
}