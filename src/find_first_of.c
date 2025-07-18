#include <string.h>
#include "struct.h"

char
find_first_of(str *self, const char *list, size_t pos)
{
  /* INIT */
  char  *s;
  size_t min, c;
  char   res;

  /* CHECK ARGUMENTS */
  if (!self->c_str || self->is_free || !list || pos > strlen(self->c_str))
    return '\0';

  /* STARTING VALUES */
  s   = self->c_str + pos;
  min = self->alloced;
  
  /* FIND */
  for (;*list; list++) {
    for (c = 0; *(s + c) && *(s + c) != *list; c++);
    if (c < min) {
      res = *list;
      min = c;
    }
  }

  /* END */  
  return res;
}
