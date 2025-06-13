#include "struct.h"

/* RETURNS */
extern const size_ DOUBLE_FREE;
extern const size_ SUCCESS_FREE;
extern const size_ SUCCESS_SWAP;
extern const str  *FAILED_LESS_MEMORY;
extern const char *FAIL_ADDING;
extern const char *FAIL_MAKING; 
extern const size_ VALUE_WAS_RELEASED;
extern const size_ SUCCESS;

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

extern size_ _swap(str *, str *);
#define swap(s1, s2) (_swap(&s1, &s2))

extern int _compare(char *, char *);
#define compare(s1, s2) ( _compare(s1.c_str, s2.c_str) )

extern long int stoi(const char *, size_ *pos, int num);
