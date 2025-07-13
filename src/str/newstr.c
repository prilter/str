#include "../struct.h"
#include <malloc.h>
#include <string.h>

extern void *FAIL_MAPPING;

#define MAPPING(S, len) \
  if (S->alloced < len) {\
    if (!(S->c_str = realloc(S->c_str, len + 4)))\
      return (void)*FAIL_MAPPING;\
    S->alloced = len + 4;\
  }\

/* NEWSTR */
void
newstr(str *restrict ln, const char *restrict s) /* LIKE string(const char *) FROM C++ */
{
  if (!s)
    return; 

  MAPPING(ln, strlen(s));
  memcpy(ln->c_str, s, ln->alloced);
}

/* NEWSTR N */
void
newstr_n(str *ln, const char *s, size_t n) /* LIKE string(const char *, size_t) FROM C++ */
{
  if (!s)
    return; 

  MAPPING(ln, strlen(s));
  memcpy(ln->c_str, s, ln->alloced <= n ? ln->alloced:n);
}
