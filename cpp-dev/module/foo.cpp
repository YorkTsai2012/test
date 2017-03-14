
#include "foo.h"

// not inlined, must go in the cpp file
int Foo::not_inlined() {
  return 0;
}
