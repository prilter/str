#include <stdio.h>
#include <stdlib.h>

#define ASSERTATION(cond, err_output) do { \
  if (!(cond)) {\
    fputs(err_output, stderr);\
    exit(1);\
  }\
} while (0);

float
stof(const char *num, size_t *pos) 
{
  char* endptr;
  float res;

  ASSERTATION(num && *num != '\0', "Empty argument\n\twhat: number argument of stof\n");
  ASSERTATION(pos, "Wrong argument\n\twhat: pos pointer equal NULL for stof function\n");

  res = strtof(num, &endptr);
  ASSERTATION(*endptr, "Invalid argument\n\twhat():  stof\n");

  *pos = endptr - num;
  return res;
}

