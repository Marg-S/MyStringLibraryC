#include "my_string.h"

// Копирует n символов из src в dest.

void *my_memcpy(void *dest, const void *src, my_size_t n) {
  char *d = (char *)dest;
  const char *s = (const char *)src;
  my_size_t i = 0;
  while (i < n) {
    d[i] = s[i];
    i++;
  }
  return dest;
}