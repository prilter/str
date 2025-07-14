#include <string.h>
#include <malloc.h>
#include "../struct.h"

/* ERASE STRING */
int
erase(str *ln, const char *s) 
{
  if (!s)
    return NO_DATA;
  if (ln->is_free)
    return UNSAFE;

  char *p;
  if (!(p = strstr(ln->c_str, s)))
    return NO_DATA;

  memmove(p, p + strlen(s), strlen(p + strlen(s)) + 1);
	if (!(ln->c_str = realloc(ln->c_str, sizeof(char) * strlen(ln->c_str) + 4)))
	 return FAIL_MAPPING;
  ln->alloced = sizeof(char) * strlen(ln->c_str) + 4;

	return SUCCESS;
}

int
erase_n(str *ln, const char *s, size_t times)
{
  if (!s || times == 0)
    return NO_DATA;
  if (ln->is_free)
    return UNSAFE;

  for (;times-- && strstr(ln->c_str, s);)
    erase(ln, s);
  return SUCCESS;
}

/* ERASE CHAR */
int
erase_ch(str *ln, int ch, size_t times) 
{
  if (times == 0)
    return NO_DATA;
  if (ln->is_free)
    return UNSAFE;

  size_t i;
  for (i = 0; times && *(ln->c_str + i); i++)
    if (*(ln->c_str + i) == ch)
      {memcpy(ln->c_str+i, ln->c_str+i+1, ln->alloced-- - i); times--;}

  return SUCCESS;
}

/* ERASE SUBLINE*/
int
erase_sub(str *ln, size_t st, size_t end) 
{
  size_t len;

  len = strlen(ln->c_str);
  if (st > len || ln->is_free)
	 return UNSAFE;

  memmove(ln->c_str + st, ln->c_str + end, len - (end - st) + 1);
	if (!(ln->c_str = realloc(ln->c_str, len * sizeof(char) + 4)))
	 return FAIL_MAPPING;
  ln->alloced = len * sizeof(char) + 4;

	return SUCCESS;
}
