#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "../struct.h"

extern str *FAIL_ADDING;

str
___insert_char___(str *line, const char ch, size_t x)
{
  size_t linelen;

  linelen = strlen(line->c_str);

  if (x > linelen)
    x = linelen;

  if (line->alloced <= linelen + 1) {
    if (!(line->c_str = realloc(line->c_str, line->alloced + 5)))
      return *FAIL_ADDING;
    line->alloced += 5;
  }

  memcpy(line->c_str + x + 1, line->c_str + x, linelen - x + 1);
  *(line->c_str + x) = ch;

  return *line;
}
