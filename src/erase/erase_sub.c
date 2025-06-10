#include <string.h>
#include <malloc.h>
#include "../struct.h"

str
___erase_sub___(str *self, size_ st, size_ end) 
{
  size_t len;

  len = strlen(self->c_str);
  if (st > len)
	 return *self;

  memmove(self->c_str + st, self->c_str + end, len - (end - st) + 1);
	if (!(self->c_str = realloc(self->c_str, len)))
	 return *self;
  self->alloced = len;

	return *self;
}
