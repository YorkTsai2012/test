
#include <iostream>
#include <stdio.h>
using namespace std;

class A 
{
public:
    static void staticmember(){cout<<"static"<<endl;}
    void nonstatic(){cout<<"nonstatic"<<endl;}
    virtual void virtualmember(){cout<<"virtual"<<endl;}
};

int main()
{
    A a;
    void (*ptrstatic)() = &A::staticmember;
    void (A::*ptrnonstatic)() = &A::nonstatic;
    void (A::*ptrvirtual)() = &A::virtualmember;

    ptrstatic();
    printf("%p\n", &ptrstatic);
    (a.*ptrnonstatic)();
    printf("%p\n", &(a.*ptrnonstatic));
    (a.*ptrvirtual)();
 //   printf("%p\n", a.*ptrvirtual);

    return 0;
}
