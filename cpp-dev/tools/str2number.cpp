
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

uint64_t ipport2key(unsigned ip, unsigned short port) {
    uint64_t ret = 0;
    ret = ip;
    ret <<= 32;
    ret += port;
    return ret;
}

int main(int argc, char* argv[]) {

    char* nptr = "*";

    int ret = atoi(nptr);
    printf("ret:%d\n", ret);

    uint64_t key = ipport2key(0, 2000);
    printf("key:%lu\n", key);

    return 0;
}
