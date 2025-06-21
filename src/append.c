/* APPEND CONST CHAR * TO THE END OF STR */
#include <string.h>
#include <malloc.h>
#include "struct.h"

extern str *FAIL_ADDING;

str 
___append___(str *self, const char *s) 
{
  size_t dlen = strlen(self->c_str);
  size_t slen = strlen(s);

  if (dlen + slen + 1 > self->alloced) {
      if (!(self->c_str = realloc(self->c_str, dlen + slen + 1)))
        return *FAIL_ADDING;
      self->alloced = dlen + slen + 1;
  }

  memcpy(self->c_str + dlen, s, slen + 1);
  return *self;
}

str 
___append_n___(str *self, const char *s, size_t n) 
{
  size_t dlen = strlen(self->c_str);
  size_t slen = strlen(s);

  if (dlen + slen + 1 > self->alloced) {
      if (!(self->c_str = realloc(self->c_str, dlen + slen + 1)))
        return *FAIL_ADDING;
      self->alloced = dlen + slen + 1;
  }

  memcpy(self->c_str + dlen, s, n);
  return *self;
}

