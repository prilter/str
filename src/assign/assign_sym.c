#include <string.h>
#include <malloc.h>
#include "../struct.h"

extern str *FAIL_ADDING;

str
___assign_char___(str *self, size_ len, int sym) 
{
  if (!len)
    return *self;

  if (self->alloced < len) {
    if (!(self->c_str = realloc(self->c_str, len)))
      return *FAIL_ADDING;
    self->alloced = len;
  }

  memset(self->c_str, sym, len);
  return *self;
}
