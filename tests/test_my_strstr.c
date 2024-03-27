#include "my_tests.h"

START_TEST(test_my_strstr_find_middle) {
  char *haystack = "Test string";
  char *needle = "str";
  void *system_result = strstr(haystack, needle);
  void *my_result = my_strstr(haystack, needle);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strstr_find_first) {
  char *haystack = "Test string";
  char *needle = "Test";
  void *system_result = strstr(haystack, needle);
  void *my_result = my_strstr(haystack, needle);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strstr_find_end) {
  char *haystack = "Test string";
  char *needle = "ring";
  void *system_result = strstr(haystack, needle);
  void *my_result = my_strstr(haystack, needle);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strstr_no_find) {
  char *haystack = "Test string";
  char *needle = "abc";
  void *system_result = strstr(haystack, needle);
  void *my_result = my_strstr(haystack, needle);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strstr_one_needle) {
  char *haystack = "Test string";
  char *needle = " ";
  void *system_result = strstr(haystack, needle);
  void *my_result = my_strstr(haystack, needle);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strstr_one_haystack) {
  char *haystack = "T";
  char *needle = "Test";
  void *system_result = strstr(haystack, needle);
  void *my_result = my_strstr(haystack, needle);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strstr_empty_needle) {
  char *haystack = "Test string";
  char *needle = "";
  void *system_result = strstr(haystack, needle);
  void *my_result = my_strstr(haystack, needle);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strstr_empty_haystack) {
  char *haystack = "";
  char *needle = "Test";
  void *system_result = strstr(haystack, needle);
  void *my_result = my_strstr(haystack, needle);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_strstr_both_empty) {
  char *haystack = "";
  char *needle = "";
  void *system_result = strstr(haystack, needle);
  void *my_result = my_strstr(haystack, needle);
  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

Suite *suite_strstr(void) {
  Suite *suite = suite_create("my_strstr_suite");
  TCase *tc_my_strstr;

  tc_my_strstr = tcase_create("my_strstr");
  tcase_add_test(tc_my_strstr, test_my_strstr_find_middle);
  tcase_add_test(tc_my_strstr, test_my_strstr_find_first);
  tcase_add_test(tc_my_strstr, test_my_strstr_find_end);
  tcase_add_test(tc_my_strstr, test_my_strstr_no_find);
  tcase_add_test(tc_my_strstr, test_my_strstr_one_needle);
  tcase_add_test(tc_my_strstr, test_my_strstr_one_haystack);
  tcase_add_test(tc_my_strstr, test_my_strstr_empty_needle);
  tcase_add_test(tc_my_strstr, test_my_strstr_empty_haystack);
  tcase_add_test(tc_my_strstr, test_my_strstr_both_empty);
  suite_add_tcase(suite, tc_my_strstr);

  return suite;
}