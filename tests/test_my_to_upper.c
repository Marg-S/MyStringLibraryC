#include "my_tests.h"

START_TEST(test_to_upper_1) {
  char str[] = "Test String";

  char* system_result = "TEST STRING";
  char* my_result = (char*)my_to_upper(str);

  ck_assert_str_eq(system_result, my_result);
  free(my_result);
}
END_TEST

START_TEST(test_to_upper_2) {
  const char str[40] = "TEST STRING";
  char* system_result = "TEST STRING";

  char* my_result = (char*)my_to_upper(str);

  ck_assert_str_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_to_upper_3) {
  const char str[40] = "\nh\t\\g123123";
  char* system_result = "\nH\t\\G123123";

  char* my_result = (char*)my_to_upper(str);

  ck_assert_str_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_to_upper_4) {
  const char str[40] = "";
  char* system_result = "";

  char* my_result = (char*)my_to_upper(str);

  ck_assert_str_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_to_upper_5) {
  const char str[40] = "test string";
  char* system_result = "TEST STRING";

  char* my_result = (char*)my_to_upper(str);

  ck_assert_str_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_to_upper_6) {
  const char* str = NULL;
  char* system_result = NULL;

  char* my_result = (char*)my_to_upper(str);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

Suite* suite_to_upper(void) {
  Suite* suite = suite_create("my_to_upper");
  TCase* tc_my_to_upper;

  tc_my_to_upper = tcase_create("tc_my_to_upper");
  tcase_add_test(tc_my_to_upper, test_to_upper_1);
  tcase_add_test(tc_my_to_upper, test_to_upper_2);
  tcase_add_test(tc_my_to_upper, test_to_upper_3);
  tcase_add_test(tc_my_to_upper, test_to_upper_4);
  tcase_add_test(tc_my_to_upper, test_to_upper_5);
  tcase_add_test(tc_my_to_upper, test_to_upper_6);

  suite_add_tcase(suite, tc_my_to_upper);

  return suite;
}