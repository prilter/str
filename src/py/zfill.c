#include <string.h>
#include <malloc.h>
#include "../struct.h"

extern str insert_ch(str *line, const char ch, size_t x);

str
zfill(str *s, int ch, size_t len)
{
  size_t s_len = strlen(s->c_str);

  if (s_len < len && !s->is_free)
    for (;len-- - s_len;)
      insert_ch(s, ch, 0);

  return *s;
}
