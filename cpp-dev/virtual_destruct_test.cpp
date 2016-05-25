

#include <stdio.h>
#include <string>

class Observer {
    public:
        virtual void Update(const std::string& value) = 0;
        //如果基类的虚构函数不是虚的，则通过基类指针删除子类对象时，子类的析构函数未被调用
        virtual ~Observer() {

        }
};

class A: public Observer {

public:
    A() {
        printf("construct in class A\n");
    }
    ~A(){
        printf("destruct int class A\n");
    }
    void Update(const std::string& value);

private:
    std::string value;
};

void A::Update(const std::string& value) {
    this->value = value;
}

int main() {
    
    Observer* observer = new A();
    delete observer;

    return 0;
}
