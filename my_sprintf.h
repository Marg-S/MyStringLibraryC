#ifndef my_SPRINTF
#define my_SPRINTF

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <wchar.h>

#include "my_string.h"

typedef struct {
  int f_minus;
  int f_plus;
  int f_space;
  int f_sharp;
  int f_zero;
  int width;
  int precision;
  int length;
  int specifier;
} options;

int get_flag(char **p_format, options *option);
int get_value(char **p_format, va_list value);
int get_length(char **p_format);
int get_argument(char **p_format, va_list value, char *str, int *n, options *o);

void print_char(int number, char *str, int *n, options *option);
void print_integer(long long number, char *str, int *n, options *option);
void print_unsigned(unsigned long long number, char *str, int *n, options *o);
void print_hex_oct(unsigned long number, char *str, int *n, options *option);
void print_double(long double number, char *str, int *n, options *option);
void print_g_double(long double number, char *str, int *n, options *option);
void print_exponent(long double number, char *str, int *n, options *option);
void print_string(char *str_arg, char *str, int *n, options *option);

void print_rate(int space_width, int zero_width, int rate_width,
                long double rate, char *str, int *n, options *option);
long double exp_normal(long double *number, long double *whole, int *rate);
long long rnd_dfraction(long double *number, long double *whole,
                        long double *dfraction, int *rate, options *option);
int get_number_width(long long *fraction, options *option);
int get_sign(long double number, options *option);
int print_zero(int data_width, int sign, char *str, int *n, options *option);
void print_number(int space_width, int flag_minus, int sign, int zero_width,
                  int number_width, long double number, char *str, int *n);

#endif