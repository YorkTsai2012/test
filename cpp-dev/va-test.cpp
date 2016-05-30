
#include <stdio.h>
#include <stdarg.h>

#define _INTSIZEOF(n) ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

#define va_arg(ap,t) ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )


/* calculate sum of a 0 terminated list */
void sum(const char* msg, ...);
int main(int argc, char* argv[]) {
	sum("The total is %d\n", 1, 2, 3, 4, 5, 0);
	return 0; 
}
void sum(const char* msg, ...) {
	int total = 0;
	int arg;
	va_list ap;
	va_start(ap, msg); /* ap 指向第一个可变参数*/ 
	while ((arg = va_arg(ap, int)) != 0) {
		total += arg;
	}
	printf(msg, total); 
    va_end(ap);
}
	
