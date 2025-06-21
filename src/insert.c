#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "struct.h"

extern str *FAIL_ADDING;

/* INSERT */
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

/* INSERT_N */
str
___insert_n___(str *line, const char *s, size_t x, size_t n)
{
  char buf[n];
  memcpy(buf, s, n);
  buf[n] = '\0';

  return ___insert___(line, buf, x);
}

/* INSERT_CH */
str
___insert_ch___(str *line, const char ch, size_t x)
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
