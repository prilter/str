#include "struct.h"

size_
___count_ch___(str *s, int ch)
{
  size_ res;
  char *s1 = s->c_str;

  for (res = 0; *s1; s1++)
    if (*s1 == ch)
      res++;

  return res;
}
