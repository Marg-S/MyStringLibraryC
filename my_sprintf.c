#include "my_sprintf.h"

int my_sprintf(char *str, const char *format, ...) {
  va_list value;
  int n = 0, error = 0;
  char *p_format = (char *)format;
  va_start(value, format);

  while (*p_format != '\0' && !error) {
    while (*p_format != '\0' && *p_format != '%') str[n++] = *p_format++;
    if (*p_format == '%') {
      options option = {0};
      option.precision = -1;
      p_format++;
      while (get_flag(&p_format, &option)) {
      }
      option.width = get_value(&p_format, value);
      if (*p_format == '.') {
        option.precision = 0;
        p_format++;
        option.precision = get_value(&p_format, value);
      }
      option.length = get_length(&p_format);
      error = get_argument(&p_format, value, str, &n, &option);
    }
  }

  str[n] = '\0';
  va_end(value);

  return n;
}

int get_flag(char **p_format, options *option) {
  char symbol = **p_format;

  if (symbol == '-')
    option->f_minus = 1;
  else if (symbol == '+')
    option->f_plus = 1;
  else if (symbol == ' ')
    option->f_space = 1;
  else if (symbol == '#')
    option->f_sharp = 1;
  else if (symbol == '0')
    option->f_zero = 1;
  else
    symbol = 0;

  if (symbol) (*p_format)++;

  return symbol;
}

int get_value(char **p_format, va_list value) {
  int number = 0;

  if (**p_format == '*') {
    number = va_arg(value, int);
    (*p_format)++;
  }

  while (**p_format >= '0' && **p_format <= '9') {
    number = number * 10 + **p_format - '0';
    (*p_format)++;
  }

  return number;
}

int get_length(char **p_format) {
  int length = 0;
  char symbol = **p_format;

  if (symbol == 'h' || symbol == 'l' || symbol == 'L') {
    length = symbol;
    (*p_format)++;
  }

  return length;
}

int get_argument(char **p_format, va_list v, char *str, int *n, options *o) {
  int error = 0;
  o->specifier = **p_format;
  if (o->specifier == '%')
    str[(*n)++] = '%';
  else if (o->specifier == 'n')
    *(va_arg(v, int *)) = *n;
  else if (o->specifier == 'o' || o->specifier == 'x' || o->specifier == 'X' ||
           o->specifier == 'p')
    print_hex_oct(va_arg(v, unsigned long), str, n, o);
  else if (o->specifier == 'c')
    print_char(va_arg(v, int), str, n, o);
  else if (o->specifier == 'u')
    print_unsigned(va_arg(v, unsigned long long), str, n, o);
  else if (o->specifier == 'd' || o->specifier == 'i')
    print_integer(va_arg(v, long long), str, n, o);
  else if (o->specifier == 'f') {
    if (o->length == 'L')
      print_double(va_arg(v, long double), str, n, o);
    else
      print_double(va_arg(v, double), str, n, o);
  } else if (o->specifier == 'g' || o->specifier == 'G')
    if (o->length == 'L')
      print_g_double(va_arg(v, long double), str, n, o);
    else
      print_g_double(va_arg(v, double), str, n, o);
  else if (o->specifier == 'e' || o->specifier == 'E')
    if (o->length == 'L')
      print_exponent(va_arg(v, long double), str, n, o);
    else
      print_exponent(va_arg(v, double), str, n, o);
  else if (o->specifier == 's')
    print_string(va_arg(v, char *), str, n, o);
  else
    error++;

  if (!error) (*p_format)++;

  return error;
}

void print_char(int number, char *str, int *n, options *option) {
  option->precision = 0;
  int space_width = print_zero(1, 0, str, n, option);

  if (option->length == 'l')
    str[(*n)++] = (wchar_t)number;
  else
    str[(*n)++] = (char)number;

  while (space_width-- > 0) str[(*n)++] = ' ';
}

void print_integer(long long number, char *str, int *n, options *o) {
  int sign = 0, flag_long_min = 0;
  if (o->length == 'h')
    number = (short)number;
  else if (o->length != 'l')
    number = (int)number;

  if (number != LONG_MIN) {
    sign = get_sign(number, o);
    if (sign == '-') number = -number;
  } else {
    sign = '-';
    number = LONG_MAX;
    flag_long_min++;
  }

  int number_width = 1;
  if (number != 0)
    number_width = log10(number) + 1;
  else if (o->precision == 0)
    number_width = 0;

  int space_width = print_zero(number_width, sign, str, n, o);

  if (flag_long_min) number++;
  while (number_width-- > 0) {
    unsigned long long divider = pow(10, number_width);
    str[(*n)++] = (number / divider) % 10 + '0';
  }
  while (space_width-- > 0) str[(*n)++] = ' ';
}

void print_unsigned(unsigned long long number, char *str, int *n, options *o) {
  if (o->length == 'h')
    number = (unsigned short)number;
  else if (o->length != 'l')
    number = (unsigned int)number;

  int number_width = 1;
  if (number != 0)
    number_width = log10(number) + 1;
  else if (o->precision == 0)
    number_width = 0;

  int space_width = print_zero(number_width, 0, str, n, o);

  while (number_width-- > 0) {
    unsigned long long divider = pow(10, number_width);
    str[(*n)++] = (number / divider) % 10 + '0';
  }

  while (space_width-- > 0) str[(*n)++] = ' ';
}

