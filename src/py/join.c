#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "../struct.h"

extern const char *FAIL_ADDING;
extern const str  *FAIL_MAPPING;

#define MAPPING(S, len) \
  if (S->alloced < len) {\
    if (!(S->c_str = realloc(S->c_str, len + 4)))\
      return *FAIL_MAPPING;\
    S->alloced = len + 4;\
  }
#define len strlen(ln->c_str)

str
join(str *ln, const char *sep, char *s)
{
  if (ln->is_free || !s)
    return *(str *)FAIL_ADDING;

  if (!sep)
    return *ln;

  MAPPING(ln, 2*strlen(sep)*strlen(s));
  memset(ln->c_str, 0, ln->alloced);

  *ln->c_str = *s++;
  for (;*s;)
    snprintf(ln->c_str + len, ln->alloced - len, "%s%c", sep, *s++);

  return *ln;
}
