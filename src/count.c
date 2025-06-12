#include <string.h>
#include "struct.h"

size_ 
___count___(str *self, const char *sub)
{
  char *s = self->c_str;
  size_ res;
  size_ sublen;

  if (!s || !sub) 
    return 0;

  for (res = 0, sublen = strlen(sub); (s = strstr(s, sub)); s += sublen, res++);
  return res;
}
