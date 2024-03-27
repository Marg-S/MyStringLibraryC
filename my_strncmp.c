#include "my_string.h"

/*compares at most the first n bytes of str1 and str2.*/

int my_strncmp(const char *str1, const char *str2, my_size_t n) {
  int cmp_result = 0;
  my_size_t i = 0;
  while (i < n && !cmp_result && str1[i] != '\0') {
    cmp_result = str1[i] - str2[i];
    i++;
  }
  if (!i) {
    cmp_result = str1[i] - str2[i];
#ifdef __linux__
    if (cmp_result && n > 1) {
      cmp_result = cmp_result < 0 ? -1 : 1;
    }
#endif
  }

  return cmp_result;
}