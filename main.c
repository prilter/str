#include <stdio.h>
#include "src/str.h"

/*
 * TODO:
 * replace_py
 * Add reserve functions
*/

int 
main(void)
{
  size_ pos, stoi_res;
  stoi_res = stoi("101", &pos, 2);
  printf("returned stoi: %ld\npos value: %ld\n", stoi_res, pos);
  return 0;
}

