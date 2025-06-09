#include <string.h>
#include "../struct.h"

extern str ___insert___(str *, const char *, size_t);

str
___insertn___(str *line, const char *s, size_t x, size_t n)
{
  char buf[n];
  memcpy(buf, s, n);

  return ___insert___(line, buf, x);
}
