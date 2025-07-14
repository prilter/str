#include <string.h>
#include "struct.h"

size_t
count(str *ln, const char *sub)
{
  char  *s;
  size_t res;
  size_t sublen;

  s = ln->c_str;
  if (!sub) 
    return (size_t)NO_DATA;
  if (ln->is_free)
    return (size_t)UNSAFE;
  if (!s)
    return 0;

  for (res = 0, sublen = strlen(sub); (s = strstr(s, sub)); s += sublen, res++);
  return res;
}

size_t
count_ch(str *s, int ch)
{
  size_t res;
  char  *s1;

  s1 = s->c_str;
  if (s->is_free)
    return UNSAFE;
  if (!s1)
    return 0;

  for (res = 0; *s1; s1++)
    if (*s1 == ch)
      res++;

  return res;
}
