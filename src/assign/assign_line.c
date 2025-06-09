#include <string.h>
#include <malloc.h>
#include "../struct.h"

extern str *FAIL_ADDING;

str 
___assign_line___(str *self, const char *s)
{
  /* NOT S */
  if (!s)
    return *self; 

  /* IF NOT ENOUGH MEMORY */
  if (self->alloced <= strlen(s)) {
    if (!(self->c_str = realloc(self->c_str, strlen(s))))
      return *FAIL_ADDING;
    self->alloced = strlen(s);
  }

  /* MAKE */
  memcpy(self->c_str, s, self->alloced);
  return *self;
}

