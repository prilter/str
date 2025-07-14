#include <string.h>
#include <malloc.h>

#include "../struct.h"

int
pop_back(str *restrict s)
{
  if (!s->data)
    return NO_DATA;
  if (s->is_free)
    return UNSAFE;

  *(s->c_str + strlen(s->c_str) - 1) = '\0';
  if (!(s->c_str = realloc(s->c_str, s->alloced - sizeof(char))))
    return FAIL_MAPPING;
  s->alloced -= sizeof(char);
  return SUCCESS;
}
