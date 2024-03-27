#include "my_string.h"

void *my_insert(const char *src, const char *str, my_size_t start_index) {
  if (src == my_NULL || str == my_NULL) {
    return my_NULL;
  }
  my_size_t length = my_strlen(src);

  if (length < start_index) {
    return my_NULL;
  }
  my_size_t i = 0, j = 0, k = 0;

  int str_length = my_strlen(src);
  char *result = (char *)calloc(length + str_length + 1, sizeof(char));

  for (; k < start_index; k++) {
    result[j] = src[k];
    j++;
  }
  while (str[i] != '\0') {
    result[j] = str[i];
    j++;
    i++;
  }
  while (src[k] != '\0') {
    result[j] = src[k];
    j++;
    k++;
  }

  return result;
}