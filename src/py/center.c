#include <string.h>
#include "../struct.h"

extern int insert_ch(str *s, const char ch, size_t x);
extern int push_back(str *s, int ch);

int
center(str *s, int ch, size_t w)
{ 
  /* INIT */
  size_t st, len;

  /* CHECKING PROBLEMS */
  len = strlen(s->c_str);
  if (w <= len || w == 0)
    return WRONG_DATA;
  if (s->is_free)
    return UNSAFE;

  /* MAIN */
  st = (size_t)((w - len) >> 1);
  for (;st--;) {
    insert_ch(s, ch, 0);
    push_back(s, ch);
  }
  if (strlen(s->c_str) < w) /* SOMETHING WRONG WITH LENGTH */
    push_back(s, ch); 

  /* END */
  return SUCCESS;
}
