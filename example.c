#include <stdio.h>
#include "src/str.h"

int 
main(void)
{
  str s = init_str(AUTO_ALLOC);

  assign_ln(&s, "Hi Hi Hi Hi Hi!");
  puts(replace_py(&s, "Hi", "Hello", 3).c_str);

  if (free_str(&s))
    puts("Successful free");

  return 0;
}
