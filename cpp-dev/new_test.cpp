
#include <iostream>
using namespace std;

class A {
    int m_value;
    static new_handler    current_handler;

  public:
    A(int value) :m_value(value * value) {}
    void Func() {
        printf("m_value=%d\n", m_value);
    }

    static new_handler set_new_handler(new_handler p) {
        //保存传入的Handler，返回以前的Handler
        new_handler old_handler = current_handler;
        current_handler = p;
        return old_handler;
    }


    void* operator new(size_t size) {
        printf("operator new called\n");
        new_handler globe_handler = std::set_new_handler(current_handler); // 调用全局函数set_new_handler设置handler

        void *memory = NULL;
        try {
            memory = ::operator new(size);
        } catch(std::bad_alloc) {
            std::set_new_handler(globe_handler);
            throw;
        }
        std::set_new_handler(globe_handler);

        return memory;
    }

    /*
        void* operator new(size_t size){
            printf("operator new called\n");
            return ::operator new(size);
        }
    */
};

void handlerFunc() {
    cout << "Bad Memory." << endl;
}
new_handler A::current_handler = NULL;

void* operator new(size_t size) throw(std::bad_alloc) {
    printf("global new\n");
    return malloc(size);
}

int main() {
    A::set_new_handler(handlerFunc);
    A *aPtr = new A(1);
    ::new(aPtr) A(2);
    aPtr->Func();
    delete aPtr;
    return 0;
}
