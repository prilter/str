#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "../struct.h"

/*static size_ 
count_(const char *s, const char *sub)
{
  if (!s || !sub) 
    return 0;

  size_t res;
  size_t sublen;

  for (res = 0, sublen = strlen(sub); (s = strstr(s, sub)); s += sublen, res++);
  return res;
}*/

str 
replace_py(str *self, const char *old, const char *new, int count) 
{
  old++, new++, count--;
  return *self;
}
