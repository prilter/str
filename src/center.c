#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"

extern const str *FAIL_MAPPING;
extern int   empty(str *restrict self);

str
center(str *s, int ch, size_t w)
{ 
  /* INIT */
  char *b1, *b2;
  size_t len, st;

  /* LEN AND ST */
  len = strlen(s->c_str);
  st  = (size_t)((w - len) >> 1);

  /* CHECKING PROBLEMS */
  if (w <= len)
    return *s;

  /* MAPPING */
  if (s->alloced < w * sizeof(char)) {
    s->alloced += w * sizeof(char) + 4;
    if (!(s->c_str = realloc(s->c_str, s->alloced))) {
      s->alloced -= w * sizeof(char) + 4;
      return *FAIL_MAPPING;
    }
  }

  /* MAIN */
  memset((b1 = malloc(st + 4)), ch, st);
  b2 = strdup(s->c_str);
  sprintf(s->c_str, "%s%s%s", b1, b2, b1);

  /* END */
  free(b1); free(b2);
  assert(b1 || b2);
  s->is_free = 0;
  return *s;
}
