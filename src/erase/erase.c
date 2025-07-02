#include <string.h>
#include <malloc.h>
#include "../struct.h"

/* ERASE STRING */
str
erase(str *self, const char *s) 
{
  if (!s || self->is_free)
    return *self;

  char *p;
  if (!(p = strstr(self->c_str, s)))
    return *self;

  memmove(p, p + strlen(s), strlen(p + strlen(s)) + 1);
	if (!(self->c_str = realloc(self->c_str, sizeof(char) * strlen(self->c_str) + 4)))
	 return *self;
  self->alloced = sizeof(char) * strlen(self->c_str) + 4;

	return *self;
}

str
erase_n(str *self, const char *s, size_t times)
{
  for (;times-- && strstr(self->c_str, s);)
    erase(self, s);
  return *self;
}

/* ERASE CHAR */
str
erase_ch(str *self, int ch, size_t times) 
{
  if (self->is_free || times == 0)
    return *self;

  size_t i;

  for (i = 0; times && *(self->c_str + i); i++)
    if (*(self->c_str + i) == ch)
      {memcpy(self->c_str+i, self->c_str+i+1, self->alloced-- - i); times--;}

  return *self;
}

/* ERASE SUBLINE*/
str
erase_sub(str *self, size_t st, size_t end) 
{
  size_t len;

  len = strlen(self->c_str);
  if (st > len)
	 return *self;

  memmove(self->c_str + st, self->c_str + end, len - (end - st) + 1);
	if (!(self->c_str = realloc(self->c_str, len)))
	 return *self;
  self->alloced = len;

	return *self;
}
