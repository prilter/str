#include <string.h>
#include "struct.h"

extern const size_t VALUE_WAS_RELEASED;
const size_t NPOS = -1;

size_t
rfind_ch(str *s, int ch)
{
  char *ln;
  size_t len;

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
