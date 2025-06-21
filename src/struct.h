#include <stddef.h>

#define STR struct str

typedef struct str {
  union {
    char *c_str;
    char *data;
  };
  size_t alloced;
  size_t is_free;
  
  /* ASSIGN */
  STR   (*assign_ln)      (struct str *, const char *);
  STR   (*assign_ch)      (struct str *, int, size_t);
  STR   (*assign_sub)     (struct str *, const char *, size_t, size_t);

  /* STRING */
  STR   (*emstr)          (struct str *restrict);
  STR   (*newstr)         (struct str *restrict, const char *restrict);
  STR   (*strchs)         (struct str *self, int, size_t); /* LIKE string(size_t, char) FROM C++ */
  STR   (*newnstr)        (struct str *, const char *, size_t);

  /* INSERT */
  STR   (*insert)         (struct str *, const char *, size_t);
  STR   (*insert_n)       (struct str *, const char *, size_t, size_t);
  STR   (*insert_ch)      (struct str *, const char, size_t);

  /* ERASE */
  STR   (*erase_sub)      (struct str *, size_t st, size_t end);
  STR   (*erase_s)        (struct str *, const char *);
  STR   (*erase_ch)       (struct str *, int, size_t);
  STR   (*pop_back)       (struct str *restrict);

  /* APPEND */
  STR   (*append)         (struct str *, const char *);
  STR   (*append_n)       (struct str *, const char *, size_t);
  STR   (*append_chs)     (struct str *, int, size_t);

  /* REPLACE */
  STR   (*replace)        (struct str *, size_t, size_t, const char *);
  STR   (*replace_py)     (struct str *, const char *, const char *, size_t);

  /* RFIND */
  size_t (*rfind_ch)       (struct str *, int);

  /* OTHER */
  size_t (*len)           (struct str *restrict);
  STR    (*push_back)     (struct str *, int ch);
  char  *(*back)          (struct str *restrict);
  char  *(*front)         (struct str *restrict);
  int    (*empty)         (struct str *restrict);
  size_t (*size)          (struct str *restrict);
  size_t (*count_ch)      (struct str *, int);
  size_t (*count)         (struct str *, const char *);
  char   (*find_first_of) (struct str *, const char *, size_t);
  char   (*find_last_of)  (struct str *, const char *, size_t);
  STR    (*substr)        (struct str *restrict, size_t, size_t);
  size_t (*find_n)        (struct str *, const char *, size_t, size_t);
  size_t (*find)          (struct str *, const char *, size_t);
  STR    (*copy)          (struct str *restrict, size_t);

  /* FREE */
  size_t  (*free_str)     (struct str *restrict);
} str;



/* TODO
  CAPACITY
void reserve(size_t n = 0);
size_t capacity() const noexcept;
void shrink_to_fit();

  MODIFIERS
string& append(const string& str, size_t subpos, size_t sublen);
template <class InputIterator> string& append(InputIterator first, InputIterator last);
template <class InputIterator> void insert(iterator p, InputIterator first, InputIterator last);
string& replace(size_t pos, size_t len, const string& str);
string& replace(iterator i1, iterator i2, const string& str);
string& replace(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen);
string& replace(size_t pos, size_t len, const char* s);
string& replace(iterator i1, iterator i2, const char* s);
string& replace(size_t pos, size_t len, const char* s, size_t n);
string& replace(iterator i1, iterator i2, const char* s, size_t n);
string& replace(size_t pos, size_t len, size_t n, char c);
string& replace(iterator i1, iterator i2, size_t n, char c);

  STRING OPERATIONS
size_t find(const string& str, size_t pos = 0) const noexcept;
size_t find(const char* s, size_t pos = 0) const;
size_t find(const char* s, size_t pos, size_t n) const;
size_t find(char c, size_t pos = 0) const noexcept;
size_t rfind(const string& str, size_t pos = npos) const noexcept;
size_t rfind(const char* s, size_t pos = npos) const;
size_t rfind(const char* s, size_t pos, size_t n) const;
size_t find_first_of(char c, size_t pos = 0) const noexcept;
size_t find_last_of(const string& str, size_t pos = npos) const noexcept;
size_t find_last_of(const char* s, size_t pos, size_t n) const;
size_t find_last_of(char c, size_t pos = npos) const noexcept;
size_t find_first_not_of(const string& str, size_t pos = 0) const noexcept;
size_t find_first_not_of(const char* s, size_t pos = 0) const;
size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
size_t find_first_not_of(char c, size_t pos = 0) const noexcept;
size_t find_last_not_of(const string& str, size_t pos = npos) const noexcept;
size_t find_last_not_of(const char* s, size_t pos = npos) const;
size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
size_t find_last_not_of(char c, size_t pos = npos) const noexcept;
int compare(size_t pos, size_t len, const string& str) const;
int compare(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen) const;
int compare(const char* s) const;
int compare(size_t pos, size_t len, const char* s) const;
int compare(size_t pos, size_t len, const char* s, size_t n) const;

NUMERIC CONVERSIONS (C++11 AND LATER)
long long stoll(const string& str, size_t* idx = 0, int base = 10);
unsigned long long stoull(const string& str, size_t* idx = 0, int base = 10);
double stod(const string& str, size_t* idx = 0);
long double stold(const string& str, size_t* idx = 0);

# MAIN FUNCTION GOTTED
string to_string(float val);
string to_string(double val);
string to_string(long double val);
*/
