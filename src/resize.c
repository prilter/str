#include <malloc.h>
#include <string.h>

#include "struct.h"

const void *UNSAFE = NULL;
extern const void *FAIL_MAPPING;

void
resize(str *restrict s, size_t sz)
{
  if (sz < strlen(s->c_str) * sizeof(char))
    return (void)(*UNSAFE);

  if (!(s->c_str = realloc(s->c_str, sz)))
    return (void)*FAIL_MAPPING;

  s->capacity = sz;
}
