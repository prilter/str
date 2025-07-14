#include "../struct.h"
#include <malloc.h>
#include <string.h>

#define MAPPING(S, len) \
  if (S->alloced < len) {\
    if (!(S->c_str = realloc(S->c_str, len + 4)))\
      return FAIL_MAPPING;\
    S->alloced = len + 4;\
  }\

/* NEWSTR */
int
newstr(str *restrict ln, const char *restrict s) /* LIKE string(const char *) FROM C++ */
{
  if (!s)
    return NO_DATA; 
  if (ln->is_free)
    return UNSAFE;

  MAPPING(ln, strlen(s));
  memcpy(ln->c_str, s, ln->alloced);

  return SUCCESS;
}

/* NEWSTR N */
int
newstr_n(str *ln, const char *s, size_t n) /* LIKE string(const char *, size_t) FROM C++ */
{
  if (!s || !n)
    return NO_DATA; 
  if (ln->is_free)
    return UNSAFE;

  MAPPING(ln, strlen(s));
  memcpy(ln->c_str, s, ln->alloced <= n ? ln->alloced:n);

  return SUCCESS;
}
