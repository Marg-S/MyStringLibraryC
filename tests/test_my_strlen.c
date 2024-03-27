#include "my_tests.h"

START_TEST(test_strlen_nonempty) {
  const char *str = "Test string";
  size_t size = strlen(str);
  my_size_t my_size = my_strlen(str);
  ck_assert_int_eq(size, my_size);
}
END_TEST

START_TEST(test_strlen_empty) {
  const char *str = "";
  size_t size = strlen(str);
  my_size_t my_size = my_strlen(str);
  ck_assert_int_eq(size, my_size);
}
END_TEST

Suite *suite_strlen(void) {
  Suite *suite = suite_create("my_string");
  TCase *tc_my_strlen;

  tc_my_strlen = tcase_create("my_strlen");
  tcase_add_test(tc_my_strlen, test_strlen_nonempty);
  tcase_add_test(tc_my_strlen, test_strlen_empty);
  suite_add_tcase(suite, tc_my_strlen);

  return suite;
}