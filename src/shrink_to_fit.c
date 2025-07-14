#include <malloc.h>
#include <string.h>

#include "struct.h"

int
shrink_to_fit(str *restrict s)
{
  size_t len;

  if (s->is_free)
    return UNSAFE;

  len = strlen(s->c_str);
  if ((s->data = realloc(s->data, len * sizeof(char) + 4)))
    s->alloced = len * sizeof(char) + 4;

  return SUCCESS;
}
