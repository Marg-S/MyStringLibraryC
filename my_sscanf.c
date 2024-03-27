#include "my_sscanf.h"

int my_sscanf(const char *str, const char *format, ...) {
  va_list value;
  int n = 0, error = 0, num_char = 0;
  char *p_format = (char *)format;
  char *s = (char *)str;
  va_start(value, format);

  while (*p_format != '\0' && !error) {
    p_format = parse_format(&s, p_format, &num_char, &error);

    if (*p_format == '%') {
      options option = {0};
      p_format++;
      option.width = get_width(&p_format);
      option.length = get_length_sscanf(&p_format);
      get_argument_sscanf(&p_format, &option, &value, &s, &n, &num_char,
                          &error);
    }
  }
  va_end(value);

  return (error && !n) ? -1 : n;
}

void get_argument_sscanf(char **p_format, options *options, va_list *value,
                         char **str, int *n, int *num_char, int *error) {
  int is_assigned = 1;
  int is_n = 0;
  char *start_str = *str;
  options->specifier = **p_format;
  switch (**p_format) {
    case 'd':
    case 'i': {
      process_integer(options, &error, &str, &is_assigned, &value);
    } break;
    case 'o':
    case 'u':
    case 'x':
    case 'X': {
      process_hex_oct_unsigned(options, &error, &str, &is_assigned, &value);
    } break;
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G': {
      process_double(options, &error, &str, &is_assigned, &value);
    } break;
    case 'c': {
      process_char(options, &error, &str, &is_assigned, &value);
    } break;
    case 's': {
      process_string(options, &error, &str, &is_assigned, &value);
    } break;
    case 'n': {
      int *ptr = va_arg(*value, int *);
      *ptr = (int)(*num_char);
      is_assigned = 0;
      is_n = 1;
    } break;
    case '%': {
      is_assigned = 0;
      *str += 1;
    } break;
    case 'p': {
      process_pointer(&error, &str, &value, options, &is_assigned);
    } break;
    default:
      *error += 1;
      break;
  }
  if (!(*error)) {
    (*p_format)++;
    if (is_assigned) {
      (*n)++;
    }
    if (!is_n) {
      *num_char += *str - start_str;
    }
  }
}

void process_integer(options *o, int **error, char ***str, int *is_assigned,
                     va_list **value) {
  long result = 0;
  if (o->width != -1) {
    **error += write_integer(&str, o, &result);
  }
  if (**error) {
    *is_assigned = 0;
  } else {
    if (o->length == h) {
      if (o->width != -1) {
        short *ptr = (short *)va_arg(**value, void *);
        *ptr = (short)result;
      }
    } else if (o->length == l) {
      if (o->width != -1) {
        long *ptr = (long *)va_arg(**value, void *);
        *ptr = (long)result;
      }
    } else if (o->length == no_length) {
      if (o->width != -1) {
        int *ptr = (int *)va_arg(**value, void *);
        *ptr = (int)result;
      }
    } else {
      **error += 1;
    }
  }
  if (o->width == -1) {
    o->width = 0;
    write_integer(&str, o, &result);
    *is_assigned = 0;
  }
}

int write_integer(char ****str, options *o, long *num) {
  while (is_space(****str)) {
    ***str += 1;
  }
  int sign = 1;
  if (handle_sign(&str, &sign, o) == -1) {
    return -1;
  }
  int count = 0;
  while (is_digit(****str) && (!o->width || (o->width && count < o->width))) {
    *num = (*num * 10) + (****str - '0');
    (***str)++;
    count++;
  }
  if (count == 0) {
    return -1;
  }
  *num *= sign;
  return 0;
}

void process_hex_oct_unsigned(options *o, int **error, char ***str,
                              int *is_assigned, va_list **value) {
  if (o->length == h) {
    if (o->width != -1) {
      unsigned short *ptr = (unsigned short *)va_arg(**value, void *);
      if (o->specifier == 'o' || o->specifier == 'u') {
        **error += write_octal_unsigned(&str, o, ptr);
      } else {
        **error += write_hex(&str, o, ptr);
      }
    }
  } else if (o->length == l) {
    if (o->width != -1) {
      long unsigned *ptr = (unsigned long *)va_arg(**value, void *);
      if (o->specifier == 'o' || o->specifier == 'u') {
        **error += write_octal_unsigned(&str, o, ptr);
      } else {
        **error += write_hex(&str, o, ptr);
      }
    }
  } else if (o->length == no_length) {
    if (o->width != -1) {
      unsigned int *ptr = (unsigned int *)va_arg(**value, void *);
      if (o->specifier == 'o' || o->specifier == 'u') {
        **error += write_octal_unsigned(&str, o, ptr);
      } else {
        **error += write_hex(&str, o, ptr);
      }
    }
  } else {
    *error += 1;
  }
  if (o->width == -1) {
    unsigned long result = 0;
    o->width = 0;
    if (o->specifier == 'o' || o->specifier == 'u') {
      write_octal_unsigned(&str, o, &result);
    } else {
      write_hex(&str, o, &result);
    }
    *is_assigned = 0;
  }
}

