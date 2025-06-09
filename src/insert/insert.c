#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "../struct.h"

extern str *FAIL_ADDING;

str
___insert___(str *line, const char *s, size_t x)
{
  size_t linelen, slen;

  linelen = strlen(line->c_str);
  slen    = strlen(s);

  if (x > linelen)
    x = linelen;

  if (line->alloced <= linelen + slen) {
    if (!(line->c_str = realloc(line->c_str, line->alloced + slen + 4)))
      return *FAIL_ADDING;
    line->alloced += slen + 4;
  }

  memcpy(line->c_str + x + slen, line->c_str + x, linelen - x + 1);
  for (;*s;)
    *(line->c_str + x++) = *s++;

  return *line;
}
