#include <stdio.h>
#include "src/str.h"

/* GET ENGLISH ALPHABET */
str get_ascii_uppercase(void);
int 
main(void)
{
  str s = init_str(AUTO_ALLOC);
  s.assign_ln(&s, "A friend in need is a friend indeed.");

  printf("%zd %zd\n", s.find_n(&s, "is", 0, 1), s.find(&s, "is", 0)); 

  if (s.free_str(&s))
    puts("Successful free");

  return 0;
}
