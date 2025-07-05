# str
Modern library for work with new type(str). Based on c++ std string library and default python functions

# Using guide
 1) Build the library:
   ```bash
   git clone https://github.com/prilter/str
   cd str
   make lib
   ```
 2) Use library  
   2.1) Copy str.h, struct.h and str.o files  
   2.2) Add to your Makefile/CmakeLists.txt linking with str.o file  
   2.3) Add line to needle file:
   ```c
#include "str/str.h"
  ```
