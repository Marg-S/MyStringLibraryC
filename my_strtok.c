#include "my_string.h"

/*breaks string str into a series of tokens using the delimiter delim.*/

int is_delim(char ch, const char *delim);

char *my_strtok(char *str, const char *delim) {
  static char *last_token = my_NULL;

  if (!str) {
    str = last_token;
  }
  if (!str) {
    return my_NULL;
  }
  while (*str != '\0' && is_delim(*str, delim)) {
    str++;
  }
  if (*str == '\0') {
    last_token = str;
    return my_NULL;
  }

  char *token_start = str;

  while (*str != '\0' && !is_delim(*str, delim)) {
    str++;
  }

  if (*str == '\0') {
    last_token = str;
  } else {
    *str = '\0';
    last_token = str + 1;
  }

  return token_start;
}

int is_delim(char ch, const char *delim) {
  int i = 0;
  while (delim[i] != '\0') {
    if (delim[i] == ch) {
      return 1;
    }
    i++;
  }
  return 0;
}
