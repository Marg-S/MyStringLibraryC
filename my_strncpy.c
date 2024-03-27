#include "my_string.h"

/*Copies up to n characters from the string pointed to, by src to dest*/

char *my_strncpy(char *dest, const char *src, my_size_t n) {
  char *buf = dest;
  int i = 0;
  while (i < (int)n && src[i] != '\0') {
    buf[i] = src[i];
    i++;
  }
  while (i < (int)n) buf[i++] = '\0';

  return dest;
}
