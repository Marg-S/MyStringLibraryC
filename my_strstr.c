#include "my_string.h"

/*Finds the first occurrence of the entire string needle (not including
the terminating null character) which appears in the string haystack*/

char *my_strstr(const char *haystack, const char *needle) {
  char *ptr_c = (char *)haystack;
  char *ptr_find = my_NULL;

  do {
    ptr_find = (char *)needle;
    char *ptr_temp = ptr_c;
    while (*ptr_find != '\0' && *ptr_temp == *ptr_find) {
      ptr_temp++;
      ptr_find++;
    }
  } while (*ptr_find != '\0' && *++ptr_c != '\0');
  if (*ptr_c == '\0' && *needle != '\0') ptr_c = my_NULL;

  return ptr_c;
}
