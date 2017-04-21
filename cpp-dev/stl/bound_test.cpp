
#include <stdio.h>

#include <vector>


int main(int argc, char* argv[]) {

    std::vector<int> cup;
    cup.push_back(1);
    cup.push_back(2);
    cup.push_back(3);
    cup.push_back(4);
    cup.push_back(5);

    std::vector<int>::const_iterator it = cup.begin();
    int offset = 6;
    int count = 3;
    //容器的迭代器 如果越界 iterator会指向一个空对象
    for (int loop = 0; loop < offset; loop++,it++) {}
    for (int loop = 0; loop < count && it != cup.end(); loop++, it++) {
        printf("cup element:%d\n", *it);
    }

    return 0;
}
