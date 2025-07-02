/* PUSH BACK CHAR TO THE END OF STR */
#include <string.h>
#include <malloc.h>
#include "struct.h"

#define DSTLEN strlen(self->c_str)

str *FAIL_ADDING = NULL;

str
push_back(str *self, int ch)
{
  size_t len;
  len = strlen(self->c_str);

  /* NOT ENOUGH MEMORY */
  if (len + 1 >= self->alloced) {
    if (!(self->c_str = realloc( self->c_str, len + 4 )))
      return *FAIL_ADDING;
    self->alloced >>= 1;
  }

  /* PUSH BACK */
  *(self->c_str + len) = ch;
  *(self->c_str + len + 1) = '\0';
  return *self;
}
