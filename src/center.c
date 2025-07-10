#include <malloc.h>
#include <string.h>
#include "struct.h"

extern str insert_ch(str *line, const char ch, size_t x);
extern str push_back(str *self, int ch);

str
center(str *s, int ch, size_t w)
{ 
  /* INIT */
  size_t st, len;

  /* CHECKING PROBLEMS */
  len = strlen(s->c_str);
  if (w <= len)
    return *s;

  /* MAIN */
  st = (size_t)((w - len) >> 1);
  for (;st--;) {
    insert_ch(s, ch, 0);
    push_back(s, ch);
  }
  if (strlen(s->c_str) < w) /* SOMETHING WRONG WITH LENGTH */
    push_back(s, ch); 


  /* END */
  s->is_free = 0;
  return *s;
}
