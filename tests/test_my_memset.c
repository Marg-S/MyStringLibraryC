#include "my_tests.h"

START_TEST(test_my_memset_norm) {
  int c = '_';
  my_size_t n = 10;
  char str[] = "Test string", my_str[] = "Test string";
  void *my_result = my_memset(str, c, n);
  strcpy(my_str, str);
  void *system_result = memset(str, c, n);
  ck_assert_ptr_eq(system_result, my_result);
  ck_assert_str_eq(str, my_str);
}
END_TEST

START_TEST(test_my_memset_X) {
  int c = 'X';
  my_size_t n = 10;
  char str[] = "Test string", my_str[] = "Test string";
  void *my_result = my_memset(str, c, n);
  strcpy(my_str, str);
  void *system_result = memset(str, c, n);
  ck_assert_ptr_eq(system_result, my_result);
  ck_assert_str_eq(str, my_str);
}
END_TEST

Suite *suite_memset(void) {
  Suite *suite = suite_create("my_memset_suite");
  TCase *tc_my_memset;

  tc_my_memset = tcase_create("my_memset");
  tcase_add_test(tc_my_memset, test_my_memset_norm);
  tcase_add_test(tc_my_memset, test_my_memset_X);
  suite_add_tcase(suite, tc_my_memset);

  return suite;
}