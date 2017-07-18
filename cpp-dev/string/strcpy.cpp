

#include<stdio.h>

//如果 n与src实际不符，m与dst不符，怎么办？
int strcpy(char *src, size_t n, char *dst, size_t m) {
    if (NULL == src || NULL == dst) {
        return 255;
    } else if ( n > m) {
        return 254;
    }

    if (src > dst) {
        printf("src > dst\n");
        while (*src != '\0') {
            *dst++ = *src++;
        } 
        *dst = '\0';
        return 0;
    } else {
        printf("src <= dst\n");
        char *head = src;
        while (*src != '\0') {
            src++;
            dst++;
        }
        *dst = '\0';
        while (src >= head) {
            *dst-- = *src--;
        }
        return 0;
    }
}

int main(int argc, char *argv[]) {

    char src[20] = "hello";
    //char dst[20];
    char *dst = &src[2];
    printf("src = %s, dst = %s\n", src, dst);
    strcpy(src, 10, dst, 20);
    printf("src = %s, dst = %s\n", src, dst);

    return 0;
}
