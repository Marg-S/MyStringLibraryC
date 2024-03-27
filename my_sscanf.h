#ifndef my_SSCANF
#define my_SSCANF
#include <float.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <wchar.h>

#include "my_string.h"

enum length_type { h, l, L, no_length };

typedef struct {
  int width;
  int length;
  int specifier;
} options;

char *parse_format(char **str, char *p_format, int *num_char, int *error);
int get_width(char **p_format);
int get_length_sscanf(char **p_format);
void get_argument_sscanf(char **p_format, options *options, va_list *value,
                         char **str, int *n, int *num_char, int *error);

void process_integer(options *o, int **error, char ***str, int *is_assigned,
                     va_list **value);
void process_double(options *o, int **error, char ***str, int *is_assigned,
                    va_list **value);
void process_hex_oct_unsigned(options *o, int **error, char ***str,
                              int *is_assigned, va_list **value);
void process_char(options *o, int **error, char ***str, int *is_assigned,
                  va_list **value);
void process_string(options *o, int **error, char ***str, int *is_assigned,
                    va_list **value);
void process_pointer(int **error, char ***str, va_list **value, options *o,
                     int *is_assigned);

int write_integer(char ****str, options *o, long *num);
int write_octal_unsigned(char ****str, options *o, void *num);
int write_hex(char ****str, options *o, void *num);
int write_double(char ****str, options *o, void *num);
void write_string(char ****str, options *o, void *ptr);

int handle_ox(char ****str);
int handle_sign(char *****str, int *sign, options *o);
int handle_G(char *****str, void **num, options *o);
void handle_exponent(char *****str, int *count, options *o, void **num);
void write_fraction(char ****str, int *count, options *o, void *num);

int is_space(char ch);
int is_digit(char ch);
int hex_to_decimal(char ch);
int is_hex_digit(char ch);
int is_octal_digit(char ch);

#endif  // my_SSCANF