
#include <stdio.h>
#include <zlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    uLong crcKey = crc32(0L, Z_NULL, 0);
    char * volumeid = "redeploy";
    crcKey = crc32(crcKey, (Bytef*)volumeid, strlen(volumeid));
    printf("crc32 redeploy %lu %%100=%lu\n", crcKey, crcKey % 100);
}
