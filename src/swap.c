#include <string.h>
#include <malloc.h>

#include "struct.h"

int /* SWAP C_STR VALUES */
swap(str *restrict s1, str *restrict s2)
{
  if (s1->is_free || s2->is_free)
    return UNSAFE;

  char *temp_c  = s1->c_str;
  size_t temp_a = s1->alloced;

  s1->c_str     = s2->c_str;
  s1->alloced   = s2->alloced;

  s2->c_str     = temp_c;
  s2->alloced   = temp_a;

  return SUCCESS;
}
