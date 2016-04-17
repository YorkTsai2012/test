
#include <stdio.h>
#include <string>

int main() {

    std::string a = "hello";
    std::string& b = a;
    std::string& c = b;
    
    c = "";

    printf("c = %s\n", c.c_str());
    printf("a = %s\n", a.c_str());
    printf("b = %s\n", b.c_str());

    return 0;
}
