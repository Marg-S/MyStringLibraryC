#include "my_string.h"

/*Вычисляет длину начального сегмента str1, который полностью состоит из
 * символов, не входящих в str2.*/

my_size_t my_strcspn(const char *str1, const char *str2) {
  my_size_t i = 0;
  while (str1[i] != '\0') {
    my_size_t j = 0;
    while (str2[j] != '\0') {
      if (str1[i] == str2[j]) {
        return i;
      }
      j++;
    }
    i++;
  }
  return i;
}