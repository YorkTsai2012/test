/*
 *   菱形继承内存储布局
 *   http://m.blog.csdn.net/article/details?id=49102373

- **虚基类的虚表指针是不会被派生类所共享的，
    若派生类中含有新的虚函数（改写的不算），
    将会自己产生一个指向自己虚表的指针。**

- 如果普通虚继承，虚表指针也被派生类继承；
如果是虚继承，派生类有新的虚函数（不包括改写的），
将会有自己的虚表指针。

实际测试，只要是虚继承，基类有虚函数，派生类就有自己的虚表指针

 */

#include <stdio.h>
#include <iostream>
#include <stdint.h>

using namespace std;


/*
class  A;
class  B : virtual public A;
class  C : virtual public A;
class  D : public B , public C
*/

//单一的虚拟继承
//引例一：
/*
    //{_a = -6672}
class Base {
private:
    int _a;
};

    //{<Base> = {_a = 4195712}, _vptr.Derived = 0x400838}
class Derived: virtual public Base {

};
*/

//引例二：
//{_vptr.Base = 0x400cb0, _a = 4196400}
/*
class Base {
public:
    virtual void funl() {
        cout << "Base::fun1()" << endl;
    }
private:
    int _a;
};

//{<Base> = {_vptr.Base = 0x400c80, _a = -148141152}, _vptr.Derived = 0x400c58}
class Derived: virtual public Base {
public:
    virtual void funl() {
        cout << "Derived::fun1()" << endl;
    }
    virtual void Derivedfun2() {
        cout << "Derived::Derivedfun2()" << endl;
    }
};
*/

class Base {
public:
    virtual void func1() {
        cout << "Base::func1()" << endl;
    }
    virtual void Basefunc2() {
        cout << "Base::func2()" << endl;
    }
private:
    int64_t b;
};

//Mac OS X中的GDB {<Base> = {_vptr$Base = 0x100002190 <vtable for Base1+16>, b = 140734799804768}, b1 = 0}
//可以
//class Base1 :public virtual Base {
class Base1: public Base {
public:
        virtual void func1()
       {
              cout << "Base1::func1()" << endl;
       }
        virtual void Base1func2()
       {
              cout << "Base1::func2()" << endl;
       }
private:
       int64_t b1;
};

//{<Base> = {_vptr$Base = 0x100002200 <vtable for Base2+56>, b = 4294967296}, _vptr$Base2 = 0x1000021e0 <vtable for Base2+24>, b2 = 1}
class Base2: public virtual Base {
//class Base2: public Base {
public:

/*
        virtual void func1()
       {
              cout << "Base2::func1()" << endl;
       }
*/

/*
        virtual void Base2func2()
       {
              cout << "Base2::func2()" << endl;
       }
*/
private:
        int64_t b2;
};

typedef void (*FUNC)();
void PrintVTable(int *VTable)
{
       cout << "虚表地址：" << VTable << endl;
        for (int i = 0; VTable[i] != 0; i++)
       {
              printf( "第VTable[%d]是：OX%x->" , i, VTable[i]);
               FUNC p = (FUNC )VTable[i];
              p();
       }
       cout << endl;
}

class Derived :  public Base1, public Base2
{
public:
        virtual void func1()
       {
              cout << "Derived::func1()" << endl;
       }
        virtual void Derivedfunc2()
       {
              cout << "Derived::func2()" << endl;
       }
        virtual void Derivedfunc3()
       {
              cout << "Derived::func3()" << endl;
       }
private:
        int64_t d1;
};

int main(int argc, char* argv[]) {

    char c = 'c';
    char *p = &c;
    printf("sizeof(point) = %lu\n", sizeof(p));

    Base b;
    Base1 b1;
    Base2 b2;
    Derived d;
    printf("sizeof(b) = %lu\n", sizeof(b));
    printf("sizeof(b1) = %lu\n", sizeof(b1));
    printf("sizeof(b2) = %lu\n", sizeof(b2));
    printf("sizeof(d) = %lu\n", sizeof(d));

    //Base的对象b:
    int *VTable = (int *)(*(int *)&b);
    PrintVTable(VTable);    //Base的虚函数表
}

/*
(gdb) p b
$1 = {_vptr.Base = 0x401330, b = 4196480}
(gdb) print sizeof(b)
$2 = 16
(gdb) p b1
$3 = {<Base> = {_vptr.Base = 0x4012e8, b = 4198000}, _vptr.Base1 = 0x4012b8, b1 = 4198069}
(gdb) p sizeof(b1)
$4 = 32
(gdb) p b2
$5 = {<Base> = {_vptr.Base = 0x401268, b = 4196291}, _vptr.Base2 = 0x401238, b2 = 4198000}
(gdb) p sizeof(b2)
$6 = 32
(gdb) p d
$7 = {<Base1> = {<error reading variable>
(gdb) next
135     printf("sizeof(b) = %lu\n", sizeof(b));
(gdb) p d
$8 = {<Base1> = {<Base> = {_vptr.Base = 0x401100, b = 4198182}, _vptr.Base1 = 0x401098, b1 = 65535}, <Base2> = {_vptr.Base2 = 0x4010d0, b2 = 4197156}, d1 = 0}
(gdb) p sizeof(d)
$9 = 48
*/
