#include <string.h>
#include "../struct.h"

const char *FAIL_MAKING = NULL;

str
emstr(str *restrict self) /* string() FROM C++ */
{
  if (self->alloced == 0)
    self->alloced++;
  memset(self->c_str, 0, self->alloced);
  return *self;
}