int write_octal_unsigned(char ****str, options *o, void *num) {
  int base = 10;
  if (o->specifier == 'o') {
    base = 8;
  }
  while (is_space(****str)) {
    ***str += 1;
  }
  int count = 0;
  while (((is_digit(****str) && o->specifier == 'u') ||
          (is_octal_digit(****str) && o->specifier == 'o')) &&
         (!o->width || (o->width && count < o->width))) {
    if (o->length == no_length) {
      *(unsigned int *)num = (*(unsigned int *)num * base) + (****str - '0');
    } else if (o->length == h) {
      *(short unsigned *)num =
          (*(short unsigned *)num * base) + (****str - '0');
    } else {
      *(long unsigned *)num = (*(long unsigned *)num * base) + (****str - '0');
    }
    (***str)++;
    count++;
  }
  if (count == 0) {
    return 1;
  }

  return 0;
}

int write_hex(char ****str, options *o, void *num) {
  while (is_space(****str)) ***str += 1;
  int count = 0;
  if (handle_ox(str)) {
    ***str += 2;
    if (o->length == no_length) {
      *(unsigned int *)num = 0;
    } else if (o->length == h) {
      *(short unsigned *)num = 0;
    } else {
      *(long unsigned *)num = 0;
    }
  }
  while (is_hex_digit(****str) &&
         (!o->width || (o->width && count < o->width))) {
    if (o->length == no_length) {
      *(unsigned int *)num =
          (*(unsigned int *)num * 16) + hex_to_decimal(****str);
    } else if (o->length == h) {
      *(short unsigned *)num =
          (*(short unsigned *)num * 16) + hex_to_decimal(****str);
    } else {
      *(long unsigned *)num =
          (*(long unsigned *)num * 16) + hex_to_decimal(****str);
    }
    (***str)++;
    count++;
  }
  if (count == 0) {
    return 1;
  }

  return 0;
}

int write_double(char ****str, options *o, void *num) {
  while (is_space(****str)) ***str += 1;
  if (handle_G(&str, &num, o) == 1) {
    return 0;
  }
  int sign = 1, count = 0;
  if (handle_sign(&str, &sign, o) == -1) {
    return 1;
  }
  while (is_digit(****str) && (!o->width || (o->width && count < o->width))) {
    if (o->length == no_length) {
      *(float *)num = (*(float *)num * 10) + (****str - '0');
    } else if (o->length == l) {
      *(double *)num = (*(double *)num * 10) + (****str - '0');
    } else {
      *(long double *)num = (*(long double *)num * 10) + (****str - '0');
    }
    (***str)++;
    count++;
  }
  if (****str == '.' && (!o->width || (o->width && count < o->width))) {
    (***str)++;
    write_fraction(str, &count, o, num);
  }
  handle_exponent(&str, &count, o, &num);
  if (sign == -1) {
    if (o->length == no_length) {
      *(float *)num = -(*(float *)num);
    } else if (o->length == l) {
      *(double *)num = -(*(double *)num);
    } else {
      *(long double *)num = -(*(long double *)num);
    }
  }
  if (count == 0) {
    return 1;
  }
  return 0;
}

void write_fraction(char ****str, int *count, options *o, void *num) {
  long double fraction = 0.0, divisor = 1.0;
  while (is_digit(****str) &&
         (!o->width || (o->width && *count + 1 < o->width))) {
    fraction = (fraction * 10) + (****str - '0');
    divisor *= 10;
    (***str)++;
    *count += 1;
  }
  if (o->length == no_length) {
    *(float *)num += fraction / divisor;
  } else if (o->length == l) {
    *(double *)num += fraction / divisor;
  } else {
    *(long double *)num += fraction / divisor;
  }
}

