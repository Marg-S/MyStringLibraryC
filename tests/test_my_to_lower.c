#include "my_tests.h"

START_TEST(test_to_lower_1) {
  const char str[40] = "Test String";
  char* system_result = "test string";

  char* my_result = (char*)my_to_lower(str);

  ck_assert_str_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_to_lower_2) {
  const char str[40] = "test string";
  char* system_result = "test string";

  char* my_result = (char*)my_to_lower(str);

  ck_assert_str_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_to_lower_3) {
  const char str[40] = "\nH\t\\G123123";
  char* system_result = "\nh\t\\g123123";

  char* my_result = (char*)my_to_lower(str);

  ck_assert_str_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_to_lower_4) {
  const char str[40] = "";
  char* system_result = "";

  char* my_result = (char*)my_to_lower(str);

  ck_assert_str_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_to_lower_5) {
  const char str[40] = "TEST STRING";
  char* system_result = "test string";

  char* my_result = (char*)my_to_lower(str);

  ck_assert_str_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(test_to_lower_6) {
  const char* str = NULL;
  char* system_result = NULL;

  char* my_result = (char*)my_to_lower(str);

  ck_assert_pstr_eq(system_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

Suite* suite_to_lower(void) {
  Suite* suite = suite_create("my_to_lower");
  TCase* tc_my_to_lower;

  tc_my_to_lower = tcase_create("tc_my_to_lower");
  tcase_add_test(tc_my_to_lower, test_to_lower_1);
  tcase_add_test(tc_my_to_lower, test_to_lower_2);
  tcase_add_test(tc_my_to_lower, test_to_lower_3);
  tcase_add_test(tc_my_to_lower, test_to_lower_4);
  tcase_add_test(tc_my_to_lower, test_to_lower_5);
  tcase_add_test(tc_my_to_lower, test_to_lower_6);
  suite_add_tcase(suite, tc_my_to_lower);

  return suite;
}