#include <string.h>
#include "struct.h"

int
compare(char *s1, char *s2)
{
  int l1, l2;

  if (!s1 || !s2)
    return NO_DATA;
  
  l1 = strlen(s1);
  l2 = strlen(s2);

  for (;*s1 && *s2; s1++, s2++)
    if (*s1 != *s2)
      return (int)(*s1) - (int)(*s2);

  if (l1 != l2)
    return l1 - l2;
  return SUCCESS;
}
