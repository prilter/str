#include <malloc.h>
#include <string.h>

#include "struct.h"

int
resize(str *restrict s, size_t sz)
{
  if (sz < strlen(s->c_str) * sizeof(char) || s->is_free)
    return UNSAFE;

  if (!(s->c_str = realloc(s->c_str, sz)))
    return FAIL_MAPPING;
  s->capacity = sz;

  return SUCCESS;
}
