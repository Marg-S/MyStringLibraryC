#include "my_string.h"

/*Searches for the first occurrence of the character c
(an unsigned char) in the first n bytes of the string pointed to, by the
argument str.*/

void *my_memchr(const void *str, int c, my_size_t n) {
  const char *s = (const char *)str;
  my_size_t i = 0;

  while (i < n) {
    if (s[i] == (char)c) {
      return (void *)(s + i);
    }
    i++;
  }

  return my_NULL;
}