#include <stdio.h>
#include <stdlib.h>

// 如果要返回 p 的地址 
/*
 * 1. 修改传参为 指针的指针
 * 2. 返回值是指针
 * 3. 全局变量
 */
int my_alloc(char* p) {
    //p = (char*)malloc(sizeof(int));
    //gcc 编译通过 g++ 编译不通过
    p = malloc(sizeof(int));
    return 0;
}

int main(int argc, char* argv[]) {

    char* p = NULL;
    my_alloc(p);
    // p指向的内存不变
    printf("p=%p\n", p);
    return 0;
}
