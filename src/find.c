#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "struct.h"

str
___find___(str *ln, const char *s, size_t pos, size_t count)
{
  /* INIT */
  char *needle, *res;

  /* CHECK ARGUMENTS */
  if (!ln->data || !count || !s) {
    *ln->c_str = '\0';
    return *ln;
  }

  /* GET NEEDLE */
  needle = malloc(count * sizeof(char) + 4);
  strncpy(needle, s, count);

  /* GET RESULT LINE */
  res = strstr(ln->c_str + pos, needle);
  free(needle);
  assert(res); 

  /* GET ALLOCED VALUE + MAKE A CEIL OF MEMORY FOR RESULT */
  res = strdup(res);
  ln->alloced = sizeof(char) * strlen(res) + 4;

  /* GET STRING VALUE */
  free(ln->data);
  ln->c_str = res;

  /* END */
  return *ln;
}
