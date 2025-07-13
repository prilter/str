#include <stdio.h>
#include "src/str.h"

int 
main(void)
{
  /* INIT */
  str s = init_str(); 

  /* CHECK */
  insert(&s, "Hello", 0);
  append(&s, "world!");
  insert_ch(&s, ' ', 5);

  printf("Before shrink_to_fit(): %zd\n", s.capacity);
  shrink_to_fit(&s);
  printf("After  shrink_to_fit(): %zd\n", s.capacity);

  /* FREE */
  if (free_str(&s))
    puts("Successful free memory");

  /* END */
  return 0;
}
