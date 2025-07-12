/* LIBS */
#include <malloc.h>
#include <stdio.h>
#include "struct.h"

/* BASE */
typedef unsigned long long int  ui64;
typedef unsigned long int       ui32;
typedef unsigned int            ui16;

typedef long long int           i64;
typedef long int                i32;
typedef int                     i16;

extern str *FAIL_ADDING;
extern str *FAIL_MAPPING;

#define MAPPING(str, len) do {\
  if (str->alloced <= (len)*sizeof(char)) {\
    if (!(str->c_str = realloc(str->c_str, (len) * sizeof(char) + 4)))\
      return *FAIL_MAPPING;\
    str->alloced = (len) * sizeof(char) + 4;\
  }\
} while(0);

/* UNSIGNED */
#define CODE_U(buf, n, type) \
{\
  type temp, len; \
\
  if (buf->is_free) \
    return *FAIL_ADDING; \
\
  len = 0, temp = n; \
  do { len++; temp /= 10; } while (temp); \
\
  /* ADD NUMS */ \
  MAPPING(buf, len); \
  buf->c_str[len] = '\0'; \
  for (;len--;) { \
    buf->c_str[len] = '0' + (n % 10); \
    n /= 10; \
  } \
  return *buf;\
}

str to_string_ui16(str *restrict buf, ui16 n) {CODE_U(buf, n, ui16);}
str to_string_ui32(str *restrict buf, ui32 n) {CODE_U(buf, n, ui32);}
str to_string_ui64(str *restrict buf, ui64 n) {CODE_U(buf, n, ui64);}

/* SIGNED */
#define q(x) #x
extern str insert_ch(str *line, const char ch, size_t x);
#define CODE_I(buf, n, type) \
{ \
  u##type un = (n < 0) ? -n:n; \
  CODE_U(buf, un, u##type); \
  if (n < 0) \
    insert_ch(buf, '-', 0); \
  puts(q(u##type));\
}

str to_string_i16(str *restrict buf, ui16 n) {CODE_I(buf, n, i16);}
str to_string_i32(str *restrict buf, ui32 n) {CODE_I(buf, n, i32);}
str to_string_i64(str *restrict buf, ui64 n) {CODE_I(buf, n, i64);}

