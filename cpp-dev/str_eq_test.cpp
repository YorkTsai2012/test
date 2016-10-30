#include <string>

#include <stdio.h>

#define GEO_MAJOR ("cn-bj")

int main() {

    std::string s = "cn-bj";
    if (s == GEO_MAJOR ) {
        printf("eq|left:%s|right:%s\n", s.c_str(), GEO_MAJOR);
    }
    return 0;
}
