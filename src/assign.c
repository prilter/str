#include "struct.h"

extern void  *realloc(void *, size_t);
extern void  *memcpy(void *, const void *, unsigned long);
extern size_t strlen(const char *);
extern void  *memset(void *, int, size_t);

extern void *FAIL_MAPPING;

#define MAPPING(str, len) do {\
  if (str->alloced <= (len)*sizeof(char)) {\
    if (!(str->c_str = realloc(str->c_str, (len) * sizeof(char) + 4)))\
      return *FAIL_MAPPING;\
    str->alloced = (len) * sizeof(char) + 4;\
  }\
} while(0);

/* ASSIGN LINE */
void
assign_ln(str *self, const char *s)
{
  if (!s)
    return; 

  MAPPING(self, strlen(s));
  memcpy(self->c_str, s, self->alloced);
}

/* ASSIGN SYMBOL */
void
assign_ch(str *s, int sym, size_t len) 
{
  if (!len || s->is_free)
    return;

  MAPPING(s, len);
  memset(s->c_str, sym, len);
}

/* ASSIGN SUBSTRING */
void
assign_sub(str *ln, const char *s, size_t st, size_t end)
{
  size_t buf;

  /* WRONG ARGUMENTS */
  if (!s)
    return;

  /* IF END > ST -> REVERSE ST AND END VALUES */
  if (end < st)
    {buf = st; st  = end; end = buf;}

  MAPPING(ln, end - st);

  /* COPY */
  for (buf = st; *(s + buf) && end--; buf++)
    *(ln->c_str + buf - st) = *(s + buf);
}

