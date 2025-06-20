
/*
 * TODO:
 * replace_py
 * Add reserve functions
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

/* FUNCTIONS */
extern str init_str(size_t sz);
extern size_t AUTO_ALLOC;

#define to_string(num, type) (to_string_##type(num))
extern str to_string_i16(int);
extern str to_string_ui16(unsigned int);
extern str to_string_i32(long int);
extern str to_string_ui32(unsigned long int);
extern str to_string_i64(long long int);
extern str to_string_ui64(unsigned long long int);

extern size_t _swap(str *, str *);
#define swap(s1, s2) (_swap(&s1, &s2))

extern int _compare(char *, char *);
#define compare(s1, s2) ( _compare(s1.c_str, s2.c_str) )

extern long int stoi(const char *, size_t *pos, int num);

#define at(s, idx) (*((s)->c_str + idx))
