#include <string.h>
#include "../struct.h"

const char *FAIL_MAKING = NULL;

str
emstr(str *restrict s) /* string() FROM C++ */
{
  if (s->alloced == 0)
    s->alloced++;
  memset(s->c_str, 0, s->alloced);
  return *s;
}
