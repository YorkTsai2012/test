#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("usage: %s %s\n", argv[0], "name");
        exit(1);
    }
    char* filename = argv[1];
    int fd = open(filename, O_WRONLY|O_CREAT|O_NOCTTY|O_NONBLOCK|O_EXCL, 0666);
    if (fd < 0) {
        printf("error:%s\n", strerror(errno));
    }
    close(fd);

    return 0;
}
