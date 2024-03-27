#include "my_tests.h"

START_TEST(test_strcspn_valid) {
  char *str1 = "test75";
  char *str2 = "1234567890";

  size_t system_result = strcspn(str1, str2);
  my_size_t my_result = my_strcspn(str1, str2);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strcspn_empty_str1) {
  char *str1 = "";
  char *str2 = "1234567890";

  size_t system_result = strcspn(str1, str2);
  my_size_t my_result = my_strcspn(str1, str2);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strcspn_empty_str2) {
  char *str1 = "test75";
  char *str2 = "";

  size_t system_result = strcspn(str1, str2);
  my_size_t my_result = my_strcspn(str1, str2);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strcspn_first_char) {
  char *str1 = "0test75";
  char *str2 = "1234567890";

  size_t system_result = strcspn(str1, str2);
  my_size_t my_result = my_strcspn(str1, str2);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strcspn_last_char) {
  char *str1 = "test5";
  char *str2 = "1234567890";

  size_t system_result = strcspn(str1, str2);
  my_size_t my_result = my_strcspn(str1, str2);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strcspn_nomatch) {
  char *str1 = "test";
  char *str2 = "1234567890";

  size_t system_result = strcspn(str1, str2);
  my_size_t my_result = my_strcspn(str1, str2);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *suite = suite_create("my_strcspn");
  TCase *tc_my_strcspn;

  tc_my_strcspn = tcase_create("tc_my_strcspn");
  tcase_add_test(tc_my_strcspn, test_strcspn_valid);
  tcase_add_test(tc_my_strcspn, test_strcspn_empty_str1);
  tcase_add_test(tc_my_strcspn, test_strcspn_empty_str2);
  tcase_add_test(tc_my_strcspn, test_strcspn_first_char);
  tcase_add_test(tc_my_strcspn, test_strcspn_last_char);
  tcase_add_test(tc_my_strcspn, test_strcspn_nomatch);
  suite_add_tcase(suite, tc_my_strcspn);

  return suite;
}