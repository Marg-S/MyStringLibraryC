#include "my_tests.h"

START_TEST(test_strrchr_valid) {
  const char* str = "Test string";
  int c = 116;  //'t'

  char* system_result = strrchr(str, c);
  char* my_result = my_strrchr(str, c);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strrchr_nomatch) {
  const char* str = "Test string";
  int c = '0';

  char* system_result = strrchr(str, c);
  char* my_result = my_strrchr(str, c);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strrchr_null_terminator) {
  const char* str = "Test string";
  int c = '\0';

  char* system_result = strrchr(str, c);
  char* my_result = my_strrchr(str, c);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

Suite* suite_strrchr(void) {
  Suite* suite = suite_create("my_strrchr");
  TCase* tc_my_strrchr;

  tc_my_strrchr = tcase_create("tc_my_strrchr");
  tcase_add_test(tc_my_strrchr, test_strrchr_valid);
  tcase_add_test(tc_my_strrchr, test_strrchr_nomatch);
  tcase_add_test(tc_my_strrchr, test_strrchr_null_terminator);
  suite_add_tcase(suite, tc_my_strrchr);

  return suite;
}