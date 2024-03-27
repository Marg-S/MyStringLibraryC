#include "my_string.h"

/*computes the length of the string str up to,
but not including the terminating null character.*/

my_size_t my_strlen(const char *str) {
  my_size_t length = 0;
  for (; *(str + length); length++)
    ;

  return length;
}