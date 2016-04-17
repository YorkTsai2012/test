
#include <stdio.h>

int GetFreeThreadIndex() {
    //volatile static int selector = 0;
    static int selector = 0;
    if ( selector >= 4) { 
        selector = 0;
    }   
    return selector++;
}

int main() {
   
    for (int i = 0; i < 10; i++) { 
        printf("%d\n", GetFreeThreadIndex());
    }
    return 0;
}
