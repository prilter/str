#include <malloc.h>

#include "../struct.h"

extern str *FAIL_ADDING;

str
___assign_substr___(str *self, const char *s, size_t st, size_t end)
{
  size_t buf;

  /* WRONG ARGUMENTS */
  if (!s)
    return *self;

  /* IF END > ST -> REVERSE ST AND END VALUES */
  if (end < st) {
    buf = st;
    st  = end;
    end = buf;
  }

  /* IF NOT ENOUGH MEMORY */
  if (self->alloced < end - st) {
    if (!(self->c_str = realloc(self->c_str, end - st + 1)))
      return *FAIL_ADDING;
    self->alloced = end - st + 1;
  }

  /* COPY */
  for (buf = st; *(s + buf) && end--; buf++)
    *(self->c_str + buf - st) = *(s + buf);

  return *self;
}

