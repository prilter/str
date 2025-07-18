#include <string.h>
#include "struct.h"

str 
init_str(size_t sz)
{
  extern void *malloc(size_t);
  return (str) { 
    .data = (char *)malloc(sz), 
    .alloced = sz, 
    .is_free = 0,
  };
}

str
copy(str *restrict s, size_t n)
{
  str res;

  res = init_str(n * sizeof(char) + 4);
  res.alloced = n * sizeof(char) + 4;

  memcpy(res.data, s->data, n);
  res.is_free = s->is_free;

  return res;
}
