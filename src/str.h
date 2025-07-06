/*
 * TODO:
 * Add reserve functions
 * Add "buffer" functions with buffer argument
*/

#include "struct.h"

/* RETURNS */
extern const size_t DOUBLE_FREE;
extern const size_t SUCCESS_FREE;
extern const size_t SUCCESS_SWAP;
extern const str   *FAILED_LESS_MEMORY;
extern const char  *FAIL_ADDING;
extern const char  *FAIL_MAKING; 
extern const size_t VALUE_WAS_RELEASED;
extern const str   *FAIL_MAPPING;
extern const size_t NPOS;

/* INIT */
#define AUTO_ALLOC 0
str init_str(size_t sz)
{
  extern void *malloc(size_t);
  return (str) { 
    .data = (char *)malloc(sz), 
    .alloced = (sz == AUTO_ALLOC) ? 1:sz, 
    .is_free = 0,
  };
}

/* FUNCTIONS */
/* ASSIGN */
extern str   assign_ln(str *self, const char *s);
extern str   assign_ch(str *self, int, size_t);
extern str   assign_sub(str *self, const char *, size_t, size_t);

/* STRING */
extern str   emstr(str *restrict self);
extern str   newstr(str *restrict self, const char *restrict s);
extern str   newstr_n(str *self, const char *s, size_t n);

/* INSERT */
extern str insert(str *line, const char *s, size_t x);
extern str insert_n(str *line, const char *s, size_t x, size_t n);
extern str insert_ch(str *line, const char ch, size_t x);

/* ERASE */
extern str erase_sub(str *line, size_t st, size_t end);
extern str erase(str *line, const char *s);
extern str erase_n(str *line, const char *s, size_t times);
extern str erase_ch(str *line, int ch, size_t times);
extern str pop_back(str *restrict line);

/* APPEND */
extern str    append(str *self, const char *res);
extern str    append_n(str *self, const char *res, size_t n);
extern str    append_chs(str *s, int ch, size_t n);

/* REPLACE */
extern str    replace(str *self, size_t pos, size_t count, const char *add);
extern str    replace_py(str *self, const char *to_rep, const char *to_get, size_t times);

/* PYTHON */
extern str join(str *ln, const char *sep, char *s);
extern str uppercase(str *restrict s);
extern str lowercase(str *restrict s);
extern str swapcase(str *restrict s);

/* RFIND */
extern size_t rfind_ch(str *s, int ch);

/* OTHER */
extern str    push_back(str *self, int);
extern int    empty(str *restrict);
extern size_t count_ch(str *, int);
extern size_t count(str *, const char *);
extern char   find_first_of(str *self, const char *list, size_t pos);
extern char   find_last_of(str *self, const char *list, size_t pos);
extern str    substr(str *restrict self, size_t, size_t);
extern size_t find_n(str *, const char *, size_t, size_t);
extern size_t find(str *, const char *, size_t);
extern str    copy(str *restrict, size_t);

/* FREE */
extern size_t free_str(str *restrict self);

/* INLINE */
static inline size_t len(str *restrict self) {extern size_t strlen(const char *); return strlen(self->c_str);}
static inline char *front(str *restrict s)   {return &s->c_str[0];}
static inline char *back(str *restrict s)    {extern size_t strlen(const char *); return s->c_str + strlen(s->c_str) - 1;}

/* TO_STRING */
#define to_string(num, type) (to_string_##type(num))
extern str to_string_i16(int);
extern str to_string_ui16(unsigned int);
extern str to_string_i32(long int);
extern str to_string_ui32(unsigned long int);
extern str to_string_i64(long long int);
extern str to_string_ui64(unsigned long long int);

/* 2 STR */
extern size_t swap(str *, str *);
extern int    compare(char *, char *);

/* STO* */
extern long int stoi(const char *, size_t *pos, int num);
extern float    stof(const char *, size_t *pos);

/* AT */
#define at(s, idx) (*at_ln(s, idx))
static inline const char *at_ln(str *restrict s, int idx) {
  extern size_t strlen(const char *restrict);
  int sign = (idx >= 0) ? 1:-1;
  if (sign*idx > (int)strlen(s->data)) 
    idx = (sign) * (strlen(s->data) - (sign == 1));
  return (s->c_str + (sign == -1) * strlen(s->c_str) + idx);
}
