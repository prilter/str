#include <stdio.h>
#include "src/str.h"

/* GET ENGLISH ALPHABET */
int 
main(void)
{
  const char *s = "123.45abc";
  size_t idx;

  float f = stof(s, &idx);
  printf("Source: %s\nResult: %.2f\nParsed up to index: %zu\nRemaining string: '%s'\n", s, f, idx, s + idx);

  return 0;
}
