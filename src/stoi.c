#include <stdio.h>
#include <stdlib.h>

long int
stoi(const char *num, size_t *pos, int base) 
{
  char* endptr;
  long int res;

  if (!num || *num == '\0') {
    fputs("Empty argument\n\twhat: number argument of stoi\n", stderr);
    exit(1);
  }

  if (!pos) {
    fputs("Wrong argument\n\twhat: pos pointer equal NULL for stoi function\n", stderr);
    exit(1);
  }

  if (base != 0 && (base < 2 || base > 36)) {
    fputs("Wrong argument\n\twhat: base argument of stoi\n", stderr);
    exit(1);
  }

  res = strtol(num, &endptr, base);
  if (*endptr != '\0') {
    fputs("Invalid argument\n\twhat():  stoi\n", stderr);
    exit(1);
  }
  *pos = endptr - num;

  return res;
}

