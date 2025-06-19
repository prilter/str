#include <string.h>
#include <malloc.h>
#include "../struct.h"

extern str ___erase_sub___(str *self, size_t, size_t);

str
___erase_s___(str *self, const char *s) 
{
  if (!s || self->is_free)
    return *self;

  size_t st = (size_t)(strstr(self->c_str, s) - self->c_str);
  return ___erase_sub___(self, st, st+strlen(s));
}
