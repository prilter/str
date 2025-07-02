#include <string.h>
#include <malloc.h>

#include "../struct.h"

const str *FAILED_LESS_MEMORY = NULL;

str
pop_back(str *restrict self)
{
  *(self->c_str + strlen(self->c_str) - 1) = '\0';
  if (!(self->c_str = realloc(self->c_str, self->alloced - sizeof(char))))
    return *FAILED_LESS_MEMORY;
  self->alloced -= sizeof(char);
  return *self;
}