void print_hex_oct(unsigned long number, char *str, int *n, options *option) {
  int base = 16, count = 0, remain[50] = {0};
  if (option->specifier == 'o') base = 8;

  if (option->specifier != 'p') {
    if (option->length == 'h')
      number = (unsigned short)number;
    else if (option->length != 'l')
      number = (unsigned int)number;
  }

  while (number) {
    remain[count] = number % base;
    number /= base;
    count++;
  }
  int space_width = print_zero(count, 0, str, n, option);

  if (count == 0 && option->precision != 0) str[(*n)++] = '0';
  while (count-- > 0) {
    int add = remain[count] > 9 ? 'a' - 10 + option->specifier - 'x' : '0';
    str[(*n)++] = remain[count] + add;
  }

  while (space_width-- > 0) str[(*n)++] = ' ';
}

void print_double(long double number, char *str, int *n, options *option) {
  if (option->precision < 0) option->precision = 6;
  int sign = get_sign(number, option);
  if (number < 0) number = -number;
  number = roundl(number * powl(10, option->precision));
  number /= powl(10, option->precision);
  long double whole = 0;
  long double dfraction = modfl(number, &whole);

  int number_width = 1;
  if (whole != 0) number_width = log10l(whole) + 1;
  long long fraction = llroundl(dfraction * powl(10, option->precision));
  int fraction_width = 0;
  if (fraction != 0) fraction_width = log10l(fraction) + 1;
  if ((option->specifier == 'g' || option->specifier == 'G') && fraction == 0)
    option->precision = 0;
  if (option->precision > 0) option->f_sharp = 1;
  int space_width = option->width - number_width - option->precision -
                    option->f_sharp - !!sign;
  int zero_width = 0;
  if (option->f_zero == 1 && option->f_minus == 0) {
    zero_width = space_width;
    space_width = 0;
  }
  int space_start = space_width;
  if (option->f_minus == 1) space_start = 0;
  print_number(space_start, option->f_minus, sign, zero_width, number_width,
               whole, str, n);

  space_width -= space_start;
  zero_width = option->precision - fraction_width;
  if (option->f_sharp) str[(*n)++] = '.';
  print_number(space_width, option->f_minus, 0, zero_width, fraction_width,
               fraction, str, n);
}

void print_g_double(long double number, char *str, int *n, options *option) {
  char *str_add = NULL;
  if (isinf(number)) str_add = "inf";
  if (isnan(number)) str_add = "nan";
  if (isinf(number) || isnan(number)) {
    int len = my_strlen(str_add);
    my_memcpy(str + *n, str_add, len);
    *n += len;
    return;
  }
  long double whole, buf_number = number;
  if (number < 0) buf_number = -number;
  long double dfraction = modfl(buf_number, &whole);
  int rate = 0;
  if (buf_number != 0) rate = log10l(buf_number);

  if (option->precision < 0) option->precision = 6;
  if (option->precision == 0) option->precision = 1;
  int number_width = 0;
  if (whole != 0) number_width = log10l(whole) + 1;

  if (rate <= -4 || rate >= option->precision) {
    option->precision -= 1;
    print_exponent(number, str, n, option);
  } else {
    if (option->precision > 0 && option->precision >= number_width)
      option->precision -= number_width;
    long long fraction = llroundl(dfraction * powl(10, option->precision));
    if (fraction != 0)
      while (fraction % 10 == 0) {
        fraction /= 10;
        option->precision--;
      }
    print_double(number, str, n, option);
  }
}

void print_exponent(long double number, char *str, int *n, options *option) {
  int sign = get_sign(number, option);
  if (number < 0) number = -number;

  int rate = 0;
  if (number != 0) rate = log10l(number);
  number /= pow(10, rate);
  long double whole = 0;
  long double dfraction = exp_normal(&number, &whole, &rate);
  if (option->precision == 0) number = roundl(number);
  if (option->precision < 0) option->precision = 6;
  long long fraction =
      rnd_dfraction(&number, &whole, &dfraction, &rate, option);
  int number_width = get_number_width(&fraction, option);
  int rate_sign = (rate < 0) ? -1 : 1;
  int rate_width = 1;
  if (rate != 0) rate_width = (int)log10l(rate * rate_sign) + 1;
  int sub = 0;
  if (rate_width > 2) sub += rate_width - 2;
  int space_width = option->width - option->precision - 1 - option->f_sharp -
                    4 - sub - !!sign;
  int zero_width = 0;
  if (option->f_zero == 1 && option->f_minus == 0) {
    zero_width = space_width;
    space_width = 0;
  }
  int space_start = space_width;
  if (option->f_minus == 1) space_start = 0;
  print_number(space_start, option->f_minus, sign, zero_width, 1, whole, str,
               n);

  zero_width = option->precision - number_width;
  if (option->f_sharp) str[(*n)++] = '.';
  print_number(0, 0, 0, zero_width, number_width, fraction, str, n);

  print_rate(space_width - space_start, zero_width, rate_width, rate, str, n,
             option);
}

