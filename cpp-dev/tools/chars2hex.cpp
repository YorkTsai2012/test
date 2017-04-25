

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <string>
#include <sstream>
#include <iomanip>

std::string Chars2Hex(char id[], int id_len) {
    std::stringstream ss;
    for(uint32_t i = 0; i < id_len; i++) {
        ss << std::setfill('0') << std::setw(2) << std::hex << (int)id[i];
    }
    printf("with-null size:%u\n", ss.str().size());
    for (int i = 0; i < ss.str().size(); i++) {
        printf("%c", ss.str()[i]);
    }
    printf("\n");
    return ss.str();
}


int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("usage: %s %s\n", argv[0], "char_array");
        exit(10);
    }

    char* input = argv[1];
    char tmp[] = "hello\0\tworld";
    input = tmp;
    std::string hexstr = Chars2Hex(tmp, sizeof(tmp)); 
    printf("%s\n", hexstr.c_str());

    return 0;
}
