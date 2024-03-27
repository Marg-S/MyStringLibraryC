#include "my_string.h"

/*Добавляет строку, на которую указывает src, в конец строки,
на которую указывает dest, длиной до n символов.*/

char *my_strncat(char *dest, const char *src, my_size_t n) {
  int i = 0;
  while (dest[i] != '\0') {
    i++;
  }
  int j = 0;
  while (n-- && src[j] != '\0') {
    dest[i] = src[j];
    j++;
    i++;
  }
  dest[i] = '\0';

  return dest;
}