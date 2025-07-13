#include <malloc.h>
#include "struct.h"

typedef unsigned long long int  ui64;
typedef unsigned long int       ui32;
typedef unsigned int            ui16;

typedef long long int           i64;
typedef long int                i32;
typedef int                     i16;

typedef long double             f64;
typedef double                  f32;
typedef float                   f16;

extern str *FAIL_ADDING;
extern str *FAIL_MAPPING;

#define MAPPING(str, len) do {\
  if (str->alloced <= (len)*sizeof(char)) {\
    if (!(str->c_str = realloc(str->c_str, (len) * sizeof(char) + 4)))\
      return *FAIL_MAPPING;\
    str->alloced = (len) * sizeof(char) + 4;\
  }\
} while(0);

#define CODE_U_WITHOUT_RET(buf, n, type) \
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
}
#define CODE_U(buf, n, type) {\
  CODE_U_WITHOUT_RET(buf, n, type); \
  return *buf; \
}

str to_string_ui16(str *restrict buf, ui16 n) {CODE_U(buf, n, ui16);}
str to_string_ui32(str *restrict buf, ui32 n) {CODE_U(buf, n, ui32);}
str to_string_ui64(str *restrict buf, ui64 n) {CODE_U(buf, n, ui64);}

extern str insert_ch(str *line, const char ch, size_t x);
#define CODE_I(buf, n, type) \
{ \
  u##type un = (n < 0) ? -n:n; \
  CODE_U_WITHOUT_RET(buf, un, u##type); \
  if (n < 0) \
    insert_ch(buf, '-', 0); \
  return *buf;\
}

str to_string_i16(str *restrict buf, i16 n) {CODE_I(buf, n, i16);}
str to_string_i32(str *restrict buf, i32 n) {CODE_I(buf, n, i32);}
str to_string_i64(str *restrict buf, i64 n) {CODE_I(buf, n, i64);}

/* FLOAT */
extern size_t strlen(const char *);
#include <math.h>
static inline f64 pow_(f64 n, ui16 deg) {
    float res = 1.0f;
    for (;deg--;) res *= n;
    return res;
}
static float log10f_(float x) {
    // Reduce x to [1, 10)
    int count;
    for (count = 0; x >= 10.0f; count++) x /= 10.0f;
    for (;x < 1.0f; count--)             x *= 10.0f;

    // Compute ln(x) using a series expansion
    float y = (x - 1.0f) / (x + 1.0f);
    float result = y;
    for (float i = 3.0f; i <= 9.0f; i += 2.0f) 
      result += pow_(y, i) / i;
    return (2.0f * result + count * 2.3025851f) / 2.3025851f;
}
static inline f64 floorl_(f64 x) {
    f64 y = (long double)((long long)x);
    return (y > x) ? y - 1.0L : y;
} 
#define CODE_UF_WITHOUT_RET(buf, n, type) \
{ \
  ui16 dot_pos; \
  ui64 to_conv; \
\
  dot_pos = (n == 0.0f) ? 1:(int)floorl_(log10f_(fabsf(n)))+1; \
  for (;n != (type)floorl_((f64)n);) \
    n *= 10; \
\
  to_conv = (ui64)n; \
  to_string_ui64(buf, to_conv); \
  insert_ch(buf, '.', dot_pos); \
} 
#define CODE_F(buf, n, type) \
{ \
  type un = (n < 0) ? -n:n; \
  CODE_UF_WITHOUT_RET(buf, un, type); \
  if (n < 0) \
    insert_ch(buf, '-', 0); \
  return *buf;\
}

str to_string_f16(str *restrict buf, f16 n) {CODE_F(buf, n, f16);}
str to_string_f32(str *restrict buf, f32 n) {CODE_F(buf, n, f32);}
