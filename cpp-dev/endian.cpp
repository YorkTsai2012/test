#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void printInt(int n) {
    uint8_t *p = (uint8_t*)&n;
    for (int i = 0; i < sizeof(int); i++) {
        printf("order:%x|value:%x\n", i, p[i]);
    }
}

ssize_t writeToFile(const char* path, int n) {
    int fd = open(path, O_WRONLY|O_CREAT);
    ssize_t ret = write(fd, (const void*)&n, sizeof(int));
    if (ret < 0) {
        perror("write error");
    }
    close(fd);
    return ret;
}

//TODO  向文件流中写一个整型 

int main(int argc, char *argv[]) {

    //小端 低位字节先存到低地址   大端  高位字节先存低地址 （阅读顺序）
    int a = 0x7f454c46; //先存 0x46 -> 0x4c -> 0x45 -> 0x7f
    printInt(a);
    int b = 0x7f45;  // 先存 0x45 -> 0x7f -> 0x00 -> 0x00
    printInt(b);

    //写到文件的 存储顺序 和打印顺序一致
    writeToFile("7f454c46.save", a);
    writeToFile("7f45.save", b);

    return 0;
}
