#include <stdio.h>
#include <string.h>
#include <string>

#include <arpa/inet.h>

int main(int argc, char* argv[]) {

    std::string buffer;

    //char *str1 = "abc";

    //buffer.append((char*)str1);
    
    int num = 0x1234;
    int net_num = htonl(num);
    buffer.reserve(sizeof(int));
    printf("current buffer size = %d\n", buffer.size());
    buffer.append((char*)&net_num, sizeof(int));
    printf("current buffer size = %d\n", buffer.size());

    for (int i = 0; i < buffer.size(); i++) {
        printf("buffer:%x\n", buffer.c_str()[i]);
    }

    char id[36];
    memcpy(id, "14f51bc6-efe2-49a1-97e6-356859c216aa", 36);
    printf("id=%s\n", id);

    std::string x = "14f51bc6-efe2-49a1-97e6-356859c216aa";
    printf("x.size=%d\n", x.size());
   
    uint32_t xid = 0x12345678;
    //printf("0x %04x %04x\n", (xid>>16),(uint16_t)xid);
    printf("0x %4x %4x|0x%8x\n", (xid >>16), (xid & 0x0000FFFF), xid);

    char cookieverf[8] = {0};
    uint64_t verf;
    memcpy((void*)&verf, cookieverf, sizeof(verf));
    printf("init verf:%lu\n", verf);
    verf = 0x1234;
    memcpy(cookieverf, &verf, sizeof(cookieverf));
    printf("cookieverf array:%s\n", cookieverf);
    memcpy((void*)&verf, cookieverf, sizeof(verf));
    printf("restore verf:%lx\n", verf);
    return 0;
}
