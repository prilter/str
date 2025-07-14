/* APPEND CONST CHAR * TO THE END OF STR */
#include <string.h>
#include <malloc.h>
#include "struct.h"

/* APPEND */
int
append(str *ln, const char *s) 
{
  size_t dlen = strlen(ln->c_str);
  size_t slen = strlen(s);

  if (ln->is_free)
    return UNSAFE;
  if (!s)
    return NO_DATA;

  if (dlen + slen + 1 > ln->alloced) {
      if (!(ln->c_str = realloc(ln->c_str, dlen + slen + 1)))
        return FAIL_MAPPING;
      ln->alloced = dlen + slen + 1;
  }

  memcpy(ln->c_str + dlen, s, slen + 1);
  return SUCCESS;
}

/* APPEND_N */
int
append_n(str *self, const char *s, size_t n) 
{
  size_t dlen = strlen(self->c_str);
  size_t slen = strlen(s);

  if (self->is_free)
    return UNSAFE;
  if (!s)
    return NO_DATA;
  if (!n)
    return WRONG_DATA;

  if (dlen + slen + 1 > self->alloced) {
      if (!(self->c_str = realloc(self->c_str, dlen + slen + 1)))
        return FAIL_MAPPING;
      self->alloced = dlen + slen + 1;
  }

  memcpy(self->c_str + dlen, s, n);
  return SUCCESS;
}

/* APPEND CHS */
int
append_chs(str *s, int ch, size_t n)
{
  char *buf;

  if (s->is_free)
    return UNSAFE;
  if (!(buf = malloc(n * sizeof(char) + 4)))
    return FAIL_MAPPING;

  memset(buf, ch, n);
  append(s, buf);

  free(buf);
  return SUCCESS;
}
