#include <stdint.h>
#include <stdio.h>

void printInt(int n) {
    uint8_t *p = (uint8_t*)&n;
    for (int i = 0; i < sizeof(int); i++) {
        printf("order:%x|value:%x\n", i, p[i]);
    }
}

int main(int argc, char *argv[]) {

    //小端 低位字节先存到低地址   大端  高位字节先存低地址 （阅读顺序）
    int a = 0x7f451234; //先存 0x34 -> 0x12 -> 0x45 -> 0x7f
    printInt(a);
    int b = 0x7f45;  // 先存 0x45 -> 0x7f -> 0x00 -> 0x00
    printInt(b);

    return 0;
}
