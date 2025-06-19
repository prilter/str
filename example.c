#include <stdio.h>
#include "src/str.h"

/* GET ENGLISH ALPHABET */
str get_ascii_uppercase(void);
int 
main(void)
{
  str s1 = get_ascii_uppercase();
  str s2 = s1.copy(&s1, s1.len(&s1));

  printf("Not copied alphabet:\t%s\nCopied alphabet:\t%s\n", s1.c_str, s2.c_str);

  if (s1.free_str(&s1))
    puts("Successful free(s1)");
  if (s2.free_str(&s2))
    puts("Successful free(s2)");

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
