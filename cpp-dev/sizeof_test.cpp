
#include <stdio.h>

struct empty {

    virtual void func() {

    }

};

int main(int argc, char *argv[]) {

    printf("%lu\n", sizeof(empty));

    return 0;
}
