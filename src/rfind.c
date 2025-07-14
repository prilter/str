#include <string.h>
#include "struct.h"

size_t
rfind_ch(str *s, int ch)
{
  char *ln;
  size_t len;

  if (s->is_free)
    return NPOS;
  if (!s->data)
    return 0;

  len = strlen(s->c_str);

  for (;len--;) {
    ln = s->data + len;
    if (*ln == ch)
      return len;
  }

  return NPOS;
}
