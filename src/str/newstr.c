#include "../struct.h"
#include <malloc.h>
#include <string.h>

extern str *FAIL_MAKING;

str
___newstr___(str *restrict self, const char *restrict s) /* LIKE string(const char *) FROM C++ */
{
  if (!s)
    return *self; 

  if (self->alloced < strlen(s)) {
    if (!(self->c_str = realloc(self->c_str, strlen(s) + 4)))
      return *FAIL_MAKING;
    self->alloced = strlen(s) + 4;
  }

  memcpy(self->c_str, s, self->alloced);
  return *self;
}
