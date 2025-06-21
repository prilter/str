/* STD LIB */
#include <malloc.h>
#include "struct.h"

#define STR struct str

/* REAL FUNCTIONS */
/* ASSIGN */
extern STR   ___assign_ln___(str *self, const char *s);
extern STR   ___assign_ch___(str *self, int, size_t);
extern STR   ___assign_sub___(str *self, const char *, size_t, size_t);

/* STRING */
extern STR   ___emstr___(str *restrict self);
extern STR   ___newstr___(str *restrict self, const char *restrict s);
extern STR   ___newnstr___(str *self, const char *s, size_t n);

/* INSERT */
extern STR ___insert___(str *line, const char *s, size_t x);
extern STR ___insert_n___(str *line, const char *s, size_t x, size_t n);
extern STR ___insert_ch___(str *line, const char ch, size_t x);

/* ERASE */
extern STR ___erase_sub___(str *line, size_t st, size_t end);
extern STR ___erase_s___(str *line, const char *s);
extern STR ___erase_ch___(str *line, int ch, size_t times);
extern STR ___pop_back___(str *restrict line);

/* APPEND */
extern STR    ___append___(str *self, const char *res);
extern STR    ___append_n___(str *self, const char *res, size_t n);
extern STR    ___append_chs___(str *s, int ch, size_t n);

/* REPLACE */
extern STR    ___replace___(str *self, size_t pos, size_t count, const char *add);
extern STR    ___replace_py___(str *self, const char *to_rep, const char *to_get, size_t times);

/* RFIND */
extern size_t ___rfind_ch___(str *s, int ch);

/* OTHER */
extern size_t ___len___(str *restrict);
extern STR    ___push_back___(str *self, int);
extern char * ___back___(str *self);
extern char * ___front___(str *restrict);
extern int    ___empty___(str *restrict);
extern size_t ___count_ch___(str *, int);
extern size_t ___count___(str *, const char *);
extern char   ___find_first_of___(str *self, const char *list, size_t pos);
extern char   ___find_last_of___(str *self, const char *list, size_t pos);
extern str    ___substr___(str *restrict self, size_t, size_t);
extern size_t ___find_n___(str *, const char *, size_t, size_t);
extern size_t ___find___(str *, const char *, size_t);
extern str    ___copy___(str *restrict, size_t);

/* FREE */
extern size_t ___free_str___(str *restrict self);

/* FUNCTION */
size_t AUTO_ALLOC = 0;
str init_str(size_t sz)
{
  return (str) { 
    .c_str = (char *)malloc(sz), 
    .alloced = (sz == AUTO_ALLOC) ? 1:sz, 
    .is_free = 0,

    /* ASSIGN */
    .assign_ln     = ___assign_ln___ ,
    .assign_ch     = ___assign_ch___ ,
    .assign_sub    = ___assign_sub___ ,

    /* STRING */
    .emstr         = ___emstr___,
    .newstr        = ___newstr___,
    .strchs        = ___assign_ch___,
    .newnstr       = ___newnstr___,

    /* INSERT */
    .insert        = ___insert___,
    .insert_n      = ___insert_n___,
    .insert_ch     = ___insert_ch___,

    /* ERASE */
    .erase_sub     = ___erase_sub___,
    .erase_s       = ___erase_s___,
    .erase_ch      = ___erase_ch___,
    .pop_back      = ___pop_back___,

    /* APPEND */
    .append        = ___append___ ,
    .append_n      = ___append_n___ ,
    .append_chs    = ___append_chs___ ,

    /* REPLACE */
    .replace       = ___replace___,
    .replace_py    = ___replace_py___,

    /* RFIND */
    .rfind_ch      = ___rfind_ch___,

    /* OTHER */
    .len           = ___len___ ,
    .push_back     = ___push_back___,
    .back          = ___back___,
    .front         = ___front___,
    .empty         = ___empty___,
    .size          = ___len___,
    .count_ch      = ___count_ch___,
    .count         = ___count___,
    .find_first_of = ___find_first_of___,
    .find_last_of  = ___find_last_of___,
    .substr        = ___substr___,
    .find_n        = ___find_n___,
    .find          = ___find___,
    .copy          = ___copy___,

    /* FREE */
    .free_str = ___free_str___
  };
}


