
#include<stdio.h>

int main(int argc, char* argv[]) {
	int *p = NULL;
    printf("%x\n", p);
    int a = 8;
	p = &a;
    printf("%x\n", p);
    p = new int(9);
	printf("%x, %d\n", p, *p);
} 
