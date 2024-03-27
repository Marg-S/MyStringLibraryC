#include "my_tests.h"

START_TEST(test_trim_1) {
  const char *src = "   Test...   ";
  const char *str = " .";
  char *system_result = "Test";

  char *my_result = (char *)my_trim(src, str);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_trim_2) {
  const char *src = "   Test string...   ";
  const char *str = " .";
  char *system_result = "Test string";

  char *my_result = (char *)my_trim(src, str);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_trim_3_empty_str) {
  const char *src = "   Test...   ";
  const char *str = "";
  char *system_result = "   Test...   ";

  char *my_result = (char *)my_trim(src, str);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_trim_4_empty_src) {
  const char *src = "";
  const char *str = " .";
  char *system_result = "";

  char *my_result = (char *)my_trim(src, str);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_trim_5_both_empty) {
  const char *src = "";
  const char *str = "";
  char *system_result = "";

  char *my_result = (char *)my_trim(src, str);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_trim_6_null_str) {
  const char *src = "   Test...   ";
  const char *str = NULL;
  char *system_result = "   Test...   ";

  char *my_result = (char *)my_trim(src, str);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_trim_7_null_src) {
  const char *src = NULL;
  const char *str = " .";
  char *system_result = NULL;

  char *my_result = (char *)my_trim(src, str);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_trim_8_both_null) {
  const char *src = NULL;
  const char *str = NULL;
  char *system_result = NULL;

  char *my_result = (char *)my_trim(src, str);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_trim_9) {
  const char *src = "?   ?Test...?   ?";
  const char *str = "?";
  char *system_result = "   ?Test...?   ";

  char *my_result = (char *)my_trim(src, str);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_trim_10) {
  const char *src = "Test string ?!....??";
  const char *str = "?!.";
  char *system_result = "Test string ";

  char *my_result = (char *)my_trim(src, str);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

Suite *suite_trim(void) {
  Suite *suite = suite_create("my_trim");
  TCase *tc_my_trim;

  tc_my_trim = tcase_create("tc_my_trim");
  tcase_add_test(tc_my_trim, test_trim_1);
  tcase_add_test(tc_my_trim, test_trim_2);
  tcase_add_test(tc_my_trim, test_trim_3_empty_str);
  tcase_add_test(tc_my_trim, test_trim_4_empty_src);
  tcase_add_test(tc_my_trim, test_trim_5_both_empty);
  tcase_add_test(tc_my_trim, test_trim_6_null_str);
  tcase_add_test(tc_my_trim, test_trim_7_null_src);
  tcase_add_test(tc_my_trim, test_trim_8_both_null);
  tcase_add_test(tc_my_trim, test_trim_9);
  tcase_add_test(tc_my_trim, test_trim_10);

  suite_add_tcase(suite, tc_my_trim);

  return suite;
}