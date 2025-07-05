#include "../struct.h"
#include <malloc.h>
#include <string.h>

extern str *FAIL_MAPPING;

#define MAPPING(S, len) \
  if (S->alloced < len) {\
    if (!(S->c_str = realloc(S->c_str, len + 4)))\
      return *FAIL_MAPPING;\
    S->alloced = len + 4;\
  }\

/* NEWSTR */
str
newstr(str *restrict self, const char *restrict s) /* LIKE string(const char *) FROM C++ */
{
  if (!s)
    return *self; 

  MAPPING(self, strlen(s));
  memcpy(self->c_str, s, self->alloced);
  return *self;
}

/* NEWSTR N */
str
newstr_n(str *self, const char *s, size_t n) /* LIKE string(const char *, size_t) FROM C++ */
{
  if (!s)
    return *self; 

  MAPPING(self, strlen(s));
  memcpy(self->c_str, s, self->alloced <= n ? self->alloced:n);
  return *self;
}
