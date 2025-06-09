#include <string.h>
#include "../struct.h"

const char *FAIL_MAKING = NULL;

str
___emstr___(str *restrict self) /* string() FROM C++ */
{
  if (self->alloced == 0)
    self->alloced += 1;
  memset(self->c_str, 0, self->alloced);
  return *self;
}
