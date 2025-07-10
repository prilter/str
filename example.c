#include <stdio.h>
#include "src/str.h"

int 
main(void)
{
  str s = init_str(AUTO_ALLOC);

  assign_ln(&s, "Hello");
  center(&s, 11, '!');
  printf("Line: %s\nLength: %zd\nCapacity: %zd\n", s.c_str, len(&s), s.alloced);

  if (free_str(&s))
    puts("Successful free");

  return 0;
}
