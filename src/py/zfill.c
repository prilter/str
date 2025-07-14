#include <string.h>
#include <malloc.h>
#include "../struct.h"

extern int insert_ch(str *s, const char ch, size_t x);

int
zfill(str *s, int ch, size_t len)
{
  size_t s_len = strlen(s->c_str);

  if (!len)
    return WRONG_DATA;
  if (s->is_free)
    return UNSAFE;

  if (s_len < len && !s->is_free)
    for (;len-- - s_len;)
      insert_ch(s, ch, 0);

  return SUCCESS;
}
