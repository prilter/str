#include <string.h>
#include "struct.h"

size_t
___len___(str *restrict self) {
  return strlen(self->c_str);
}
