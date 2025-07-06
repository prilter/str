#include <ctype.h>
#include "../struct.h"

str
uppercase(str *restrict s)
{
  char *b;

  if (s->is_free || !s->c_str)
    return *s;

  b = s->c_str;
  for (;*b; b++)
    *b = toupper(*b);

  return *s;
}
