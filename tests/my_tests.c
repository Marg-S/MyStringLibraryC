#include "my_tests.h"

int main(void) {
  int failed = 0;
  Suite *suite[21];
  SRunner *runner;

  suite[0] = suite_sprintf();
  suite[1] = suite_strlen();
  suite[2] = suite_memcmp();
  suite[3] = suite_memset();
  suite[4] = suite_strchr();
  suite[5] = suite_strncpy();
  suite[6] = suite_strpbrk();
  suite[7] = suite_strstr();
  suite[8] = suite_strerror();
  suite[9] = suite_strncmp();
  suite[10] = suite_memchr();
  suite[11] = suite_memcpy();
  suite[12] = suite_strcspn();
  suite[13] = suite_strncat();
  suite[14] = suite_strrchr();
  suite[15] = suite_strtok();
  suite[16] = suite_sscanf();
  suite[17] = suite_to_lower();
  suite[18] = suite_to_upper();
  suite[19] = suite_insert();
  suite[20] = suite_trim();
  runner = srunner_create(suite[1]);

  srunner_add_suite(runner, suite[0]);
  srunner_add_suite(runner, suite[2]);
  srunner_add_suite(runner, suite[3]);
  srunner_add_suite(runner, suite[4]);
  srunner_add_suite(runner, suite[5]);
  srunner_add_suite(runner, suite[6]);
  srunner_add_suite(runner, suite[7]);
  srunner_add_suite(runner, suite[8]);
  srunner_add_suite(runner, suite[9]);
  srunner_add_suite(runner, suite[10]);
  srunner_add_suite(runner, suite[11]);
  srunner_add_suite(runner, suite[12]);
  srunner_add_suite(runner, suite[13]);
  srunner_add_suite(runner, suite[14]);
  srunner_add_suite(runner, suite[15]);
  srunner_add_suite(runner, suite[16]);
  srunner_add_suite(runner, suite[17]);
  srunner_add_suite(runner, suite[18]);
  srunner_add_suite(runner, suite[19]);
  srunner_add_suite(runner, suite[20]);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}