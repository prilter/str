#include <stdio.h>
#include "src/str.h"

/*
 * TODO:
 * replace_py
 * Add reserve functions
*/

/* GET ENGLISH ALPHABET */
str get_ascii_uppercase(void);
int 
main(void)
{
  str s = get_ascii_uppercase();
  puts(s.c_str);
  printf("\"AB\" in alphabet counted: %zd\n", s.count(&s, "AB"));
  putc(s.find_first_of(&s, "STR", 0), stdout);
  if (s.free_str(&s))
    puts("\nSuccessful free");
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
