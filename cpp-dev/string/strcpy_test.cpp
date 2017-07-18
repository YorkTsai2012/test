#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) {
    int flag  = 0;
    char passwd[10];
    memset(passwd, 10, sizeof(passwd));
    
    strcpy(passwd, argv[1]);
    

    if (0 == strcmp("Linux", passwd)) {
        flag = 1;
    }

    if (flag) {
        printf("\n Passwd cracked\n");
    } else {
        printf("\n Invalid Passwd \n");
    }
    
    return 0;
}