void process_double(options *o, int **error, char ***str, int *is_assigned,
                    va_list **value) {
  if (o->length == L) {
    if (o->width != -1) {
      long double *ptr = (long double *)va_arg(**value, void *);
      *ptr = 0;
      **error += write_double(&str, o, (long double *)ptr);
    }
  } else if (o->length == l) {
    if (o->width != -1) {
      double *ptr = (double *)va_arg(**value, void *);
      *ptr = 0;
      **error += write_double(&str, o, (double *)ptr);
    }
  } else {
    if (o->width != -1) {
      float *ptr = (float *)va_arg(**value, void *);
      *ptr = 0;
      **error += write_double(&str, o, (float *)ptr);
    }
  }
  if (o->width == -1) {
    long double result = 0;
    o->width = 0;
    write_double(&str, o, &result);
    *is_assigned = 0;
  }
}

void process_char(options *o, int **error, char ***str, int *is_assigned,
                  va_list **value) {
  if (o->length == l) {
    if (o->width != -1) {
      wchar_t *ptr = (wchar_t *)va_arg(**value, void *);
      *ptr = (wchar_t)(unsigned char)***str;
      **str += o->width || 1;
    }
  } else if (o->length == no_length) {
    if (o->width != -1) {
      char *ptr = (char *)va_arg(**value, void *);
      *ptr = ***str;
      **str += o->width ? o->width : 1;
    }
  } else {
    **error += 1;
  }
  if (o->width == -1) {
    **str += 1;
    *is_assigned = 0;
  }
}

void process_string(options *o, int **error, char ***str, int *is_assigned,
                    va_list **value) {
  while (is_space(***str)) {
    **str += 1;
  }
  if (***str == '\0') {
    *is_assigned = 0;
    **error += 1;
    return;
  }
  if (o->length == l) {
    if (o->width != -1) {
      wchar_t *ptr = (wchar_t *)va_arg(**value, void *);
      write_string(&str, o, ptr);
    }
  } else if (o->length == no_length) {
    if (o->width != -1) {
      char *ptr = (char *)va_arg(**value, void *);
      write_string(&str, o, ptr);
    }
  } else {
    **error += 1;
  }
  if (o->width == -1) {
    while (!is_space(***str) && ***str != '\0') {
      **str += 1;
    }
    *is_assigned = 0;
  }
}

void write_string(char ****str, options *o, void *ptr) {
  int i = 0;
  while (((o->width && i < o->width) || !o->width) &&
         !is_space(*(***str + i)) && *(***str + i) != '\0') {
    if (o->length == l) {
      *(wchar_t *)(ptr + i) = *(***str + i);
    } else {
      *(char *)(ptr + i) = *(***str + i);
    }

    i++;
  }
  if (o->length == l) {
    *(char *)(ptr + i) = '\0';
  } else {
    *(char *)(ptr + i) = '\0';
  }

  ***str += i;
}

void process_pointer(int **error, char ***str, va_list **value, options *o,
                     int *is_assigned) {
  uintptr_t addr = 0;
  int valid_hex = 0;
  int i = 0;

  if (handle_ox(&str)) {
    i += 2;
    **str += 2;
    valid_hex = 1;
  }

  while (is_hex_digit(***str) &&
         ((o->width && i < o->width) || !o->width || o->width == -1)) {
    valid_hex = 1;
    addr = (addr << 4) | hex_to_decimal(***str);
    **str += 1;
    i++;
  }

  if (valid_hex) {
    if (o->width != -1) {
      void **ptr = va_arg(**value, void **);
      *ptr = (void *)addr;
    } else {
      *is_assigned = 0;
    }
  } else {
    **error += 1;
  }
}

char *parse_format(char **str, char *p_format, int *num_char, int *error) {
  while (*p_format != '\0' && *p_format != '%') {
    if ((**str != *p_format)) {
      if (is_space(*p_format)) {
        p_format++;
      } else {
        *error += 1;
        break;
      }
    } else {
      (*str)++;
      *num_char += 1;
      p_format++;
    }
  }
  return p_format;
}

int get_width(char **p_format) {
  int width = 0;
  if (**p_format == '*') {
    width = -1;
    (*p_format)++;
  } else {
    while (**p_format >= '0' && **p_format <= '9') {
      width = width * 10 + **p_format - '0';
      (*p_format)++;
    }
  }

  return width;
}

