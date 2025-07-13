#include <malloc.h>
#include <string.h>

#include "struct.h"

void
shrink_to_fit(str *restrict s)
{
  size_t len;
  len = strlen(s->c_str);
  if ((s->c_str = realloc(s->c_str, len * sizeof(char) + 4)))
    s->alloced = len * sizeof(char) + 4;
}
