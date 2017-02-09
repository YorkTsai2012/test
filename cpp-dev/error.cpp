#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
    printf("EBADF:%s\n", strerror(EBADF));
    return 0;
}
