#include <stdio.h>

#include <string>
#include <iostream>

//dangling pointer
const char* SayHi() {
    std::string data("Mustafa Hi");
    const char* cptr = data.c_str();
    return cptr;
}

int main(int argc, char* argv[]) {
    int a = 2;
    std::cout << SayHi() << std::endl;
    int b = 4;
    printf("%s\n", SayHi());
    printf("%s\n", SayHi());
    printf("%s\n", SayHi());
    printf("%s\n", SayHi());
    printf("%s\n", SayHi());
    return 0;
}
