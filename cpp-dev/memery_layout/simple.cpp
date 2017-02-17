
#include <stdint.h>
#include <stdio.h>

class A {
    int a;

public:
    virtual ~A(){}
};

class B: public A {
    virtual void myfunB(){}
};

class C: virtual public A {
    virtual void myfunC() {}
};

class D: public B, public C {
    virtual void myfunD() {}
};


int main(int argc, char* argv[]) {

    char *p;
    printf("sizeof(point) = %lu\n", sizeof(p));

    A a;
    printf("sizeof(a) = %lu\n", sizeof(a));
    B b;
    C c;
    D d;
    printf("sizeof(b) = %lu\n", sizeof(b));
    printf("sizeof(c) = %lu\n", sizeof(c));
    printf("sizeof(d) = %lu\n", sizeof(d));

    return 0;
}
