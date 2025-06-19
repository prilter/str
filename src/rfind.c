#include <string.h>
#include "struct.h"

extern const size_ VALUE_WAS_RELEASED;
const size_ NPOS = -1;

size_
___rfind_ch___(str *s, int ch)
{
  char *ln;
  size_ len;

  if (!s->data || s->is_free)
    return VALUE_WAS_RELEASED;

  len = strlen(s->c_str);

  for (;len--;) {
    ln = s->data + len;
    if (*ln == ch)
      return len;
  }

  return NPOS;
}
