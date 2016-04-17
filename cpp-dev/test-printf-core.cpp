
#include<stdio.h>

int main(int argc, char *argv[]) {

    for (int i = 0; i < argc; i++) {
        printf("arg[%d]=%s\n", i, argv[i]);
    }

    printf("Getv2|Session:cb68428d-6d7c-424b-8375-0b39b820e8cb|Host:down.haodown.org|Path:/cx/1511165/setup_147.exe|Query:?|UserAgent:Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1; Trident/4.0; @ylx%nG:MIJ&sX\n");
    printf("%s", "Getv2|Session:cb68428d-6d7c-424b-8375-0b39b820e8cb|Host:down.haodown.org|Path:/cx/1511165/setup_147.exe|Query:?|UserAgent:Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1; Trident/4.0; @ylx%nG:MIJ&sX\n");

    return 0;
}
