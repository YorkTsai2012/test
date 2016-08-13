
#include <stdio.h>
#include <string>

class A {

};

class B: public A {

};

int main() {

    std::string a = "hello";
    std::string& b = a;
    std::string& c = b;
    
    c = "";

    printf("c = %s\n", c.c_str());
    printf("a = %s\n", a.c_str());
    printf("b = %s\n", b.c_str());

    A* p = new A();
    const A& ref_p = *p;
    A* null = NULL;
    const A& ref_null = *null;
    delete &ref_p;

    B* obj_b = new B();
    A& parent = *obj_b;

    return 0;
}
