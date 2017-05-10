#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <sstream>
#include <iomanip>

int main(int argc, char* argv[]) {

    char text[20] = {0x01, 0x01, 0x00, 0x01,
        0x53, 0x07, 0x2C, 0xB9,
        0x22, 0xDA, 0x43, 0x8A,
        0xB3, 0x35, 0x2C, 0xBF,
        0x7F, 0xDD, 0x2F, 0xFF};

    //char *octet2hex(char *to, const char *str, unsigned int len);
    char buffer[40] = {0};
//    octet2hex(buffer, text, 20);

    std::stringstream ss;
    for(int i = 0; i < 20; i++) {
        ss << std::setfill('0') << std::setw(2) << std::hex << (unsigned)(text[i] & 0xFF);
    }
    
    printf("hexstr:%s\n", ss.str().c_str());

    return 0;
}
