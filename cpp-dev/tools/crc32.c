
#include <stdio.h>
#include <zlib.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("usage: %s %s\n", argv[0], "input");
        exit(-1);
    }

    uLong crcKey = crc32(0L, Z_NULL, 0);
    char * volumeid = argv[1];
    printf("%s %d\n", volumeid, strlen(volumeid));
    crcKey = crc32(crcKey, (Bytef*)volumeid, strlen(volumeid));
    printf("crc32 redeploy %lu %%100=%lu\n", crcKey, crcKey % 100);
}
