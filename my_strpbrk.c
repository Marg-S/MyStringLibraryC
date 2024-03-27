#include "my_string.h"

/*Finds the first character in the string str1 that matches
any character specified in str2*/

char *my_strpbrk(const char *str1, const char *str2) {
  char *ptr_c = (char *)str1;
  char *ptr_find = my_NULL;

  do {
    ptr_find = (char *)str2;
    while (*ptr_find != '\0' && *ptr_c != *ptr_find) ptr_find++;
  } while (*ptr_find == '\0' && *++ptr_c != '\0');
  if (*ptr_find == '\0') ptr_c = my_NULL;

  return ptr_c;
}
