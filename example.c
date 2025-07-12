#include <stdio.h>
#include <malloc.h>
#include "src/str.h"

int 
main(void)
{
  /* INIT */
  str s0 = init_str();
  str s1 = init_str(100);

  /* INFO */
  printf("s0: %zd alloced\ns1: %zd alloced\n", s0.alloced, s1.alloced);

  /* FREE */
  if (free_str(&s0))
    puts("Successful free memory from s0");
  if (free_str(&s1))
    puts("Successful free memory from s1");

  /* END */
  return 0;
}
