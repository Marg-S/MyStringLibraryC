#include "my_tests.h"

START_TEST(test_my_strerror_all) {
  for (int errnum = -2; errnum < MAX_ERR_N + 2; errnum++) {
    char *system_result = strerror(errnum);
    char *my_result = my_strerror(errnum);
    ck_assert_str_eq(system_result, my_result);
  }
}
END_TEST

Suite *suite_strerror(void) {
  Suite *suite = suite_create("my_strerror_suite");
  TCase *tc_my_strerror;

  tc_my_strerror = tcase_create("my_strerror");
  tcase_add_test(tc_my_strerror, test_my_strerror_all);
  suite_add_tcase(suite, tc_my_strerror);

  return suite;
}