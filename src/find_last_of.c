#include <string.h>
#include "struct.h"

char
___find_last_of___(str *self, const char *list, size_ pos)
{
  /* INIT */
  char *s;
  size_ max, c;
  char res;

  /* CHECK ARGUMENTS */
  if (!self->c_str || self->is_free || !list || pos > strlen(self->c_str))
    return '\0';

  /* STARTING VALUES */
  s   = self->c_str + pos;
  max = 0;
  
  /* FIND */
  for (;*list; list++) {
    for (c = 0; *(s + c) && *(s + c) != *list; c++);
    if (c > max) {
      res = *list;
      max = c;
    }
  }

  /* END */  
  return res;
}
