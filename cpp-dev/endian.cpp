#include <stdio.h>

int main(int argc, char *argv[]) {

    int a = 0x1256;
    unsigned char *p = (unsigned char*)&a;
    for (int i = 0; i < sizeof(int); i++) {
        printf("order:%x|value:%x\n", i, p[i]);
    }

    return 0;
}
