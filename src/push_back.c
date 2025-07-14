/* PUSH BACK CHAR TO THE END OF STR */
#include <string.h>
#include <malloc.h>
#include "struct.h"

#define DSTLEN strlen(s->c_str)

int
push_back(str *s, int ch)
{
  size_t len;
  
  if (s->is_free)
    return UNSAFE;

  /* NOT ENOUGH MEMORY */
  len = strlen(s->c_str);
  if (len + 1 >= s->alloced) {
    if (!(s->c_str = realloc( s->c_str, len * sizeof(char) + 4 )))
      return FAIL_MAPPING;
    s->alloced = len * sizeof(char) + 4;
  }

  /* PUSH BACK */
  *(s->c_str + len) = ch;
  *(s->c_str + len + 1) = '\0';
  return SUCCESS;
}
