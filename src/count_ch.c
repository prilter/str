#include "struct.h"

extern const size_t VALUE_WAS_RELEASED;

size_t
___count_ch___(str *s, int ch)
{
  size_t res;
  char  *s1;

  s1 = s->c_str;

  if (!s1 || s->is_free)
    return VALUE_WAS_RELEASED;

  for (res = 0; *s1; s1++)
    if (*s1 == ch)
      res++;

  return res;
}
