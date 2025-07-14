#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "../struct.h"

#define MAPPING(S, len) \
  if (S->alloced < len) {\
    if (!(S->c_str = realloc(S->c_str, len + 4)))\
      return FAIL_MAPPING;\
    S->alloced = len + 4;\
  }
#define len strlen(ln->c_str)

int
join(str *ln, const char *sep, char *s)
{
  if (ln->is_free)
    return UNSAFE;
  if (!s || !sep)
    return NO_DATA;

  MAPPING(ln, 2*strlen(sep)*strlen(s));
  memset(ln->c_str, 0, ln->alloced);

  *ln->c_str = *s++;
  for (;*s;)
    snprintf(ln->c_str + len, ln->alloced - len, "%s%c", sep, *s++);

  return SUCCESS;
}
