#include <stdio.h>
#include "src/str.h"

int 
main(void)
{
  /* INIT */
  str s = init_str(); 

  /* hello world! */
  if (assign_ln(&s, "Hello world!") == FAIL_MAPPING)
    return 1;
  puts(s.c_str);

  /* FREE */
  if (free_str(&s) == SUCCESS)
    puts("Successful free memory");

  /* END */
  return 0;
}
