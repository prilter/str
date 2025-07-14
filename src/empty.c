#include "struct.h"
#include <string.h>
#include <ctype.h>

int
empty(str *restrict s)
{
  if (strcmp(s->c_str, "\0") == 0 || s->is_free)
    return 1;

  for (;*s->c_str;)
    if (!isspace(*s->c_str++))
      return 0;

  return 1;
}
