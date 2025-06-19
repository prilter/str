#include "../struct.h"
#include <malloc.h>
#include <string.h>

extern str *FAIL_MAKING;

str
___newnstr___(str *self, const char *s, size_t n) /* LIKE string(const char *, size_t) FROM C++ */
{
  if (self->alloced < strlen(s)) {
    if (!(self->c_str = realloc(self->c_str, strlen(s) + 4)))
      return *FAIL_MAKING;
    self->alloced = strlen(s) + 4;
  }

  memcpy(self->c_str, s, self->alloced <= n ? self->alloced:n);
  return *self;
}
