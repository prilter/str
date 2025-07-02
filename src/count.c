#include <string.h>
#include "struct.h"

size_t
count(str *self, const char *sub)
{
  char  *s;
  size_t res;
  size_t sublen;

  s = self->c_str;

  if (!s || !sub) 
    return 0;

  for (res = 0, sublen = strlen(sub); (s = strstr(s, sub)); s += sublen, res++);
  return res;
}