long double exp_normal(long double *number, long double *whole, int *rate) {
  long double dfraction = modfl(*number, whole);
  if (*whole == 0 && dfraction != 0) {
    *number *= 10;
    *rate -= 1;
    dfraction = modfl(*number, whole);
  }
  return dfraction;
}

long long rnd_dfraction(long double *number, long double *whole,
                        long double *dfraction, int *rate, options *option) {
  if (option->specifier == 'g' || option->specifier == 'G') {
    if (*rate > 0) {
      *number = roundl(*number * powl(10, option->precision + *rate - 1));
      *number /= powl(10, option->precision + *rate - 1);
      *dfraction = modfl(*number, whole);
    }
    *dfraction = exp_normal(number, whole, rate);
  }
  if (*number != 0 && log10l(*number) != 0) {
    int rate_add = log10l(*number);
    *number /= pow(10, rate_add);
    *rate += rate_add;
  }
  *dfraction = modfl(*number, whole);

  return llroundl(*dfraction * powl(10, option->precision));
}

int get_number_width(long long *fraction, options *option) {
  int number_width = 0;
  if (*fraction != 0) number_width = ((int)log10l(*fraction) + 1);
  if (option->specifier == 'g' || option->specifier == 'G') {
    if (*fraction == 0)
      option->precision = 0;
    else if (option->f_sharp == 0)
      while (*fraction % 10 == 0) {
        *fraction /= 10;
        option->precision--;
        number_width--;
      }
    option->specifier = 'e';
  }
  if (number_width != 0 || option->precision != 0) option->f_sharp = 1;
  return number_width;
}

void print_rate(int space_width, int zero_width, int rate_width,
                long double rate, char *str, int *n, options *option) {
  int sign = '+';
  if (rate < 0) {
    rate = -rate;
    sign = '-';
  }
  str[(*n)++] = option->specifier;
  zero_width = 2 - rate_width;
  print_number(space_width, option->f_minus, sign, zero_width, rate_width, rate,
               str, n);
}

void print_string(char *str_arg, char *str, int *n, options *option) {
  char *str_null = "(null)";
  if (str_arg == NULL) str_arg = str_null;

  int str_length = my_strlen(str_arg);
  if (option->length == 'l') str_length = wcslen((const wchar_t *)str_arg);
  if (option->precision != -1 && str_length > option->precision)
    str_length = option->precision;

  option->precision = 0;
  int space_width = print_zero(str_length, 0, str, n, option);

  if (option->length != 'l') {
    for (int i = 0; i < str_length; i++) str[(*n)++] = *str_arg++;
  } else {
    wchar_t *w_str = (wchar_t *)str_arg;
    for (int i = 0; i < str_length; i++) str[(*n)++] = w_str[i];
  }

  while (space_width-- > 0) str[(*n)++] = ' ';
}

void print_number(int space_width, int flag_minus, int sign, int zero_width,
                  int number_width, long double number, char *str, int *n) {
  if (flag_minus == 0)
    while (space_width > 0) {
      str[(*n)++] = ' ';
      space_width--;
    }

  if (sign != 0) str[(*n)++] = sign;
  while (zero_width-- > 0) str[(*n)++] = '0';

  while (number_width-- > 0) {
    long double divider = pow(10, number_width);
    str[(*n)++] = (unsigned long long)(number / divider) % 10 + '0';
  }

  while (space_width-- > 0) str[(*n)++] = ' ';
}

int print_zero(int data_width, int sign, char *str, int *n, options *o) {
  int space_width = 0, zero_width = 0, sub = 0;

  if (o->specifier == 'o' && o->f_sharp && data_width != 0) sub++;
  if (((o->specifier == 'x' || o->specifier == 'X') && o->f_sharp &&
       data_width != 0) ||
      o->specifier == 'p')
    sub += 2;
  if (data_width == 0 && o->precision != 0) data_width++;
  if (o->precision > data_width) zero_width = o->precision - data_width;
  if (o->specifier == 'o') zero_width -= sub;
  space_width = o->width - data_width - zero_width - !!sign;
  if (o->specifier != 'c' || o->f_minus == 0) {
    if (o->f_zero && o->precision <= 0)
      zero_width = space_width, space_width = 0;
  }

  if (o->f_minus == 0)
    while (space_width - sub > 0) str[(*n)++] = ' ', space_width--;
  if (o->specifier == 'p') o->specifier = 'x';
  if (sub != 0) str[(*n)++] = '0';
  if (sub == 2) str[(*n)++] = o->specifier;

  if (sign) str[(*n)++] = sign;
  while (zero_width-- > 0) str[(*n)++] = '0';

  return space_width - sub;
}

int get_sign(long double number, options *option) {
  int sign = 0;
  if (number < 0)
    sign = '-';
  else if (option->f_plus)
    sign = '+';
  else if (option->f_space)
    sign = ' ';

  return sign;
}