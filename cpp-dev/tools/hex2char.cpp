
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sstream>
#include <ios>


void Hex2CharArray(char* hex_chars) {
    printf("\n");
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("usage: %s %s\n", argv[0], "hex_str");
        exit(10);
    }

    char* hex_chars = argv[1];
    Hex2CharArray(hex_chars);

    return 0;
}
