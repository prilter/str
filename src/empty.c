#include "struct.h"
#include <string.h>
#include <ctype.h>

int
___empty___(str *restrict self)
{
  if (strcmp(self->c_str, "\0") == 0 || self->is_free)
    return 1;

  for (;*self->c_str;)
    if (!isspace(*self->c_str++))
      return 0;

  return 1;
}
