#include <string.h>
#include <malloc.h>

#include "struct.h"

const size_t VALUE_WAS_RELEASED = 0;
const size_t SUCCESS_SWAP = 1;

size_t /* SWAP C_STR VALUES */
_swap(str *s1, str *s2)
{
  if (s1->is_free || s2->is_free)
    return VALUE_WAS_RELEASED;

  char *temp_c  = s1->c_str;
  size_t temp_a = s1->alloced;

  s1->c_str     = s2->c_str;
  s1->alloced   = s2->alloced;

  s2->c_str     = temp_c;
  s2->alloced   = temp_a;

  return SUCCESS_SWAP;
}
