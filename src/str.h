#include "struct.h"

/* RETURNS */
extern const size_ DOUBLE_FREE;
extern const size_ SUCCESS_FREE;
extern const char *FAIL_ADDING;
extern const char *FAIL_MAKING; 

/* FUNCTIONS */
extern str init_str(size_ sz);
extern size_ AUTO_ALLOC;

#define to_string(num, type) (to_string_##type(num))
extern str to_string_i16(int);
extern str to_string_ui16(unsigned int);
extern str to_string_i32(long int);
extern str to_string_ui32(unsigned long int);
extern str to_string_i64(long long int);
extern str to_string_ui64(unsigned long long int);

extern void _swap(str *restrict, str *restrict);
#define swap(s1, s2) _swap(&s1, &s2)
