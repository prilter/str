#include <stdio.h>
#include "src/str.h"

int 
main(void)
{
  str s = init_str(AUTO_ALLOC);
  newstr(&s, "A friend in need is a friend indeed");
  erase_n(&s, "friend ", 2);
  puts(s.c_str);

  if (free_str(&s))
    puts("Successful free");

  return 0;
}
