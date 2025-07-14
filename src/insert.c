#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "struct.h"

/* INSERT */
int
insert(str *line, const char *s, size_t x)
{
  size_t linelen, slen;

  if (line->is_free)
    return UNSAFE;
  if (!s)
    return NO_DATA;

  linelen = strlen(line->c_str);
  slen    = strlen(s);

  if (x > linelen)
    x = linelen;

  if (line->alloced <= linelen + slen) {
    if (!(line->c_str = realloc(line->c_str, line->alloced + slen + 4)))
      return FAIL_MAPPING;
    line->alloced += slen + 4;
  }

  memcpy(line->c_str + x + slen, line->c_str + x, linelen - x + 1);
  for (;*s;)
    *(line->c_str + x++) = *s++;

  return SUCCESS;
}

/* INSERT_N */
int
insert_n(str *line, const char *s, size_t x, size_t n)
{
  char buf[n];
  memcpy(buf, s, n);
  buf[n] = '\0';

  return insert(line, buf, x);
}

/* INSERT_CH */
int
insert_ch(str *line, const char ch, size_t x)
{
  size_t linelen;

  if (line->is_free)
    return UNSAFE;
  linelen = strlen(line->c_str);

  if (x > linelen)
    x = linelen;

  if (line->alloced <= linelen + 1) {
    if (!(line->c_str = realloc(line->c_str, line->alloced + 5)))
      return FAIL_MAPPING;
    line->alloced += 5;
  }

  memcpy(line->c_str + x + 1, line->c_str + x, linelen - x + 1);
  *(line->c_str + x) = ch;

  return SUCCESS;
}
