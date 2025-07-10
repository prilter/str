#include <stdio.h>
#include "src/str.h"

int 
main(void)
{
  str s = init_str(AUTO_ALLOC);

  assign_ln(&s, "H e l l o");
  strip(&s);
  puts(s.c_str);

  if (free_str(&s))
    puts("Successful free");

  return 0;
}
