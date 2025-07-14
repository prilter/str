#include <malloc.h>
#include "struct.h"

int
free_str(str *restrict self)
{
  if (self->is_free)
    return DOUBLE_FREE;

  free(self->c_str);
  self->is_free = 1;
  return SUCCESS;
}
