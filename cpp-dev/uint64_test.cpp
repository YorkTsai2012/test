#include <stdio.h>
#include <stdint.h>

int main(int argc, char* arg[]) {

    uint64_t a = 100;//18446744073709551615; //2^64 -1
    printf("%lu\n", a);
    printf("%llu\n", a);

    //plus int64_t
    int64_t b = (int64_t)-5;
    uint64_t c = 2;
    c = c + b;
    printf("%lu\n", c);

    return 0;
}
