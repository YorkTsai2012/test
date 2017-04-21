#include <stdio.h>


#define ARRAY_LEN(arr) \
    sizeof(arr) / sizeof(arr[0])

int main(int argc, char* argv[]) {

    char non_null_str[16] = {'h','e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd', 'j', 'u', 'm', 'p', 'b', 'b'}; 
    non_null_str[15] = 'h';
    int tail = 0x12345678;

    int len = ARRAY_LEN(non_null_str);
    printf("len:%d\n", len);
    for (int i = 0; i < ARRAY_LEN(non_null_str); i++) {
        printf("%c", non_null_str[i]);
    }
    printf("\n");
    printf("non_null_str:%s\n", non_null_str);

/*

When the length of non_null_str is less than 16, it's ok.
But when it is equal to 16, wired thing happens.

output more characters than expected
non_null_str:helloWorldjumpbh@�xV4

printf 
non-null terminated str is dangerous

x/32xb non_null_str
0x7fffffffe240: 0x68    0x65    0x6c    0x6c    0x6f    0x57    0x6f    0x72
0x7fffffffe248: 0x6c    0x64    0x6a    0x75    0x6d    0x70    0x62    0x68
0x7fffffffe250: 0x40    0xe3    0xff    0xff    0x78    0x56    0x34    0x12
0x7fffffffe258: 0x10    0x00    0x00    0x00    0x00    0x00    0x00    0x00

*/

    return 0;
}
