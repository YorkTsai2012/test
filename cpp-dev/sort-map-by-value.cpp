

#include <stdio.h>
#include <stdint.h>

#include <map>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    
    std::multimap<int64_t, std::string, std::greater<int64_t> > delta;
    delta.insert(std::make_pair(20, "red"));
    delta.insert(std::make_pair(40, "green"));
    delta.insert(std::make_pair(30, "white"));
    delta.insert(std::make_pair(500, "black"));
    delta.insert(std::make_pair(101, "blue"));
    delta.insert(std::make_pair(2, "yellow"));
    delta.insert(std::make_pair(30, "same"));

    std::multimap<int64_t, std::string>::iterator it = delta.begin();
    for(; it != delta.end(); it++) {
        std::pair<std::multimap<int64_t, std::string>::iterator, std::multimap<int64_t, std::string>::iterator> ret = delta.equal_range(it->first);
        for (std::multimap<int64_t, std::string>::iterator it2 = ret.first;  it2 != ret.second; it2++) {
            printf("%d: %d -> %s\n", it->first, it2->first, it2->second.c_str());
        }
    }
    
    //不需要两层循环
    std::multimap<int64_t, std::string>::iterator iter = delta.begin();
    for(; iter != delta.end(); iter++) {
        printf("%d -> %s\n", iter->first, iter->second.c_str());
    }
    
    return 0;
}
