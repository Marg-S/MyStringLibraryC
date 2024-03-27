#include "my_tests.h"

START_TEST(test_my_sprintf_1) {
  char str[100], str_my[100];
  char *format = "%%Test1 %% string%%";
  int system_result = sprintf(str, "%%Test1 %% string%%");
  int my_result = my_sprintf(str_my, format);
  ck_assert_str_eq(str, str_my);
  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_my_sprintf_2) {
  char str[100], str_my[100], c = 'A';
  wchar_t wc = 'A';
  char *format = "Test2 %c %-10lc";
  int system_result = sprintf(str, format, c, wc);
  int my_result = my_sprintf(str_my, format, c, wc);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_str_eq(str, str_my);
}
END_TEST

START_TEST(test_my_sprintf_3) {
  char str[100], str_my[100];
  char *format = "Test3 %+15.10d %.1d %-15.0d";
  int n = 567890;
  int system_result = sprintf(str, format, n, n, n);
  int my_result = my_sprintf(str_my, format, n, n, n);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_str_eq(str, str_my);
}
END_TEST

START_TEST(test_my_sprintf_4) {
  char str[100], str_my[100];
  char *format = "Test4 %d %010d % 10d string";
  int n = -567890;
  int system_result = sprintf(str, format, n, n, n);
  int my_result = my_sprintf(str_my, format, n, n, n);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_str_eq(str, str_my);
}
END_TEST

START_TEST(test_my_sprintf_5) {
  char str[100], str_my[100];
  char *format = "Test5 %d %010d %+10d %-10d";
  int n = 54321;
  int system_result = sprintf(str, format, n, n, n, n);
  int my_result = my_sprintf(str_my, format, n, n, n, n);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_str_eq(str, str_my);
}
END_TEST

START_TEST(test_my_sprintf_6) {
  char str[100], str_my[100];
  char *format = "Test6 %0d %+d % d %-d %.d";
  int n = 12345000;
  int system_result = sprintf(str, format, n, n, n, n, n);
  int my_result = my_sprintf(str_my, format, n, n, n, n, n);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_str_eq(str, str_my);
}
END_TEST

START_TEST(test_my_sprintf_7) {
  char str[100], str_my[100];
  char *format = "Test7 %d %0d %+d % d %-d";
  int n = 54321;
  int system_result = sprintf(str, format, n, n, n, n, n);
  int my_result = my_sprintf(str_my, format, n, n, n, n, n);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_str_eq(str, str_my);
}
END_TEST

START_TEST(test_my_sprintf_8) {
  char str[100], str_my[100];
  char *format = "Test8 % 15.0d %015d %-15.10d";
  int n = -54321;
  int system_result = sprintf(str, format, n, n, n);
  int my_result = my_sprintf(str_my, format, n, n, n);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_str_eq(str, str_my);
}
END_TEST

START_TEST(test_my_sprintf_9) {
  char str[1000], str_my[1000];
  char *format = "Test9 %-25.22lu string";
  unsigned long n = -999999999999999;
  int system_result = sprintf(str, format, n);
  int my_result = my_sprintf(str_my, format, n);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_str_eq(str, str_my);
}
END_TEST

START_TEST(test_my_sprintf_10) {
  char str[1000], str_my[1000];
  char s[] = "HELLO";
  wchar_t ls[] = {'T', 33, 34, '\0'};
  const char *format = "%10ls Test10 %s %-10.2s";
  int system_result = sprintf(str, format, ls, s, s);
  int my_result = my_sprintf(str_my, format, ls, s, s);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_str_eq(str, str_my);
}
END_TEST

START_TEST(test_my_sprintf_11) {
  char str[1000], str_my[1000];
  char *format = "Test11 %020Lf %-#15f %+10.2f";
  double n = 123.1;
  long double ln = 12345678999999999999.9;
  int system_result = sprintf(str, format, ln, n, n);
  int my_result = my_sprintf(str_my, format, ln, n, n, n, &n, n);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_str_eq(str, str_my);
}
END_TEST

START_TEST(test_my_sprintf_12) {
  char str[100], str_my[100];
  char *format = "Test12 %nstring";
  int n, my_n;
  int system_result = sprintf(str, format, &n);
  int my_result = my_sprintf(str_my, format, &my_n);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(n, my_n);
  ck_assert_str_eq(str, str_my);
}
END_TEST

START_TEST(test_my_sprintf_13) {
  char str[100], str_my[100];
  char *format = "Test13 %ho %lo string";
  long n = 987654321099999;
  int system_result = sprintf(str, format, (short)n, n);
  int my_result = my_sprintf(str_my, format, (short)n, n);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_str_eq(str, str_my);
}
END_TEST

START_TEST(test_my_sprintf_14) {
  char str[100], str_my[100];
  char *format = "Test14 %20.8hx %-20lx";
  long n = 567890;
  int system_result = sprintf(str, format, (short)n, n);
  int my_result = my_sprintf(str_my, format, (short)n, n);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_str_eq(str, str_my);
}
END_TEST

START_TEST(test_my_sprintf_15) {
  char str[1000], str_my[1000];
  char *format = "Test15 %-g %.2g %020g %g";
  double n = -1000.005;
  int system_result = sprintf(str, format, n, n, n, n);
  int my_result = my_sprintf(str_my, format, n, n, n, n);
  ck_assert_int_eq(system_result, my_result);
  ck_assert_str_eq(str, str_my);
}
END_TEST

Suite *suite_sprintf(void) {
  Suite *suite = suite_create("my_sprintf_suite");
  TCase *tc_my_sprintf;

  tc_my_sprintf = tcase_create("my_sprintf");
  tcase_add_test(tc_my_sprintf, test_my_sprintf_1);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_2);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_3);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_4);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_5);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_6);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_7);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_8);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_9);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_10);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_11);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_12);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_13);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_14);
  tcase_add_test(tc_my_sprintf, test_my_sprintf_15);
  suite_add_tcase(suite, tc_my_sprintf);

  return suite;
}