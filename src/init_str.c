/* STD LIB */
#include <malloc.h>
#include "struct.h"

#define STR struct str

/* REAL FUNCTIONS */
/* ASSIGN */
extern STR   ___assign___(str *self, ...);
extern STR   ___assign_line___(str *self, const char *s);
extern STR   ___assign_char___(str *self, size_, int);
extern STR   ___assign_substr___(str *self, const char *, size_, size_);

/* STRING */
extern STR   ___emstr___(str *restrict self);
extern STR   ___newstr___(str *restrict self, const char *restrict s);
extern STR   ___newnstr___(str *self, const char *s, size_ n);

/* INSERT */
extern STR ___insert___(str *line, const char *s, size_t x);
extern STR ___insertn___(str *line, const char *s, size_t x, size_t n);
extern STR ___insert_char___(str *line, const char ch, size_t x);

/* ERASE */
extern STR ___erase_sub___(str *line, size_t st, size_t end);
extern STR ___erase_s___(str *line, const char *s);
extern STR ___erase_ch___(str *line, int ch, size_ times);

/* APPEND */
extern STR   ___append___(str *restrict self, const char *restrict res);

/* REPLACE */
extern STR   ___replace___(str *self, size_ pos, size_ count, const char *add);

/* OTHER */
extern size_ ___len___(str *restrict);
extern STR   ___push_back___(str *self, int);
extern char *___back___(str *self);
extern char *___front___(str *restrict);
extern int   ___empty___(str *restrict);
extern size_ ___count_ch___(str *, int);

// /* FREE */
extern size_ ___free_str___(str *restrict self);

/* FUNCTION */
size_ AUTO_ALLOC = 0;
str init_str(size_ sz)
{
  return (str) { 
    .c_str = (char *)malloc(sz), 
    .alloced = (sz == AUTO_ALLOC) ? 1:sz, 
    .is_free = 0,

    /* ASSIGN */
    .assign_line   = ___assign_line___ ,
    .assign_char   = ___assign_char___ ,
    .assign_substr = ___assign_substr___ ,

    /* STRING */
    .emstr         = ___emstr___,
    .newstr        = ___newstr___,
    .strchs        = ___assign_char___,
    .newnstr       = ___newnstr___,

    /* INSERT */
    .insert        = ___insert___,
    .insertn       = ___insertn___,
    .insert_char   = ___insert_char___,

    /* ERASE */
    .erase_sub     = ___erase_sub___,
    .erase_s       = ___erase_s___,
    .erase_ch      = ___erase_ch___,

    /* APPEND */
    .append        = ___append___ ,

    /* REPLACE */
    .replace       = ___replace___,

    /* OTHER */
    .len           = ___len___ ,
    .push_back     = ___push_back___,
    .back          = ___back___,
    .front         = ___front___,
    .empty         = ___empty___,
    .size          = ___len___,
    .count_ch      = ___count_ch___,

    /* FREE */
    .free_str = ___free_str___
  };
}


