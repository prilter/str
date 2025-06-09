#include <string.h>
#include "struct.h"

size_
___len___(str *restrict self) {
  return strlen(self->c_str);
}
