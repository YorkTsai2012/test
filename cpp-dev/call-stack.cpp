

#include<stdio.h>
#include <arpa/inet.h>

int sum(int x, int y) {
	printf("&x = %p\n", &x);
	printf("&y = %p\n", &y);
	int z = x + y;
	printf("&z = %p\n", &z);
	return z;
}

void printBytes(int32_t num) {
	char *s = (char *)&num;
	for (int i = 0; i < sizeof(num); i++) {
		printf("&num[%d]=%p, num[%d]=%02x\n", i, &s[i],	i, s[i]);
	}
}

int main() {


	int a = 0x1234;
	printf("a = 0x%x\n", a);
	int *p = &a;
	char *s = (char*)p;
	printf("&a = %p\n", &a);
	printf("p = %p\n", p);
	printf("s = %p\n", s);
	for (int i = 0; i < sizeof(int); i++) {
		printf("&s[%d]=%p, s[%d]=%02x\n", i, &s[i], i, s[i]);
	}

	int z = sum(1,2);
	printf("&z = %p\n", &z);
	//返回值 堆栈地址 和 
	
	uint32_t nl = htonl((uint32_t)a);
	printf("ntol(a) = 0x%x\n",(int32_t)nl);
	printBytes(nl);

	return 0;
}
