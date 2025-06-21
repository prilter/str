#include <stdio.h>
#include <stdlib.h>

#define ASSERTATION(cond, err_output) do { \
  if (!(cond)) {\
    fputs(err_output, stderr);\
    exit(1);\
  }\
} while (0);

long int
stoi(const char *num, size_t *pos, int base) 
{
  char* endptr;
  long int res;

  ASSERTATION(num && *num != '\0', "Empty argument\n\twhat: number argument of stoi\n");
  ASSERTATION(pos, "Wrong argument\n\twhat: pos pointer equal NULL for stoi function\n");
  ASSERTATION((base == 0) || (base >= 2 && base <= 36), "Wrong argument\n\twhat: base argument of stoi\n");

  res = strtol(num, &endptr, base);
  ASSERTATION(*endptr == '\0', "Invalid argument\n\twhat():  stoi\n");
  *pos = endptr - num;

  return res;
}

