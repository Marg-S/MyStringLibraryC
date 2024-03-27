#include "my_string.h"

int check_is_trimmed(char ch, const char *trim_chars);

void *my_trim(const char *src, const char *trim_chars) {
  if (src == my_NULL) {
    return my_NULL;
  }
  int i = 0, j = 0, k = 0, l = -1;
  int length = my_strlen(src);
  char *result = (char *)calloc(length + 1, sizeof(char));
  if (result == my_NULL) {
    return my_NULL;
  }
  if (trim_chars == my_NULL) {
    for (i = 0; i < length; i++) {
      result[i] = src[i];
    }
    return result;
  }
  char *trim_str = (char *)calloc(length + 1, sizeof(char));
  if (trim_str == my_NULL) {
    return my_NULL;
  }
  for (; i < length; i++) {
    int is_trimmed = check_is_trimmed(src[i], trim_chars);
    if (!is_trimmed) {
      result[k] = src[i];
      k++;
      break;
    }
  }
  for (i = i + 1; i < length; i++) {
    int is_trimmed = check_is_trimmed(src[i], trim_chars);
    if (!is_trimmed) {
      for (j = 0; j <= l; j++, k++) {
        result[k] = trim_str[j];
      }
      l = -1;
      result[k] = src[i];
      k++;
    } else {
      l++;
      trim_str[l] = src[i];
    }
  }
  free(trim_str);
  return result;
}

int check_is_trimmed(char ch, const char *trim_chars) {
  int trim_chars_length = my_strlen(trim_chars);
  for (int j = 0; j < trim_chars_length; j++) {
    if (ch == trim_chars[j]) {
      return 1;
    }
  }
  return 0;
}