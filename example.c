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

  printf("Before resize(): %zd\n", s.capacity);
  resize(&s, 25);
  printf("After  resize(): %zd\n", s.capacity);


  /* FREE */
  if (free_str(&s))
    puts("Successful free memory");

  /* END */
  return 0;
}
