#include <stdio.h>
#include "src/str.h"

/*
 * Add reserve functions
*/

/* GET ENGLISH ALPHABET */
str get_ascii_uppercase(void);
int 
main(void)
{
/*  str s = get_ascii_uppercase();
  puts(s.c_str);
  if (s.free_str(&s))
    puts("Successful free");
  return 0;*/

  str s1, s2;

  s1 = init_str(AUTO_ALLOC);
  s2 = init_str(AUTO_ALLOC);

  s1.assign_line(&s1, "Hello");
  s2.assign_line(&s2, "world");

  printf("%d\n", compare(s1, s2.push_back(&s2, '!')));
}

str 
get_ascii_uppercase(void)
{
  str res = init_str(30);
  for (int i = 65; i <= 90; i++)
    res.push_back(&res,i);

  return res;
}
