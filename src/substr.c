#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include "struct.h"

const str *FAIL_MAPPING = NULL;

/* CANNOT MAKE NORMAL ALGORITHM(WITHOUT MALLOC, NEW POINTER...), 
 * BECAUSE GCC CANNOT COMPILE WITHOUT ALLOCATIONS ERROR. 
 * FOR NOW SUBSTR WORKS WITHOUT BUGS WORKS FINE */
str
___substr___(str *restrict s, size_t pos, size_t len)
{
  assert(pos <= strlen(s->c_str));

  char *buf;
  size_t s_len = strlen(s->c_str + pos);
  size_t new_alloced = (s_len > len) ? (sizeof(char)*len+4):s->alloced;

  if (!(buf = malloc(new_alloced)))
      return *FAIL_MAPPING;

  memcpy(buf, s->c_str + pos, len);
  free(s->c_str);

  s->c_str = buf;
  s->alloced = new_alloced;

  return *s;
}
