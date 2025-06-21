#include <stdio.h>
#include "src/str.h"

/* GET ENGLISH ALPHABET */
str get_ascii_uppercase(void);
int 
main(void)
{
  str s = get_ascii_uppercase();

  puts(s.append_n(&s, s.data, 5).c_str);
  if (s.free_str(&s))
    puts("Successful free");

  return 0;
}

str 
get_ascii_uppercase(void)
{
  str res = init_str(30);
  for (int i = 65; i <= 90; i++)
    res.push_back(&res,i);

  return res;
}
