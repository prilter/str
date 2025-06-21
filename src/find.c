#include <string.h>
#include "struct.h"

/* FIND */
extern const size_t NPOS;
size_t
___find___(str *ln, const char *s, size_t pos)
{
  size_t res;

  if (!ln->data || !s)
    return NPOS;

  res = strstr(ln->c_str + pos, s) - ln->c_str;
  if ((int)res < 0 || res > strlen(ln->c_str))
    return NPOS;
  return res;
}


/* FIND_N */
extern void free(void *);
size_t
___find_n___(str *ln, const char *s, size_t pos, size_t count)
{
  /* INIT */
  char *needle;
  size_t res;

  /* CHECK ARGUMENTS */
  if (!ln->data || !count || !s)
    return NPOS;

  /* GET RESULT */
  needle = strndup(s, count);
  res = strstr(ln->c_str + pos, needle) - ln->c_str;
  free(needle);

  if ((int)res < 0 || res > strlen(ln->c_str))
    return NPOS;
  return res;
}
