#include "my_tests.h"

// Integers
START_TEST(test_sscanf_integer_d_1) {
  const char *str = "-1234567 3.14";
  const char *fstr = "%d %d";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result =
      sscanf(str, "%d %d", &system_values[0], &system_values[1]);
  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
}
END_TEST

START_TEST(test_sscanf_integer_d_2) {
  const char *str = "  ";
  const char *fstr = "%d %n";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result =
      sscanf(str, "%d %n", &system_values[0], &system_values[1]);
  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
}
END_TEST

START_TEST(test_sscanf_integer_d_3) {
  const char *str = "       ";
  const char *fstr = "%i ";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result = sscanf(str, "%i ", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_integer_d_i_width) {
  const char *str = "-12345678";
  const char *fstr = "%3d%2d";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result =
      sscanf(str, "%3d%2d", &system_values[0], &system_values[1]);
  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
}
END_TEST

START_TEST(test_sscanf_integer_ld) {
  long system_values[5] = {0};
  long my_values[5] = {0};
  const char *fstr = "%ld %ld %ld";
  const char *str = "111 222 333";

  int system_result = sscanf(str, "%ld %ld %ld", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_integer_hd) {
  short system_values[5] = {0};
  short my_values[5] = {0};
  const char *fstr = "%hd %hd %hd";
  const char *str = "111 222 333";

  int system_result = sscanf(str, "%hd %hd %hd", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_integer_ld_1) {
  long system_values[5] = {0};
  long my_values[5] = {0};
  const char *fstr = "%ld %ld %ld";
  const char *str = "111 222 333";

  int system_result = sscanf(str, "%ld %ld %ld", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_integer_ld_2) {
  long system_values[5] = {0};
  long my_values[5] = {0};
  const char *fstr = "%*d %ld %*d %ld %*d %ld";
  const char *str = "1111111111111 2 333333333333333 4 555555 6";

  int system_result = sscanf(str, "%*d %ld %*d %ld %*d %ld", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_integer_ld_3) {
  long system_values[5] = {0};
  long my_values[5] = {0};
  const char *fstr = "%ld %ld %ld";
  const char *str = "+111 -222 -333";

  int system_result = sscanf(str, "%ld %ld %ld", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_integer_ld_4) {
  long system_values[5] = {0};
  long my_values[5] = {0};
  const char *fstr = "%2ld %1ld %1ld";
  const char *str = "-0 +0 -0";

  int system_result = sscanf(str, "%2ld %1ld %1ld", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_integer_ld_5) {
  long system_values[5] = {0};
  long my_values[5] = {0};
  const char *fstr = "%ld %ld %ld";
  const char *str = "0 01 10";

  int system_result = sscanf(str, "%ld %ld %ld", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_integer_ld_6) {
  long system_values[5] = {0};
  long my_values[5] = {0};
  const char *fstr = "%li %ld %ld %li";
  const char *str = "100200-300+400 555";

  int system_result =
      sscanf(str, "%li %ld %ld %li", &system_values[0], &system_values[1],
             &system_values[2], &system_values[3]);
  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1],
                              &my_values[2], &my_values[3]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
  ck_assert_int_eq(system_values[3], my_values[3]);
}
END_TEST

START_TEST(test_sscanf_integer_ld_7) {
  long system_values[5] = {0};
  long my_values[5] = {0};
  const char *fstr = "%ld";
  const char *str = "9223372036854775806";

  int system_result = sscanf(str, "%ld", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_integer_ld_width_1) {
  long system_values[5] = {0};
  long my_values[5] = {0};
  const char *fstr = "%1ld %1ld %1ld";
  const char *str = "123";

  int system_result = sscanf(str, "%1ld %1ld %1ld", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_integer_ld_width_2) {
  long system_values[5] = {0};
  long my_values[5] = {0};
  const char *fstr = "%3ld%4ld%1ld";
  const char *str = "11122223";

  int system_result = sscanf(str, "%3ld%4ld%1ld", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_integer_ld_width_3) {
  long system_values[5] = {0};
  long my_values[5] = {0};
  const char *fstr = "%15ld %4ld %1ld";
  const char *str = "11122223";

  int system_result = sscanf(str, "%15ld %4ld %1ld", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST
// End of Integers

// Unsigned
START_TEST(test_sscanf_unsigned_1) {
  unsigned int system_values[5] = {0};
  unsigned int my_values[5] = {0};
  const char *fstr = "%u %*u %u %u";
  const char *str = "1111 22 32267 22";

  int system_result = sscanf(str, "%u %*u %u %u", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_unsigned_2) {
  unsigned long system_values[5] = {0};
  unsigned long my_values[5] = {0};
  const char *fstr = "%1lu %2lu %5lu %4lu";
  const char *str = "1111 22 33333 22";

  int system_result =
      sscanf(str, "%1lu %2lu %5lu %4lu", &system_values[0], &system_values[1],
             &system_values[2], &system_values[3]);
  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1],
                              &my_values[2], &my_values[3]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
  ck_assert_int_eq(system_values[3], my_values[3]);
}
END_TEST
// end of Unsigned

// Hex
START_TEST(test_sscanf_hex_1) {
  const char *str = "A1FF FF";
  const char *fstr = "%x %x";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result =
      sscanf(str, "%x %x", &system_values[0], &system_values[1]);
  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
}
END_TEST

START_TEST(test_sscanf_hex_2) {
  const char *str = "A1FF FF";
  const char *fstr = "%X %X";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result =
      sscanf(str, "%X %X", &system_values[0], &system_values[1]);
  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
}
END_TEST

START_TEST(test_sscanf_hex_3) {
  const char *str = "0xFFFFFFFF";
  const char *fstr = "%X";
  unsigned int system_values[5] = {0};
  unsigned int my_values[5] = {0};

  int system_result = sscanf(str, "%X", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_hex_4) {
  const char *str = "0X123";
  const char *fstr = "%X";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result = sscanf(str, "%X", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_hex_5) {
  const char *str = "          \n             \n     F";
  const char *fstr = "%X";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result = sscanf(str, "%X", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_hex_short) {
  const char *str = "F";
  const char *fstr = "%hX";
  unsigned short system_values[5] = {0};
  unsigned short my_values[5] = {0};

  int system_result = sscanf(str, "%hX", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_hex_long) {
  const char *str = "F";
  const char *fstr = "%lX";
  unsigned long system_values[5] = {0};
  unsigned long my_values[5] = {0};

  int system_result = sscanf(str, "%lX", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_hex_long_2) {
  const char *str = "F";
  const char *fstr = "%lX";
  unsigned long system_values[5] = {0};
  unsigned long my_values[5] = {0};

  int system_result = sscanf(str, "%lX", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_hex_6) {
  const char *str = "0xFF0x0xFFF 0xFFxFF";
  const char *fstr = "%X";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result = sscanf(str, "%X", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_hex_not_writable) {
  const char *str = "0xFF0x0xFFF 0xFFxFF";
  const char *fstr = "%*X";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result = sscanf(str, "%*X");
  int my_result = my_sscanf(str, fstr);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_hex_8) {
  const char *str = "abcd";
  const char *fstr = "%X";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result = sscanf(str, "%X", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_hex_width) {
  const char *str = "12345";
  const char *fstr = "%2x";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result = sscanf(str, "%2x", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST
// end of Hex

// Octal
START_TEST(test_sscanf_octal_1) {
  const char *str = "111";
  const char *fstr = "%o";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result = sscanf(str, "%o", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_octal_2) {
  const char *str = "0x888";
  const char *fstr = "%o";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result = sscanf(str, "%o", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_octal_3) {
  const char *str = "0x";
  const char *fstr = "%o";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result = sscanf(str, "%o", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_octal_4) {
  const char *str = "0X";
  const char *fstr = "%o";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result = sscanf(str, "%o", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_octal_5) {
  const char *str = "          \n             \n     5";
  const char *fstr = "%o";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result = sscanf(str, "%o", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_sscanf_octal_short) {
  const char *str = "111";
  const char *fstr = "%ho";
  unsigned short system_values[5] = {0};
  unsigned short my_values[5] = {0};

  int system_result = sscanf(str, "%ho", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_octal_long) {
  const char *str = "222";
  const char *fstr = "%lo";
  unsigned long system_values[5] = {0};
  unsigned long my_values[5] = {0};

  int system_result = sscanf(str, "%lo", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_octal_long_2) {
  const char *str = "333";
  const char *fstr = "%lo";
  unsigned long system_values[5] = {0};
  unsigned long my_values[5] = {0};

  int system_result = sscanf(str, "%lo", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_octal_not_writable) {
  const char *str = "8765 4321";
  const char *fstr = "%*o %*o";

  int system_result = sscanf(str, "%*o %*o");
  int my_result = my_sscanf(str, fstr);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_sscanf_octal_width) {
  const char *str = "123";
  const char *fstr = "%2o";
  int system_values[5] = {0};
  int my_values[5] = {0};

  int system_result = sscanf(str, "%2o", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST
// End of Octal

// Doubles and floats
START_TEST(test_sscanf_double_1) {
  const char *str = "3.14 -3.14";
  const char *fstr = "%lf %lf";
  double system_values[5] = {0};
  double my_values[5] = {0};

  int system_result =
      sscanf(str, "%lf %lf", &system_values[0], &system_values[1]);
  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_double_eq(system_values[0], my_values[0]);
  ck_assert_double_eq(system_values[1], my_values[1]);
}
END_TEST

START_TEST(test_sscanf_double_long) {
  const char *str = "-3.14 +3.000014";
  const char *fstr = "%Lf %Lf";
  long double system_values[5] = {0};
  long double my_values[5] = {0};

  int system_result =
      sscanf(str, "%Lf %Lf", &system_values[0], &system_values[1]);
  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_double_eq(system_values[0], my_values[0]);
  ck_assert_double_eq(system_values[1], my_values[1]);
}
END_TEST

START_TEST(test_sscanf_float_1) {
  const char *str = "3.14 4.2345567";
  const char *fstr = "%f %f";
  float system_values[5] = {0};
  float my_values[5] = {0};

  int system_result =
      sscanf(str, "%f %f", &system_values[0], &system_values[1]);
  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_float_eq(system_values[0], my_values[0]);
  ck_assert_float_eq(system_values[1], my_values[1]);
}
END_TEST

START_TEST(test_sscanf_float_2) {
  const char *str = "3.14 4. .";
  const char *fstr = "%f %f %f";
  float system_values[5] = {0};
  float my_values[5] = {0};

  int system_result = sscanf(str, "%f %f %f", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_float_eq(system_values[0], my_values[0]);
  ck_assert_float_eq(system_values[1], my_values[1]);
  ck_assert_float_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_float_not_writable) {
  const char *str = "3.14 4.5677888";
  const char *fstr = "%*f %*f";

  int system_result = sscanf(str, "%*f %*f");
  int my_result = my_sscanf(str, fstr);

  ck_assert_int_eq(system_result, my_result);
}
END_TEST

START_TEST(test_sscanf_float_g) {
  const char *str = "1.4441 1.31e2 3.31e-4 0.444e-5";
  const char *fstr = "%g %g %*g %g";
  float system_value[5] = {0.0};
  float my_value[5] = {0.0};

  int system_result = sscanf(str, "%g %g %*g %g", &system_value[0],
                             &system_value[1], &system_value[2]);
  int my_result =
      my_sscanf(str, fstr, &my_value[0], &my_value[1], &my_value[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_float_eq(system_value[0], my_value[0]);
  ck_assert_float_eq(system_value[1], my_value[1]);
  ck_assert_float_eq(system_value[2], my_value[2]);
}
END_TEST

START_TEST(test_sscanf_float_G_1) {
  const char *str = "inf 1.31E+2 NaN 0.444e-5 1010";
  const char *fstr = "%G %G %G %*G %G";
  float system_value[5] = {0.0};
  float my_value[5] = {0.0};

  int system_result =
      sscanf(str, "%G %G %G %*G %G", &system_value[0], &system_value[1],
             &system_value[2], &system_value[3]);
  int my_result = my_sscanf(str, fstr, &my_value[0], &my_value[1],
                              &my_value[2], &my_value[3]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_float_eq(system_value[0], my_value[0]);
  ck_assert_float_eq(system_value[1], my_value[1]);
  ck_assert_float_nan(system_value[2]);
  ck_assert_float_nan(my_value[2]);
  ck_assert_float_eq(system_value[3], my_value[3]);
}
END_TEST

START_TEST(test_sscanf_float_G_2) {
  const char *str =
      "nAN           +INF                   -0.1111         1e-10  -iNf";
  const char *fstr = "%G %G %G %G %G";
  float system_value[5] = {0.0};
  float my_value[5] = {0.0};

  int system_result =
      sscanf(str, "%G %G %G %G %G", &system_value[0], &system_value[1],
             &system_value[2], &system_value[3], &system_value[4]);
  int my_result = my_sscanf(str, fstr, &my_value[0], &my_value[1],
                              &my_value[2], &my_value[3], &my_value[4]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_float_nan(system_value[0]);
  ck_assert_float_nan(my_value[0]);
  ck_assert_float_eq(system_value[1], my_value[1]);
  ck_assert_float_eq(system_value[2], my_value[2]);
  ck_assert_float_eq(system_value[3], my_value[3]);
  ck_assert_float_eq(system_value[4], my_value[4]);
}
END_TEST

START_TEST(test_sscanf_double_e) {
  const char *str = "2.718281e+00 nan -inf +inf";
  long double system_value[5] = {0.0};
  long double my_value[5] = {0.0};

  int system_result =
      sscanf(str, "%Le %Le %Le %Le", &system_value[0], &system_value[1],
             &system_value[2], &system_value[3]);
  int my_result = my_sscanf(str, "%Le %Le %Le %Le", &my_value[0],
                              &my_value[1], &my_value[2], &my_value[3]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_double_eq(system_value[0], my_value[0]);
  ck_assert_double_nan(system_value[1]);
  ck_assert_double_nan(my_value[1]);
  ck_assert_double_eq(system_value[2], my_value[2]);
  ck_assert_double_eq(system_value[3], my_value[3]);
}
END_TEST

START_TEST(test_sscanf_double_E) {
  const char *str = "2.718281E+00 nan inf";
  double system_value[5] = {0.0};
  double my_value[5] = {0.0};
  float system_value_1 = 0;
  float my_value_1 = 0;

  int system_result = sscanf(str, "%lE %E %lE", &system_value[0],
                             &system_value_1, &system_value[2]);
  int my_result =
      my_sscanf(str, "%lE %E %lE", &my_value[0], &my_value_1, &my_value[2]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_double_eq(system_value[0], my_value[0]);
  ck_assert_double_nan(system_value_1);
  ck_assert_double_nan(my_value_1);
  ck_assert_double_eq(system_value[2], my_value[2]);
}
END_TEST

START_TEST(test_sscanf_double_width) {
  const char *str = "3.1413456 -5.000005";
  double system_value = 0.0;
  double my_value = 0.0;
  long double system_value_1 = 0.0;
  long double my_value_1 = 0.0;

  int system_result = sscanf(str, "%5lf %2Lf", &system_value, &system_value_1);
  int my_result = my_sscanf(str, "%5lf %2Lf", &my_value, &my_value_1);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_double_eq(system_value, my_value);
  ck_assert_double_eq(system_value_1, my_value_1);
}
END_TEST
// End of Doubles and Floats

// Chars
START_TEST(test_sscanf_chars_1) {
  char system_values[5] = {'\0'};
  char my_values[5] = {'\0'};
  const char *str = "a b c";
  const char *fstr = "%c %c %c";

  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);
  int system_result = sscanf(str, "%c %c %c", &system_values[0],
                             &system_values[1], &system_values[2]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_chars_lc) {
  wchar_t system_values[5] = {'\0'};
  wchar_t my_values[5] = {'\0'};
  const char *str = "a";
  const char *fstr = "%lc";

  int my_result = my_sscanf(str, fstr, &my_values[0]);
  int system_result = sscanf(str, "%lc", &system_values[0]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST

START_TEST(test_sscanf_chars_not_writable) {
  const char *str = "abcdefghjk";
  const char *fstr = "%*c%*c%*c";

  int my_result = my_sscanf(str, fstr);
  int system_result = sscanf(str, "%*c%*c%*c");

  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_sscanf_chars_2) {
  char system_values[5] = {'\0'};
  char my_values[5] = {'\0'};
  const char *str = "1 a 2   b           ";
  const char *fstr = "%c %c %c      %c";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1],
                              &my_values[2], &my_values[3]);
  int system_result =
      sscanf(str, "%c %c %c      %c", &system_values[0], &system_values[1],
             &system_values[2], &system_values[3]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
  ck_assert_int_eq(system_values[3], my_values[3]);
}
END_TEST

START_TEST(test_sscanf_chars_4) {
  char system_values[5] = {'\0'};
  char my_values[5] = {'\0'};
  const char *str = "aaaa";
  const char *fstr = "%c %c %c %c";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1],
                              &my_values[2], &my_values[3]);
  int system_result =
      sscanf(str, "%c %c %c %c", &system_values[0], &system_values[1],
             &system_values[2], &system_values[3]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
  ck_assert_int_eq(system_values[3], my_values[3]);
}
END_TEST

START_TEST(test_sscanf_chars_5) {
  char system_values[5] = {'\0'};
  char my_values[5] = {'\0'};
  const char *str = "\\\n\t\t\t";
  const char *fstr = "%c%c%c%c";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1],
                              &my_values[2], &my_values[3]);
  int system_result =
      sscanf(str, "%c%c%c%c", &system_values[0], &system_values[1],
             &system_values[2], &system_values[3]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
  ck_assert_int_eq(system_values[3], my_values[3]);
}
END_TEST

START_TEST(test_sscanf_chars_6) {
  char system_values[5] = {'\0'};
  char my_values[5] = {'\0'};
  const char *str = "a ' ' /";
  const char *fstr = "%c %c %c %c";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1],
                              &my_values[2], &my_values[3]);
  int system_result =
      sscanf(str, "%c %c %c %c", &system_values[0], &system_values[1],
             &system_values[2], &system_values[3]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
  ck_assert_int_eq(system_values[3], my_values[3]);
}
END_TEST

START_TEST(test_sscanf_chars_7) {
  char system_values[5] = {'\0'};
  char my_values[5] = {'\0'};
  const char *str = "z *'@";
  const char *fstr = "%1c %c %c %0c";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1],
                              &my_values[2], &my_values[3]);
  int system_result =
      sscanf(str, "%1c %c %c %2c", &system_values[0], &system_values[1],
             &system_values[2], &system_values[3]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
  ck_assert_int_eq(system_values[3], my_values[3]);
}
END_TEST

START_TEST(test_sscanf_chars_8) {
  const char *str = "   c ";
  const char *fstr = "%*c%*c%*c%*c";

  int my_result = my_sscanf(str, fstr);
  int system_result = sscanf(str, "%*c%*c%*c%*c");

  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_sscanf_chars_9) {
  const char *str = "abcd ";
  const char *fstr = "%*c%*c%*c%*c";

  int my_result = my_sscanf(str, fstr);
  int system_result = sscanf(str, "%*c%*c%*c%*c");

  ck_assert_int_eq(my_result, system_result);
}
END_TEST

START_TEST(test_sscanf_char) {
  char system_values[5] = {'\0'};
  char my_values[5] = {'\0'};
  const char *str = "abcdefg";
  const char *fstr = "%3c";

  int my_result = my_sscanf(str, fstr, &my_values[0]);
  int system_result = sscanf(str, "%3c", &system_values[0]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
}
END_TEST
// End of chars

// Strings
START_TEST(test_sscanf_string_1) {
  char system_string_1[10] = {'\0'};
  char system_string_2[10] = {'\0'};
  char system_string_3[10] = {'\0'};
  char system_string_4[10] = {'\0'};

  char my_string_1[10] = {'\0'};
  char my_string_2[10] = {'\0'};
  char my_string_3[10] = {'\0'};
  char my_string_4[10] = {'\0'};

  const char *str = "Aaaaa bbbb cccccc ddddd";
  const char *fstr = "%s %s %s %s";

  int my_result = my_sscanf(str, fstr, my_string_1, my_string_2,
                              my_string_3, my_string_4);
  int system_result = sscanf(str, "%s %s %s %s", system_string_1,
                             system_string_2, system_string_3, system_string_4);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_str_eq(system_string_1, my_string_1);
  ck_assert_str_eq(system_string_2, my_string_2);
  ck_assert_str_eq(system_string_3, my_string_3);
  ck_assert_str_eq(system_string_4, my_string_4);
}
END_TEST

START_TEST(test_sscanf_string_2) {
  char system_string_1[10] = {'\0'};
  char system_string_2[10] = {'\0'};
  char system_string_3[10] = {'\0'};
  char system_string_4[10] = {'\0'};
  long system_value_1 = 0;
  int system_value_2 = 0;
  int system_value_3 = 0;

  char my_string_1[10] = {'\0'};
  char my_string_2[10] = {'\0'};
  char my_string_3[10] = {'\0'};
  char my_string_4[10] = {'\0'};
  long my_value_1 = 0;
  int my_value_2 = 0;
  int my_value_3 = 0;

  const char *str = "Aaaaa 111 bbbb -222 cccccc 44ddddd 5";
  const char *fstr = "%s%ld%s%d%s%d%s";

  int my_result =
      my_sscanf(str, fstr, my_string_1, &my_value_1, my_string_2,
                 &my_value_2, my_string_3, &my_value_3, my_string_4);
  int system_result = sscanf(str, "%s%ld%s%d%s%d%s", system_string_1,
                             &system_value_1, system_string_2, &system_value_2,
                             system_string_3, &system_value_3, system_string_4);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_str_eq(system_string_1, my_string_1);
  ck_assert_str_eq(system_string_2, my_string_2);
  ck_assert_str_eq(system_string_3, my_string_3);
  ck_assert_str_eq(system_string_4, my_string_4);
  ck_assert_int_eq(system_value_1, my_value_1);
  ck_assert_int_eq(system_value_3, my_value_3);
  ck_assert_int_eq(system_value_2, my_value_2);
}
END_TEST

START_TEST(test_sscanf_string_3) {
  char system_string_1[10] = {'\0'};
  char system_string_2[10] = {'\0'};
  char system_string_3[10] = {'\0'};
  wchar_t system_string_4[10] = {'\0'};

  char my_string_1[10] = {'\0'};
  char my_string_2[10] = {'\0'};
  char my_string_3[10] = {'\0'};
  wchar_t my_string_4[10] = {'\0'};

  const char *str = "Aaaaa\tbbbb\tcccccc\tddddd e";
  const char *fstr = "%s%*s%s%s%ls";

  int my_result = my_sscanf(str, fstr, my_string_1, my_string_2,
                              my_string_3, my_string_4);
  int system_result = sscanf(str, "%s%*s%s%s%ls", system_string_1,
                             system_string_2, system_string_3, system_string_4);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_str_eq(system_string_1, my_string_1);
  ck_assert_str_eq(system_string_2, my_string_2);
  ck_assert_str_eq(system_string_3, my_string_3);
  ck_assert_int_eq(*system_string_4, *my_string_4);
}
END_TEST

START_TEST(test_sscanf_string_4) {
  char system_string_1[5] = {'\0'};
  char system_string_2[5] = {'\0'};
  char system_string_3[5] = {'\0'};
  char system_string_4[5] = {'\0'};
  int system_n = 0;

  char my_string_1[5] = {'\0'};
  char my_string_2[5] = {'\0'};
  char my_string_3[5] = {'\0'};
  char my_string_4[5] = {'\0'};
  int my_n = 0;

  const char *str = "Aaaaa\tbbbb cccccc ddddd ee f g";
  const char *fstr = "%*s%*s%*s%*s%n";

  int my_result = my_sscanf(str, fstr, &my_n);
  int system_result = sscanf(str, "%*s%*s%*s%*s%n", &system_n);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_str_eq(system_string_1, my_string_1);
  ck_assert_str_eq(system_string_2, my_string_2);
  ck_assert_str_eq(system_string_3, my_string_3);
  ck_assert_str_eq(system_string_4, my_string_4);
}
END_TEST

START_TEST(test_sscanf_string_5) {
  char system_string_1[5] = {'\0'};
  char system_string_2[5] = {'\0'};
  char system_string_3[5] = {'\0'};
  char system_string_4[5] = {'\0'};

  char my_string_1[5] = {'\0'};
  char my_string_2[5] = {'\0'};
  char my_string_3[5] = {'\0'};
  char my_string_4[5] = {'\0'};

  const char *str = "Aaaaa\tbbbb\tcccccc\tddddd";
  const char *fstr = "%1s%1s%1s%1s";

  int my_result = my_sscanf(str, fstr, my_string_1, my_string_2,
                              my_string_3, my_string_4);
  int system_result = sscanf(str, "%1s%1s%1s%1s", system_string_1,
                             system_string_2, system_string_3, system_string_4);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_str_eq(system_string_1, my_string_1);
  ck_assert_str_eq(system_string_2, my_string_2);
  ck_assert_str_eq(system_string_3, my_string_3);
  ck_assert_str_eq(system_string_4, my_string_4);
}
END_TEST

START_TEST(test_sscanf_string_6) {
  char system_string_1[5] = {'\0'};
  char system_string_2[5] = {'\0'};
  char system_string_3[5] = {'\0'};
  char system_string_4[5] = {'\0'};

  char my_string_1[5] = {'\0'};
  char my_string_2[5] = {'\0'};
  char my_string_3[5] = {'\0'};
  char my_string_4[5] = {'\0'};

  const char *str = "Aaaaa\tbbbb\tcccccc\tddddd";
  const char *fstr = "%3s%3s%3s%3s";

  int my_result = my_sscanf(str, fstr, my_string_1, my_string_2,
                              my_string_3, my_string_4);
  int system_result = sscanf(str, "%3s%3s%3s%3s", system_string_1,
                             system_string_2, system_string_3, system_string_4);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_str_eq(system_string_1, my_string_1);
  ck_assert_str_eq(system_string_2, my_string_2);
  ck_assert_str_eq(system_string_3, my_string_3);
  ck_assert_str_eq(system_string_4, my_string_4);
}
END_TEST

START_TEST(test_sscanf_string_7) {
  char system_string_1[10] = {'\0'};
  char system_string_2[10] = {'\0'};
  char system_string_3[10] = {'\0'};
  char system_string_4[10] = {'\0'};

  char my_string_1[10] = {'\0'};
  char my_string_2[10] = {'\0'};
  char my_string_3[10] = {'\0'};
  char my_string_4[10] = {'\0'};

  const char *str = "Aaaaa\tbbbb\tcccccc\tddddd";
  const char *fstr = "%150s%1s%1s\t%3s";

  int my_result = my_sscanf(str, fstr, my_string_1, my_string_2,
                              my_string_3, my_string_4);
  int system_result = sscanf(str, "%150s%1s%1s\t%3s", system_string_1,
                             system_string_2, system_string_3, system_string_4);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_str_eq(system_string_1, my_string_1);
  ck_assert_str_eq(system_string_2, my_string_2);
  ck_assert_str_eq(system_string_3, my_string_3);
  ck_assert_str_eq(system_string_4, my_string_4);
}
END_TEST
// End of strings

// n
START_TEST(test_sscanf_n_zero) {
  int system_n = 0;
  int my_n = 0;
  const char *str = "abcdefg";
  const char *fstr = "%n";

  int my_result = my_sscanf(str, fstr, &my_n);
  int system_result = sscanf(str, "%n", &system_n);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_n, my_n);
}

START_TEST(test_sscanf_n_1) {
  char system_values[5] = {'\0'};
  char my_values[5] = {'\0'};
  int system_n = 0;
  int my_n = 0;
  const char *str = "abcdefg";
  const char *fstr = "%c%c%n%c";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_n,
                              &my_values[2]);
  int system_result = sscanf(str, "%c%c%n%c", &system_values[0],
                             &system_values[1], &system_n, &system_values[2]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
  ck_assert_int_eq(system_n, my_n);
}

START_TEST(test_sscanf_n_2) {
  int system_values[5] = {0};
  int my_values[5] = {0};
  const char *str = "12 34 567";
  const char *fstr = "%d %d %n %d";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1],
                              &my_values[2], &my_values[3]);
  int system_result =
      sscanf(str, "%d %d %n %d", &system_values[0], &system_values[1],
             &system_values[2], &system_values[3]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(my_values[0], system_values[0]);
  ck_assert_int_eq(34, system_values[1]);
  ck_assert_int_eq(6, system_values[2]);
  ck_assert_int_eq(567, system_values[3]);
}

START_TEST(test_sscanf_n_percent) {
  int system_values[5] = {0};
  int my_values[5] = {0};
  const char *str = "12 %34 567";
  const char *fstr = "%d %%%d %n %d";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1],
                              &my_values[2], &my_values[3]);
  int system_result =
      sscanf(str, "%d %%%d %n %d", &system_values[0], &system_values[1],
             &system_values[2], &system_values[3]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(my_values[0], system_values[0]);
  ck_assert_int_eq(my_values[1], system_values[1]);
  ck_assert_int_eq(my_values[2], system_values[2]);
  ck_assert_int_eq(my_values[3], system_values[3]);
}

START_TEST(test_sscanf_n_no_writable) {
  char system_values[7] = {'\0'};
  char my_values[7] = {'\0'};
  int system_n_1 = 0, system_n_2 = 0;
  int my_n_1 = 0, my_n_2 = 0;
  const char *str = "abcdefg";
  const char *fstr = "%c%*c%n%*c%c%n";

  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_n_1, &my_values[1], &my_n_2);
  int system_result = sscanf(str, "%c%*c%n%*c%c%n", &system_values[0],
                             &system_n_1, &system_values[1], &system_n_2);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_n_1, my_n_1);
  ck_assert_int_eq(system_n_2, my_n_2);
}
// Enf of n

// %
START_TEST(test_sscanf_percent_1) {
  int system_values[7] = {0};
  int my_values[7] = {0};
  const char *str = "11%22%33";
  const char *fstr = "%d%%%d%%%d";

  int system_result = sscanf(str, "%d%%%d%%%d", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_percent_2) {
  int system_values[7] = {0};
  int my_values[7] = {0};
  const char *str = "11 % 22 % 33";
  const char *fstr = "%d %% %d %% %d";

  int system_result = sscanf(str, "%d %% %d %% %d", &system_values[0],
                             &system_values[1], &system_values[2]);
  int my_result =
      my_sscanf(str, fstr, &my_values[0], &my_values[1], &my_values[2]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST

START_TEST(test_sscanf_percent_3) {
  int system_values[7] = {0};
  int my_values[7] = {0};
  const char *str = "%%%11";
  const char *fstr = "%%%%%%%d";

  int system_result = sscanf(str, "%%%%%%%d", &system_values[0]);
  int my_result = my_sscanf(str, fstr, &my_values[0]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
  ck_assert_int_eq(system_values[2], my_values[2]);
}
END_TEST
// End of %

// Buffer
START_TEST(test_sscanf_buff_1) {
  int system_values[7] = {0};
  int my_values[7] = {0};
  const char *str = "12 abcde 34";
  const char *fstr = "%d abcde %d";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1]);
  int system_result =
      sscanf(str, "%d abcde %d", &system_values[0], &system_values[1]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
}
END_TEST

START_TEST(test_sscanf_buff_2) {
  int system_values[7] = {0};
  int my_values[7] = {0};
  const char *str = "12abcde34";
  const char *fstr = "%dabcde%d";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1]);
  int system_result =
      sscanf(str, "%dabcde%d", &system_values[0], &system_values[1]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
}
END_TEST

START_TEST(test_sscanf_buff_3) {
  int system_values[7] = {0};
  int my_values[7] = {0};
  const char *str = "12abcde34";
  const char *fstr = "%dabcdefd%d";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1]);
  int system_result =
      sscanf(str, "%dabcdefd%d", &system_values[0], &system_values[1]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
}
END_TEST

START_TEST(test_sscanf_buff_4) {
  int system_values[7] = {0};
  int my_values[7] = {0};
  const char *str = "12abcdefd34";
  const char *fstr = "%dabcde%d";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1]);
  int system_result =
      sscanf(str, "%dabcde%d", &system_values[0], &system_values[1]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_int_eq(system_values[0], my_values[0]);
  ck_assert_int_eq(system_values[1], my_values[1]);
}
END_TEST
// End of buffer

// Pointer
START_TEST(test_sscanf_pointer_1) {
  int *system_values[7] = {NULL};
  int *my_values[7] = {NULL};
  const char *str = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char *fstr = "%p %p %p %p";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1],
                              &my_values[2], &my_values[3]);
  int system_result =
      sscanf(str, "%p %p %p %p", &system_values[0], &system_values[1],
             &system_values[2], &system_values[3]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_ptr_eq(system_values[0], my_values[0]);
  ck_assert_ptr_eq(system_values[1], my_values[1]);
  ck_assert_ptr_eq(system_values[2], my_values[2]);
  ck_assert_ptr_eq(system_values[3], my_values[3]);
}
END_TEST

START_TEST(test_sscanf_pointer_2) {
  int *system_values[7] = {NULL};
  int *my_values[7] = {NULL};
  const char *str = "0xFFFF 0xAAAA 0x7123 0xBBC1FF 0x7123 0x7123";
  const char *fstr = "%p %p %p %p %*p %2p";

  int my_result = my_sscanf(str, fstr, &my_values[0], &my_values[1],
                              &my_values[2], &my_values[3], &my_values[4]);
  int system_result =
      sscanf(str, "%p %p %p %p %*p %2p", &system_values[0], &system_values[1],
             &system_values[2], &system_values[3], &system_values[4]);

  ck_assert_int_eq(my_result, system_result);
  ck_assert_ptr_eq(system_values[0], my_values[0]);
  ck_assert_ptr_eq(system_values[1], my_values[1]);
  ck_assert_ptr_eq(system_values[2], my_values[2]);
  ck_assert_ptr_eq(system_values[3], my_values[3]);
  ck_assert_ptr_eq(system_values[4], my_values[4]);
}
END_TEST
// End of Pointer

// Mix
START_TEST(test_sscanf_mix_1) {
  long system_values_int[5] = {0};
  long my_values_int[5] = {0};
  char system_values_ch[5] = {0};
  char my_values_ch[5] = {0};
  const char *fstr = "%li%c%li%c";
  const char *str = "100200-300+400+555";

  int system_result =
      sscanf(str, "%li%c%li%c", &system_values_int[0], &system_values_ch[0],
             &system_values_int[1], &system_values_ch[1]);
  int my_result = my_sscanf(str, fstr, &my_values_int[0], &my_values_ch[0],
                              &my_values_int[1], &my_values_ch[1]);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values_int[0], my_values_int[0]);
  ck_assert_int_eq(system_values_int[1], my_values_int[1]);
  ck_assert_int_eq(system_values_ch[0], my_values_ch[0]);
  ck_assert_int_eq(system_values_ch[1], my_values_ch[1]);
}
END_TEST

START_TEST(test_sscanf_mix_2) {
  int system_values_int[5] = {0};
  int my_values_int[5] = {0};
  int system_n = 0;
  int my_n = 0;

  const char *fstr = "%dText!%d %n";
  const char *str = "111111Text!22222";

  int system_result = sscanf(str, "%dText!%d %n", &system_values_int[0],
                             &system_values_int[1], &system_n);
  int my_result =
      my_sscanf(str, fstr, &my_values_int[0], &my_values_int[1], &my_n);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_values_int[0], my_values_int[0]);
  ck_assert_int_eq(system_values_int[1], my_values_int[1]);
}
END_TEST

START_TEST(test_sscanf_mix_3) {
  float system_float = 0;
  float my_float = 0;
  char system_str_1[10] = {0};
  char my_str_1[10] = {0};
  char system_str_2[10] = {0};
  char my_str_2[10] = {0};
  char system_ch = 0;
  char my_ch = 0;
  short system_short = 0;
  short my_short = 0;
  long long system_long_long = 0;
  long long my_long_long = 0;

  const char *fstr = "%c%5s%%%s %%  %G %hi %%FIN%lldDME%%";
  const char *str = "$AmIIn%%sane? %\n\n\n \n \n \n\t   InF 0 %FIN9D-ME%";

  int system_result = sscanf(str, "%c%5s%%%s %%  %G %hi %%FIN%lldDME%%",
                             &system_ch, system_str_1, system_str_2,
                             &system_float, &system_short, &system_long_long);
  int my_result = sscanf(str, fstr, &my_ch, my_str_1, my_str_2, &my_float,
                          &my_short, &my_long_long);

  ck_assert_int_eq(system_result, my_result);
  ck_assert_int_eq(system_ch, my_ch);
  ck_assert_str_eq(system_str_1, my_str_1);
  ck_assert_str_eq(system_str_2, my_str_2);
  ck_assert_float_eq(system_float, my_float);
  ck_assert_int_eq(system_short, my_short);
  ck_assert_int_eq(system_long_long, my_long_long);
}
END_TEST
// End of Mix

Suite *suite_sscanf(void) {
  Suite *suite = suite_create("my_sscanf");
  TCase *tc_my_sscanf;

  tc_my_sscanf = tcase_create("tc_my_sscanf");
  //   Integers
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_d_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_d_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_d_3);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_d_i_width);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_ld);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_hd);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_ld_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_ld_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_ld_3);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_ld_4);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_ld_5);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_ld_6);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_ld_7);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_ld_width_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_ld_width_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_integer_ld_width_3);
  // Unsigned
  tcase_add_test(tc_my_sscanf, test_sscanf_unsigned_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_unsigned_2);
  // Hex
  tcase_add_test(tc_my_sscanf, test_sscanf_hex_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_hex_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_hex_3);
  tcase_add_test(tc_my_sscanf, test_sscanf_hex_4);
  tcase_add_test(tc_my_sscanf, test_sscanf_hex_5);
  tcase_add_test(tc_my_sscanf, test_sscanf_hex_6);
  tcase_add_test(tc_my_sscanf, test_sscanf_hex_8);
  tcase_add_test(tc_my_sscanf, test_sscanf_hex_width);
  tcase_add_test(tc_my_sscanf, test_sscanf_hex_short);
  tcase_add_test(tc_my_sscanf, test_sscanf_hex_long);
  tcase_add_test(tc_my_sscanf, test_sscanf_hex_long_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_hex_not_writable);
  // Octal
  tcase_add_test(tc_my_sscanf, test_sscanf_octal_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_octal_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_octal_3);
  tcase_add_test(tc_my_sscanf, test_sscanf_octal_4);
  tcase_add_test(tc_my_sscanf, test_sscanf_octal_5);
  tcase_add_test(tc_my_sscanf, test_sscanf_octal_short);
  tcase_add_test(tc_my_sscanf, test_sscanf_octal_long);
  tcase_add_test(tc_my_sscanf, test_sscanf_octal_long_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_octal_not_writable);
  tcase_add_test(tc_my_sscanf, test_sscanf_octal_width);
  //   Doubles and floats
  tcase_add_test(tc_my_sscanf, test_sscanf_float_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_float_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_float_not_writable);
  tcase_add_test(tc_my_sscanf, test_sscanf_double_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_double_long);
  tcase_add_test(tc_my_sscanf, test_sscanf_float_g);
  tcase_add_test(tc_my_sscanf, test_sscanf_float_G_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_float_G_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_double_e);
  tcase_add_test(tc_my_sscanf, test_sscanf_double_E);
  tcase_add_test(tc_my_sscanf, test_sscanf_double_width);
  // Chars
  tcase_add_test(tc_my_sscanf, test_sscanf_chars_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_chars_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_chars_4);
  tcase_add_test(tc_my_sscanf, test_sscanf_chars_5);
  tcase_add_test(tc_my_sscanf, test_sscanf_chars_6);
  tcase_add_test(tc_my_sscanf, test_sscanf_chars_7);
  tcase_add_test(tc_my_sscanf, test_sscanf_chars_8);
  tcase_add_test(tc_my_sscanf, test_sscanf_chars_9);
  tcase_add_test(tc_my_sscanf, test_sscanf_chars_lc);
  tcase_add_test(tc_my_sscanf, test_sscanf_chars_not_writable);
  tcase_add_test(tc_my_sscanf, test_sscanf_char);
  // Strings
  tcase_add_test(tc_my_sscanf, test_sscanf_string_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_string_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_string_3);
  tcase_add_test(tc_my_sscanf, test_sscanf_string_4);
  tcase_add_test(tc_my_sscanf, test_sscanf_string_5);
  tcase_add_test(tc_my_sscanf, test_sscanf_string_6);
  tcase_add_test(tc_my_sscanf, test_sscanf_string_7);
  // %
  tcase_add_test(tc_my_sscanf, test_sscanf_percent_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_percent_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_percent_3);
  // Buffer
  tcase_add_test(tc_my_sscanf, test_sscanf_buff_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_buff_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_buff_3);
  tcase_add_test(tc_my_sscanf, test_sscanf_buff_4);
  // n
  tcase_add_test(tc_my_sscanf, test_sscanf_n_zero);
  tcase_add_test(tc_my_sscanf, test_sscanf_n_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_n_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_n_percent);
  tcase_add_test(tc_my_sscanf, test_sscanf_n_no_writable);
  // Pointer
  tcase_add_test(tc_my_sscanf, test_sscanf_pointer_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_pointer_2);
  // Mix
  tcase_add_test(tc_my_sscanf, test_sscanf_mix_1);
  tcase_add_test(tc_my_sscanf, test_sscanf_mix_2);
  tcase_add_test(tc_my_sscanf, test_sscanf_mix_3);

  suite_add_tcase(suite, tc_my_sscanf);

  return suite;
}