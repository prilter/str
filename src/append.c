/* APPEND CONST CHAR * TO THE END OF STR */
#include <string.h>
#include <malloc.h>
#include "struct.h"

extern str *FAIL_ADDING;

/* APPEND */
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

/* APPEND_N */
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

/* APPEND CHS */
str
___append_chs___(str *s, int ch, size_t n)
{
  char *buf;

  if (!(buf = malloc(n * sizeof(char) + 4)))
    return *FAIL_ADDING;

  memset(buf, ch, n);
  ___append___(s, buf);

  free(buf);
  return *s;
}
