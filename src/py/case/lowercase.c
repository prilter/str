#include <ctype.h>
#include "../../struct.h"

int
lowercase(str *restrict s)
{
  char *b;

  if (!s->data)
    return SUCCESS;
  if (s->is_free)
    return UNSAFE;

  b = s->c_str;
  for (;*b; b++)
    *b = tolower(*b);

  return SUCCESS;
}
