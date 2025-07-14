#include <string.h>
#include "../struct.h"

extern int erase(str *line, const char *s);
extern int insert(str *line, const char *s, size_t x);

int
replace_py(str *s, const char *old, const char *new, int count) 
{
  size_t x;
  char *b;
  
  if (s->is_free)
    return UNSAFE;
  if (!s->data || !old || !new)
    return NO_DATA;
  if (!count)
    return WRONG_DATA;

  for (;count-- && (b = strstr(s->c_str, old));) {
    x = b - s->c_str;
    erase(s, old);
    insert(s, new, x);
  }
  
  return SUCCESS;
}
