#include <stdio.h>
#include "src/str.h"

int 
main(void)
{
  str s = init_str(AUTO_ALLOC);
  str s1;

  assign_ln(&s, "world!");
  buffer(s1, s, insert, "Hello ", 0);
  puts(s1.c_str); /* INSERTED */
  puts(s.c_str);  /* SOURCE */

  if (free_str(&s))
    puts("Successful free source");
  if (free_str(&s1))
    puts("Successful free buffer");

  return 0;
}
