#include <iostream>

class A {
public:
    virtual void func(int val = 1) {
        std::cout << "A->" << val << std::endl;
    }

    virtual void test() {
        func();
    }
};

//函数的默认值 继承问题？ 考点出资《Effective C++》
/*
 * ref: http://blog.csdn.net/peter_teng/article/details/8442436
 * 虚函数是动态绑定的，而默认参数值是静态绑定的。
 * 这也就意味着对于一个虚函数，你可能会调用它在派生类中的定义，而默认参数值则采用基类中的值
 *
 * 为何C++在这一问题上如此倒行逆施？ 
 * 答案是：运行时效率。
 * 如果默认参数值是动态绑定的话，那么编译器必须提供一整套方案，为运行时的虚函数参数确定恰当的默认值。
 * 而这样做，比起C++当前使用的编译时决定机制而言，将会更复杂、更慢。鱼和熊掌不可兼得，
 * C++将设计的中心倾向了速度和简洁，你在享受效率的快感的同时，如果你忽略本条目的建议，你就会陷入困惑。
 */
class B: public A {
public:
    void func(int val = 0) {
        std::cout << "B->" << val << std::endl;
    }
};


int main(int argc, char* argv[]) {
    B* p = new B;
    p->test(); //派生类调用虚函数（基类）虚函数中又调用基类的虚函数
     // B->1 太他妈神奇了 如何分析？
    return 0;
}
