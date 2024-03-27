#include "my_tests.h"

START_TEST(test_strncmp_zero_bites) {
  const char *str1 = "Test string";
  const char *str2 = "Test";
  my_size_t n = 0;

  int system_result = strncmp(str1, str2, n);
  int my_result = my_strncmp(str1, str2, n);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strncmp_max_bites) {
  const char *str1 = "Test string";
  const char *str2 = "Test";
  my_size_t n = 6;

  int system_result = strncmp(str1, str2, n);
  int my_result = my_strncmp(str1, str2, n);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strncmp_exceed_bites) {
  const char *str1 = "Test";
  const char *str2 = "Test";
  my_size_t n = 9;

  int system_result = strncmp(str1, str2, n);
  int my_result = my_strncmp(str1, str2, n);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strncmp_smaller) {
  const char *str1 = "Test string";
  const char *str2 = "test";
  my_size_t n = 2;

  int system_result = strncmp(str1, str2, n);
  int my_result = my_strncmp(str1, str2, n);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strncmp_bigger) {
  const char *str1 = "Test string";
  const char *str2 = "Test";
  my_size_t n = 1;

  int system_result = strncmp(str1, str2, n);
  int my_result = my_strncmp(str1, str2, n);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strncmp_empty_str2) {
  const char *str1 = "Test string";
  const char *str2 = "";
  my_size_t n = 2;

  int system_result = strncmp(str1, str2, n);
  int my_result = my_strncmp(str1, str2, n);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strncmp_empty_str1) {
  const char *str1 = "";
  const char *str2 = "f";
  my_size_t n = 1;

  int system_result = strncmp(str1, str2, n);
  int my_result = my_strncmp(str1, str2, n);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *suite = suite_create("my_strncmp");
  TCase *tc_my_strncmp;

  tc_my_strncmp = tcase_create("tc_my_strncmp");
  tcase_add_test(tc_my_strncmp, test_strncmp_zero_bites);
  tcase_add_test(tc_my_strncmp, test_strncmp_max_bites);
  tcase_add_test(tc_my_strncmp, test_strncmp_exceed_bites);
  tcase_add_test(tc_my_strncmp, test_strncmp_smaller);
  tcase_add_test(tc_my_strncmp, test_strncmp_bigger);
  tcase_add_test(tc_my_strncmp, test_strncmp_empty_str2);
  tcase_add_test(tc_my_strncmp, test_strncmp_empty_str1);
  suite_add_tcase(suite, tc_my_strncmp);

  return suite;
}