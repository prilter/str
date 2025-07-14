#include <string.h>
#include "../struct.h"

int
emstr(str *restrict s) /* string() FROM C++ */
{
  if (s->is_free)
    return UNSAFE;
  if (!s->data)
    return SUCCESS;
  if (s->alloced == 0)
    s->alloced++;

  memset(s->c_str, 0, s->alloced);
  return SUCCESS;
}
