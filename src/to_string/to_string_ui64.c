/* 
 * WARNING! FUNCTION ALLOC NEW SEGMENT OF MEMORY. USE str VARIABLE TO ESCAPE MEMORY ALLOCATION ISSUE 
*/

#include "../struct.h"

#define AUTO_ALLOC 0
static str init_str(size_t sz)
{
  extern void *malloc(size_t);
  return (str) { 
    .data = (char *)malloc(sz), 
    .alloced = (sz == AUTO_ALLOC) ? 1:sz, 
    .is_free = 0,
  };
}

static int
___pow10___(size_t deg)
{
  int res;
  for (res = 1; deg--;)
    res *= 10;
  return res;
}

str
to_string_ui64(unsigned long long int n)
{
  /* INIT */
  str    res;
  size_t len, i;
  char   digs[11] = "0123456789";

  /* IF 0 */
  if (n == 0) {
    res = init_str(4);
    *res.c_str = '0';
    return res;
  }

  /* GET LEN */
  for (len = 0; n % (int)___pow10___(len) != n;)
    len++;

  res = init_str(len + 4);
  for (i = 0; i < len; i++)
    *(res.c_str + i) = '0';

  /* GET STR */
  for (;len; n /= 10)
    *(res.c_str + len-- - 1) = digs[n % 10];
  

  /* END */
  return res;
}
