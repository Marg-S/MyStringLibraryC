#include <stdio.h>

#include "my_string.h"

/*Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
 * которую указывает аргумент str.*/

char *my_strrchr(const char *str, int c) {
  char *last_occurence = my_NULL;
  while (*str) {
    if (*str == c) {
      last_occurence = (char *)str;
    }
    str++;
  }
  if (*str == c) {
    last_occurence = (char *)str;
  }

  return last_occurence;
}