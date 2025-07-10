#include <stdio.h>
#include "src/str.h"

int 
main(void)
{
  str s = init_str(AUTO_ALLOC);

  assign_ln(&s, "Hello");
  center(&s, '0', 20);
  printf("Line:   %s\nLength: %zd\n", s.c_str, len(&s));

  if (free_str(&s))
    puts("Successful free");

  return 0;
}
