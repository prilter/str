#include <string.h>
#include <malloc.h>

#include "struct.h"

void /* SWAP C_STR VALUES */
_swap(str *restrict s1, str *restrict s2)
{
  char *temp_c  = s1->c_str;
  size_t temp_a = s1->alloced;
  size_t free_a = s1->is_free;

  s1->c_str     = s2->c_str;
  s1->alloced   = s2->alloced;
  s1->is_free   = s2->is_free;

  s2->c_str     = temp_c;
  s2->alloced   = temp_a;
  s2->is_free   = free_a;
}
