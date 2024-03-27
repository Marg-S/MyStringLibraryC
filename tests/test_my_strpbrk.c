#include "my_tests.h"

START_TEST(test_my_strpbrk_find) {
  char *str1 = "Test string";
  char *str2 = "abcdefghijk";
  void *system_result = strpbrk(str1, str2);
  void *my_result = my_strpbrk(str1, str2);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strpbrk_no_find) {
  char *str1 = "Test string";
  char *str2 = "abcd";
  void *system_result = strpbrk(str1, str2);
  void *my_result = my_strpbrk(str1, str2);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strpbrk_one_symbol) {
  char *str1 = "Test string";
  char *str2 = "t";
  void *system_result = strpbrk(str1, str2);
  void *my_result = my_strpbrk(str1, str2);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *suite = suite_create("my_strpbrk_suite");
  TCase *tc_my_strpbrk;

  tc_my_strpbrk = tcase_create("my_strpbrk");
  tcase_add_test(tc_my_strpbrk, test_my_strpbrk_find);
  tcase_add_test(tc_my_strpbrk, test_my_strpbrk_no_find);
  tcase_add_test(tc_my_strpbrk, test_my_strpbrk_one_symbol);
  suite_add_tcase(suite, tc_my_strpbrk);

  return suite;
}