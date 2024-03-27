#include "my_tests.h"

START_TEST(test_my_memcmp_equal_n10) {
  const char *str1 = "Test string 1";
  const char *str2 = "Test string 2";
  my_size_t n = 10;
  int system_result = memcmp(str1, str2, n);
  int my_result = my_memcmp(str1, str2, n);
  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_memcmp_nonequal_n10) {
  const char *str1 = "Test string";
  const char *str2 = "Test another string";
  my_size_t n = 10;
  int system_result = memcmp(str1, str2, n);
  int my_result = my_memcmp(str1, str2, n);
  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_memcmp_empty_n10) {
  const char *str1 = "";
  const char *str2 = "Test string";
  my_size_t n = 10;
  int system_result = memcmp(str1, str2, n);
  int my_result = my_memcmp(str1, str2, n);
  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_memcmp_over_n20) {
  const char *str1 = "Test string 1";
  const char *str2 = "Test string 2";
  my_size_t n = 20;
  int system_result = memcmp(str1, str2, n);
  int my_result = my_memcmp(str1, str2, n);
  ck_assert_int_eq(system_result, my_result);
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *suite = suite_create("my_memcmp_suite");
  TCase *tc_my_memcmp;

  tc_my_memcmp = tcase_create("my_memcmp");
  tcase_add_test(tc_my_memcmp, test_my_memcmp_equal_n10);
  tcase_add_test(tc_my_memcmp, test_my_memcmp_nonequal_n10);
  tcase_add_test(tc_my_memcmp, test_my_memcmp_empty_n10);
  tcase_add_test(tc_my_memcmp, test_my_memcmp_over_n20);
  suite_add_tcase(suite, tc_my_memcmp);

  return suite;
}