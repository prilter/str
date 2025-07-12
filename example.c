#include <stdio.h>
#include <malloc.h>
#include "src/str.h"

int 
main(void)
{
  /* INIT */
  str s = init_str(); 

  /* CHECK */
  to_string_i32(&s, -123456789);
  puts(s.c_str);

  to_string_ui32(&s, 10156789);
  puts(s.c_str);

  /* FREE */
  if (free_str(&s))
    puts("Successful free memory");

  /* END */
  return 0;
}
