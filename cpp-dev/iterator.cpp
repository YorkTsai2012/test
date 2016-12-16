#include <set>
#include <string>
#include <cstdio>

int main(int argc, char* argv[]) {

    std::set<std::string> ips;
    ips.insert("aaa");
    ips.insert("bbb");
    ips.insert("ccc");
  
    //set的iterator没有实现 > 运算符重载 iterator 和 reverse_iterator比较 
   /* 
    for (std::set<std::string>::iterator iter = ips.begin(); iter != ips.end(); iter++) {
        printf("%s\n", (*iter).c_str());
        if (iter > ips.begin()) {
            printf("not first\n")
        }
        if (iter == ips.rbegin()) {
            printf("last second\n");
        }
    }
    */
    std::set<std::string>::reverse_iterator iter = ips.rbegin();
    for (; iter != ips.rend(); iter++) {
        printf("%s\n", (*iter).c_str());
    }    
      
    return 0;
}
