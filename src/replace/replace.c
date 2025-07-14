#include <malloc.h>
#include <string.h>

#include "../struct.h"

int
replace(str *s,  size_t pos, size_t count, const char *add)
{
  if (pos > strlen(s->c_str) || !count || !pos)
    return WRONG_DATA;
  if (s->is_free)
    return UNSAFE;
  if (!add)
    return NO_DATA;

  char *ln = s->c_str + pos;
  for (;*ln && *add && count--;)
    *(ln++) = *(add++);

  for (;*ln && count--;) {
    memcpy(ln, ln+1, strlen(ln)-1);
    *(ln+strlen(ln)-1) = '\0';
    s->alloced -= sizeof(char);
  }
  
  s->c_str = realloc(s->c_str, s->alloced);
  return SUCCESS;
}
