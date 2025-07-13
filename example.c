#include <stdio.h>
#include <malloc.h>
#include "src/str.h"

int 
main(void)
{
  /* INIT */
  str    s = init_str(); 
  float  a = 5.6;
  double b = -123.43;

  /* CHECK */
  to_string_f16(&s, a);
  printf("f16:\nstr lib: %s\nGlibc formatting: %f\n\n", s.c_str, a);
  to_string_f32(&s, b);
  printf("f32:\nstr lib: %s\nGlibc formatting: %.14f\n\n", s.c_str, b);

  /* FREE */
  if (free_str(&s))
    puts("Successful free memory");

  /* END */
  return 0;
}
