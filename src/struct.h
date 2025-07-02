#include <stddef.h>

typedef struct str {
  union {
    char *c_str;
    char *data;
  };
  union {
    size_t alloced;
    size_t capacity;
  };
  size_t is_free;
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
