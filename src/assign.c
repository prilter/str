#include "struct.h"

extern void  *realloc(void *, size_t);
extern void  *memcpy(void *, const void *, unsigned long);
extern size_t strlen(const char *);
extern void  *memset(void *, int, size_t);

#define MAPPING(str, len) do {\
  if (str->alloced <= (len)*sizeof(char)) {\
    if (!(str->c_str = realloc(str->c_str, (len) * sizeof(char) + 4)))\
      return FAIL_MAPPING;\
    str->alloced = (len) * sizeof(char) + 4;\
  }\
} while(0);

/* ASSIGN LINE */
int
assign_ln(str *ln, const char *s)
{
  if (!s)
    return NO_DATA;
  if (ln->is_free)
    return UNSAFE; 

  MAPPING(ln, strlen(s));
  memcpy(ln->c_str, s, ln->alloced);

  return SUCCESS;
}

/* ASSIGN SYMBOL */
int
assign_ch(str *s, int sym, size_t len) 
{
  if (s->is_free)
    return UNSAFE;
  if (!len)
    return WRONG_DATA;

  MAPPING(s, len);
  memset(s->c_str, sym, len);

  return SUCCESS;
}

/* ASSIGN SUBSTRING */
int
assign_sub(str *ln, const char *s, size_t st, size_t end)
{
  size_t buf;

  /* WRONG ARGUMENTS */
  if (!s)
    return NO_DATA;
  if (ln->is_free)
    return UNSAFE;

  /* IF END > ST -> REVERSE ST AND END VALUES */
  if (end < st)
    {buf = st; st  = end; end = buf;}

  MAPPING(ln, end - st);

  /* COPY */
  for (buf = st; *(s + buf) && end--; buf++)
    *(ln->c_str + buf - st) = *(s + buf);

  return SUCCESS;
}

