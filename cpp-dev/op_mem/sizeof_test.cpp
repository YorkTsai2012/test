#include <stdio.h>
#include <stdint.h>

// 8 + 4*4 + 1 + 24 = 8 + 16 + 25 = 24 +  25 = 49
// 按8字节(机器字长)对齐 = 56
struct NeedleDiskInfo {
    int64_t id;
    int32_t sanity;
    int32_t magic;
    int32_t crc;
    int32_t size;
    int8_t  flag;
    char extension[24];
} __attribute__((__packed__)) ;

int main(int argc, char* argv[]) {

    printf("%d\n", sizeof(NeedleDiskInfo));    

    return 0;
}
