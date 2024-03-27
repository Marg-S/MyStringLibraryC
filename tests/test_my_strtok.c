#include "my_tests.h"

START_TEST(test_strtok_one_char) {
  char str1[] = "Test string";
  char str2[] = "Test string";
  char* delim = " ";

  char* system_result = strtok(str1, delim);
  char* my_result = my_strtok(str2, delim);

  while (system_result != NULL && my_result != NULL) {
    ck_assert_str_eq(system_result, my_result);
    system_result = strtok(NULL, delim);
    my_result = my_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(test_strtok_two_char) {
  char str1[] = "Test string";
  char str2[] = "Test string";
  char* delim = "es";

  char* system_result = strtok(str1, delim);
  char* my_result = my_strtok(str2, delim);

  while (system_result != NULL || my_result != NULL) {
    ck_assert_str_eq(system_result, my_result);
    system_result = strtok(NULL, delim);
    my_result = my_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(test_strtok_empty_delim) {
  char str1[] = "Test string";
  char str2[] = "Test string";
  char* delim = "";

  char* system_result = strtok(str1, delim);
  char* my_result = my_strtok(str2, delim);

  while (system_result != NULL || my_result != NULL) {
    ck_assert_str_eq(system_result, my_result);
    system_result = strtok(NULL, delim);
    my_result = my_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(test_strtok_empty_string) {
  char str1[] = "";
  char str2[] = "";
  char* delim = "/";

  char* system_result = strtok(str1, delim);
  char* my_result = my_strtok(str2, delim);

  while (system_result != NULL || my_result != NULL) {
    ck_assert_str_eq(system_result, my_result);
    system_result = strtok(NULL, delim);
    my_result = my_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(test_strtok_nomatch) {
  char str1[] = "Test string";
  char str2[] = "Test string";
  char* delim = ".";

  char* system_result = strtok(str1, delim);
  char* my_result = my_strtok(str2, delim);

  while (system_result != NULL || my_result != NULL) {
    ck_assert_str_eq(system_result, my_result);
    system_result = strtok(NULL, delim);
    my_result = my_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(test_strtok_start_with_delim) {
  char str1[] = ".....Test string";
  char str2[] = ".....Test string";
  char* delim = ".";

  char* system_result = strtok(str1, delim);
  char* my_result = my_strtok(str2, delim);

  while (system_result != NULL || my_result != NULL) {
    ck_assert_str_eq(system_result, my_result);
    system_result = strtok(NULL, delim);
    my_result = my_strtok(NULL, delim);
  }
}
END_TEST

Suite* suite_strtok(void) {
  Suite* suite = suite_create("my_strtok");
  TCase* tc_my_strtok;

  tc_my_strtok = tcase_create("tc_my_strtok");
  tcase_add_test(tc_my_strtok, test_strtok_one_char);
  tcase_add_test(tc_my_strtok, test_strtok_two_char);
  tcase_add_test(tc_my_strtok, test_strtok_empty_delim);
  tcase_add_test(tc_my_strtok, test_strtok_empty_string);
  tcase_add_test(tc_my_strtok, test_strtok_nomatch);
  tcase_add_test(tc_my_strtok, test_strtok_start_with_delim);
  suite_add_tcase(suite, tc_my_strtok);

  return suite;
}