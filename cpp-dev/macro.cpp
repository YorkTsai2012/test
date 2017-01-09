
// #表示：对应变量字符串化
// ##表示：把宏参数名与宏定义代码序列中的标识符连接在一起，形成一个新的标识符
#include <stdio.h>
#define trace(x, format) printf(#x " = %" #format "\n", x)
#define trace2(i) trace(x##i, d)

int main(int argc, char* argv[]) {
    int i=1;
    const char* s="three";
    float x=2.0;

    trace(i, d);                // 相当于 printf("x = %d\n", x)
    trace(x, f);                // 相当于 printf("x = %d\n", x)
    trace(s, s);                // 相当于 printf("x = %d\n", x)

    int x1=1, x2=2, x3=3;
    trace2(1);              // 相当于 trace(x1, d)
    trace2(2);              // 相当于 trace(x2, d)
    trace2(3);              // 相当于 trace(x3, d)

    return 0;
}
