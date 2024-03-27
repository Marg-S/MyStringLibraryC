#include "my_string.h"

/*Searches for the first occurrence of the character c (an unsigned char)
in the string pointed to, by the argument str*/

char *my_strchr(const char *str, int c) {
  char *ptr_c = (char *)str;
  while (*ptr_c != (char)c && *ptr_c != '\0') ptr_c++;
  if (*ptr_c == '\0' && *ptr_c != c) ptr_c = my_NULL;

  return ptr_c;
}
