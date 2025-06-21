#include <stdio.h>
#include "src/str.h"

/* GET ENGLISH ALPHABET */
str get_ascii_uppercase(void);
int 
main(void)
{
  str s = init_str(AUTO_ALLOC);

  s.assign_ln(&s, "Hello world!");
  puts(s.c_str);

  s.emstr(&s);

  s.assign_ch(&s, '!', 3);
  puts(s.c_str);

  s.emstr(&s);

  s.assign_sub(&s, "Hello world!", 6, 11);
  puts(s.c_str);

  if (s.free_str(&s))
    puts("Successful free");

  return 0;
}
