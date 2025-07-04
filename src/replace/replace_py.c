#include <string.h>
#include "../struct.h"

extern str erase(str *line, const char *s);
extern str insert(str *line, const char *s, size_t x);

extern str *FAIL_ADDING;

str 
replace_py(str *self, const char *old, const char *new, int count) 
{
  size_t x;
  char *b;
  str str_b;
  
  if (self->is_free || !old || !new || !count)
    return *self;

  for (;count-- && (b = strstr(self->c_str, old));) {
    x = b - self->c_str;
    erase(self, old);
    str_b = insert(self, new, x);
    if (&str_b == FAIL_ADDING)
      return *FAIL_ADDING;
  }
  
  return *self;
}
