
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

int main() {
    
    std::string weird;
    srand(time(NULL));
    for( int i = 0; i < 10; i++) {
        int r = random() % 100 + 100;
        printf("%d, %c\n", r, (char)r);
        weird.append(1, (char)r);
    }
    printf("\n");
    std::cout << weird << std::endl;
    return 0;
}
