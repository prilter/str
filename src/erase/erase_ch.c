#include <string.h>
#include <malloc.h>
#include "../struct.h"

str
___erase_ch___(str *self, int ch, size_ times) 
{
  if (self->is_free || times == 0)
    return *self;

  size_t i;

  for (i = 0; times && *(self->c_str + i); i++)
    if (*(self->c_str + i) == ch)
      {memcpy(self->c_str+i, self->c_str+i+1, self->alloced-- - i); times--;}

  return *self;
}
