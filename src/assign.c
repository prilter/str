#include "struct.h"

extern void  *realloc(void *, size_t);
extern void  *memcpy(void *, const void *, unsigned long);
extern size_t strlen(const char *);
extern void  *memset(void *, int, size_t);

extern str *FAIL_ADDING;

#define MAPPING(str, len) do {\
  if (str->alloced <= (len)*sizeof(char)) {\
    if (!(str->c_str = realloc(str->c_str, (len) * sizeof(char) + 4)))\
      return *FAIL_ADDING;\
    self->alloced = (len) * sizeof(char) + 4;\
  }\
} while(0);

/* ASSIGN LINE */
str 
___assign_ln___(str *self, const char *s)
{
  if (!s)
    return *self; 

  MAPPING(self, strlen(s));

  memcpy(self->c_str, s, self->alloced);
  return *self;
}

/* ASSIGN SYMBOL */
str
___assign_ch___(str *self, int sym, size_t len) 
{
  if (!len)
    return *self;

  MAPPING(self, len);

  memset(self->c_str, sym, len);
  return *self;
}

/* ASSIGN SUBSTRING */
str
___assign_sub___(str *self, const char *s, size_t st, size_t end)
{
  size_t buf;

  /* WRONG ARGUMENTS */
  if (!s)
    return *self;

  /* IF END > ST -> REVERSE ST AND END VALUES */
  if (end < st)
    {buf = st; st  = end; end = buf;}

  MAPPING(self, end - st);

  /* COPY */
  for (buf = st; *(s + buf) && end--; buf++)
    *(self->c_str + buf - st) = *(s + buf);

  return *self;
}

