
#include <stdio.h>

#include <algorithm>
#include <map>


int main(int argc, char* argv[]) {

    std::map<int, int> cup;

    std::map<int, int>::const_iterator up_it = cup.upper_bound(0);
    if (up_it == cup.end()) {
        printf("cup.upper_bound(0) is cup.end()\n");
    }
    --up_it;
    if (up_it == cup.begin()) {
        printf("--up_it is cup.begin()\n");
    } else if (up_it == cup.end()) {
        printf("--up_it is cup.end()\n");
    }

    return 0;
}
