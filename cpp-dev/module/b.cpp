
#include "foo.h"
#include <stdio.h>

// not inlined, must go in the cpp file
void Foo::B() {
    printf("b\n");
}