int get_length_sscanf(char **p_format) {
  enum length_type length;
  switch (**p_format) {
    case 'h':
      length = h;
      break;
    case 'l':
      length = l;
      break;
    case 'L':
      length = L;
      break;
    default:
      length = no_length;
  }
  if (length != no_length) (*p_format)++;

  return length;
}

// Helper functions
int is_space(char ch) {
  return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n';
}

int is_digit(char ch) { return ch >= '0' && ch <= '9'; }

int is_octal_digit(char ch) { return (ch >= '0' && ch <= '7'); }

int is_hex_digit(char ch) {
  return (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') ||
         (ch >= 'a' && ch <= 'f');
}

int hex_to_decimal(char ch) {
  if (ch >= '0' && ch <= '9')
    return ch - '0';
  else if (ch >= 'A' && ch <= 'F')
    return ch - 'A' + 10;
  else if (ch >= 'a' && ch <= 'f')
    return ch - 'a' + 10;
  else
    return -1;
}

void handle_exponent(char *****str, int *count, options *o, void **num) {
  if ((*****str == 'E' || *****str == 'e') &&
      (!o->width || (o->width && *count < o->width))) {
    (****str)++;
    char exponent_sign_ch = *****str;

    if (exponent_sign_ch == '+' || exponent_sign_ch == '-') {
      (****str)++;
    } else {
      exponent_sign_ch = '+';
    }
    int exponent = 0;
    int exponent_sign = (exponent_sign_ch == '-') ? -1 : 1;

    while (is_digit(*****str) &&
           (!o->width || (o->width && (*count < o->width)))) {
      exponent = (exponent * 10) + (*****str - '0');
      (****str)++;
      (*count)++;
    }

    if (o->length == no_length) {
      int sub = 100;
      if (exponent_sign < 0) {
        sub = 1000000;
        *(float *)*num = (*(float *)*num / sub) *
                         (powf(10.0f, exponent_sign * exponent) * sub);
      } else {
        *(float *)*num = (*(float *)*num * sub) *
                         (powf(10.0f, exponent_sign * exponent) / sub);
      }
    } else if (o->length == l) {
      *(double *)*num *= pow(10.0, exponent_sign * exponent);
    } else {
      *(long double *)*num *= powl(10.0L, exponent_sign * exponent);
    }
  }
}

int handle_G(char *****str, void **num, options *o) {
  int result = 0;
  char str_copy[10] = {'\0'};
  char *str_lower = my_to_lower(my_strncpy(str_copy, ****str, 4));
  if (my_strncmp(str_lower, "inf", 3) == 0) {
    if (o->length == no_length) {
      *(float *)*num = INFINITY;
    } else if (o->length == l) {
      *(double *)*num = INFINITY;
    } else {
      *(long double *)*num = INFINITY;
    }
    ****str += 3;
    result = 1;
  } else if (my_strncmp(str_lower, "+inf", 4) == 0) {
    if (o->length == no_length) {
      *(float *)*num = INFINITY;
    } else if (o->length == l) {
      *(double *)*num = INFINITY;
    } else {
      *(long double *)*num = INFINITY;
    }
    ****str += 4;
    result = 1;
  } else if (my_strncmp(str_lower, "-inf", 4) == 0) {
    if (o->length == no_length) {
      *(float *)*num = -INFINITY;
    } else if (o->length == l) {
      *(double *)*num = -INFINITY;
    } else {
      *(long double *)*num = -INFINITY;
    }
    ****str += 4;
    result = 1;
  } else if (my_strncmp(str_lower, "nan", 3) == 0) {
    if (o->length == no_length) {
      *(float *)*num = NAN;
    } else if (o->length == l) {
      *(double *)*num = NAN;
    } else {
      *(long double *)*num = NAN;
    }
    ****str += 3;
    result = 1;
  }
  free(str_lower);
  return result;
}

int handle_ox(char ****str) {
  if (****str == '0' && (*(***str + 1) == 'x' || *(***str + 1) == 'X')) {
    return 1;
  }
  return 0;
}

int handle_sign(char *****str, int *sign, options *o) {
  int result = 0;
  if (*****str == '-' || *****str == '+') {
    if (*****str == '-') {
      *sign = -1;
    }
    (****str)++;
    if (o->width > 1) {
      o->width--;
    } else if (o->width == 1) {
      result = -1;
    }
  }
  return result;
}
// End of Helper functions