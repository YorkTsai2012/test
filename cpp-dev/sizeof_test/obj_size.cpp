
#include <stdio.h>
#include <stdint.h>

class CNull {

};

class CVariable {

int m_a;
int m_b;
int m_c;

};

//vfptr ->  虚函数表 
class CVFun {

double m_a;

virtual void f() {};
virtual void g() {};

};

class Base {

int m_base;
uint64_t m_align;
uint64_t m_align1;
uint64_t m_align2; // 24 + 4 + 4字节对齐 = 32

};

//vbptr -> 虚基类表
class Derived: public Base {

int m_derived;

};

class VDerived: virtual public Base {

int m_base;
char m_char; //64位OS 也按照8字节来对齐
double m_derived;

};

class CParent {

protected:
int m_nAge;

protected:
virtual void f0() {}
virtual void g0() {}
virtual void h0() {}

};

class CParent2 {
protected:
    short m_nParent2;
    
protected:
    virtual void f1() {}
    virtual void g1() {}
    virtual void h1() {}
};

class CChildren: public CParent {

public:
    int m_nChildren;

public:
    virtual void f0() {};
    virtual void h0() {};
};

class CChildren2: public CParent, public CParent2 {

public:
    int m_nChildren;

public:
    
    void f1() {};    

    virtual void f0() {}
    virtual void g1() {}
    virtual void f2() {}

    virtual void h0() {}
    virtual void h1() {}
    virtual void h2() {}

};

//菱形继承的sizeof 
//http://blog.csdn.net/it_yuan/article/details/24651347

#define print_size(obj) \
 printf("sizeof("#obj")=%lu\n", sizeof(obj));

int main() {

    CNull null;
    print_size(null);

    CVariable var;
    print_size(var); 

    CVFun cvf;
    print_size(cvf); //64位指针 8字节

    Base base;
    print_size(base);

    Derived derived;
    print_size(derived);

    VDerived v_derived;
    print_size(v_derived); 

    CParent parent;
    print_size(parent);
    
    CChildren children;
    print_size(children);

    CChildren children2;
    print_size(children2);
    
    
    return 0;
}
