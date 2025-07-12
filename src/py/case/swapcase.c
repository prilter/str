#include <ctype.h>
#include "../../struct.h"

str
swapcase(str *restrict s)
{
  char *b;

  if (s->is_free || !s->c_str)
    return *s;

  b = s->c_str;
  for (;*b; b++)
    *b = islower(*b) ? toupper(*b):tolower(*b);

  return *s;
}
