#include "../struct.h"
#include <malloc.h>
#include <string.h>

str 
___replace___(str *self,  size_ pos, size_ count, char *add)
{
  if (pos > strlen(self->c_str))
    return *self;

  char *ln = self->c_str + pos;
  for (;*ln && *add && count--;)
    *(ln++) = *(add++);

  for (;*ln && count--;) {
    memcpy(ln, ln+1, strlen(ln)-1);
    *(ln+strlen(ln)-1) = '\0';
    self->alloced -= sizeof(char);
  }
  
  self->c_str = realloc(self->c_str, self->alloced);
  return *self;
}
