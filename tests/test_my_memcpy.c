#include "my_tests.h"

START_TEST(test_memcpy_valid) {
  char dest[] = "Test string";
  char* src = "Copy";
  my_size_t n = 4;

  char* system_result = memcpy(dest, src, n);
  char* my_result = my_memcpy(dest, src, n);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_memcpy_zero_bytes) {
  char dest[] = "Test string";
  char* src = "Copy";
  my_size_t n = 0;

  char* system_result = memcpy(dest, src, n);
  char* my_result = my_memcpy(dest, src, n);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_memcpy_empty_dest) {
  char dest[5] = "";
  char* src = "Copy";
  my_size_t n = 2;

  char* system_result = memcpy(dest, src, n);
  char* my_result = my_memcpy(dest, src, n);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

START_TEST(test_memcpy_empty_src) {
  char dest[] = "Test string";
  char* src = "";
  my_size_t n = 0;

  char* system_result = memcpy(dest, src, n);
  char* my_result = my_memcpy(dest, src, n);

  ck_assert_ptr_eq(system_result, my_result);
}
END_TEST

Suite* suite_memcpy(void) {
  Suite* suite = suite_create("my_memcpy");
  TCase* tc_my_memcpy;

  tc_my_memcpy = tcase_create("tc_my_memcpy");
  tcase_add_test(tc_my_memcpy, test_memcpy_valid);
  tcase_add_test(tc_my_memcpy, test_memcpy_zero_bytes);
  tcase_add_test(tc_my_memcpy, test_memcpy_empty_dest);
  tcase_add_test(tc_my_memcpy, test_memcpy_empty_src);
  suite_add_tcase(suite, tc_my_memcpy);

  return suite;
}