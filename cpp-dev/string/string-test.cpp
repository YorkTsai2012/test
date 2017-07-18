
#include <stdio.h>

#include<string>
#include<iostream>
#include <sstream>
#include <map>

void TestNull() {

    char a[] = "hello\0world";
    std::string b(a, sizeof(a));
    std::cout << b << std::endl;

    std::map<std::string, int> counter;
    counter[b] =  100;
    std::cout << counter[b] << std::endl;

    printf("str:%s|count:%d\n", b.c_str(), counter[b]);

}

void TestAppend() {
    std::string s = "hello";
    std::string result = "";
    int i = 5;
    std::ostringstream oss;
    oss << s << i;
    result += oss.str();
    std::cout << result << std::endl;    
}

int main(int argc, char* argv[]) {

    TestNull();

    return 0;
}
