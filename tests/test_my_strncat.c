#include "my_tests.h"

START_TEST(test_strncat_valid) {
  char dest[20] = "Test string";
  const char* src = "Add";
  my_size_t n = 3;

  char* system_result = strncat(dest, src, n);
  char* my_result = my_strncat(dest, src, n);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strncat_exceed_bytes) {
  char dest[20] = "Test string";
  const char* src = "Add";
  my_size_t n = 10;

  char* system_result = strncat(dest, src, n);
  char* my_result = my_strncat(dest, src, n);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strncat_empty_dest) {
  char dest[15] = {'\0'};
  const char* src = "Add";
  my_size_t n = 10;

  char* system_result = strncat(dest, src, n);
  char* my_result = my_strncat(dest, src, n);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strncat_empty_src) {
  char dest[15] = "Test string";
  const char* src = "";
  my_size_t n = 10;

  char* system_result = strncat(dest, src, n);
  char* my_result = my_strncat(dest, src, n);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_strncat_zero_bytes) {
  char dest[15] = "Test string";
  const char* src = "Add";
  my_size_t n = 0;

  char* system_result = strncat(dest, src, n);
  char* my_result = my_strncat(dest, src, n);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

Suite* suite_strncat(void) {
  Suite* suite = suite_create("my_strncat");
  TCase* tc_my_strncat;

  tc_my_strncat = tcase_create("tc_my_strncat");
  tcase_add_test(tc_my_strncat, test_strncat_valid);
  tcase_add_test(tc_my_strncat, test_strncat_exceed_bytes);
  tcase_add_test(tc_my_strncat, test_strncat_empty_dest);
  tcase_add_test(tc_my_strncat, test_strncat_empty_src);
  tcase_add_test(tc_my_strncat, test_strncat_zero_bytes);
  suite_add_tcase(suite, tc_my_strncat);

  return suite;
}