#include "my_tests.h"

START_TEST(test_memchr_match) {
  const char *str = "Test string";
  my_size_t n = 10;
  int c = 116;  //'t'

  void *system_result = memchr(str, c, n);
  void *my_result = my_memchr(str, c, n);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_memchr_nomatch) {
  my_size_t n = 10;
  char *str = "Test string";
  int c = '0';

  void *system_result = memchr(str, c, n);
  void *my_result = my_memchr(str, c, n);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_memchr_exceed) {
  my_size_t n = 20;
  char *str = "Test string";
  int c = 116;  //'t'

  void *system_result = memchr(str, c, n);
  void *my_result = my_memchr(str, c, n);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_memchr_last_char) {
  my_size_t n = 20;
  char *str = "Test string";
  int c = 103;  //'g'

  void *system_result = memchr(str, c, n);
  void *my_result = my_memchr(str, c, n);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

Suite *suite_memchr(void) {
  Suite *suite = suite_create("my_memchr");
  TCase *tc_my_memchr;

  tc_my_memchr = tcase_create("tc_my_memchr");
  tcase_add_test(tc_my_memchr, test_memchr_match);
  tcase_add_test(tc_my_memchr, test_memchr_nomatch);
  tcase_add_test(tc_my_memchr, test_memchr_exceed);
  tcase_add_test(tc_my_memchr, test_memchr_last_char);
  suite_add_tcase(suite, tc_my_memchr);

  return suite;
}