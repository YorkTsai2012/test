
#include <stdio.h>

#include <memory>

class MyKlass {

};

int main(int argc, char* argv[]) {

    std::shared_ptr<MyKlass> sp((MyKlass*)0);

    if (sp) {
        printf("valid addr|sp:%x|t:%x\n", &sp, sp.get());
    } else {
        printf("invalid addr|sp:%x|t:%x\n", &sp, sp.get());
    }

    return 0;
}
