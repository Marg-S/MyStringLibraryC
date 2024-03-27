#include "my_string.h"

/*Compares the first n bytes of str1 and str2*/

int my_memcmp(const void *str1, const void *str2, my_size_t n) {
  int cmp_result = 0;

  for (my_size_t i = 0; i < n && !cmp_result; i++)
    cmp_result = ((char *)str1)[i] - ((char *)str2)[i];

  return cmp_result;
}
