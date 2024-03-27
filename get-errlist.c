#include <stdio.h>
#include <string.h>

int main() {
  for (int i = -5; i < 145; i++) printf("[%d] \"%s\"\n", i, strerror(i));
}
