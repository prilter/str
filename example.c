#include <stdio.h>
#include "src/str.h"

int 
main(void)
{
  str s = init_str(AUTO_ALLOC);
  assign_ln(&s, "Hello");

  puts(swapcase(&s).c_str);
  puts(uppercase(&s).c_str);
  puts(lowercase(&s).c_str);

  if (free_str(&s))
    puts("Successful free");

  return 0;
}
