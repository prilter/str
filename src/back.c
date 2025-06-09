#include "struct.h"
#include <string.h>

char
*___back___(str *restrict self) {
  return self->c_str + strlen(self->c_str) - 1;
}

