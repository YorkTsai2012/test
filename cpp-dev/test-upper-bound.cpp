/*
语义
lower_bound -> not go before key :  >= key
upper_bound -> go after key :  > key

与左闭右开区间表达一致
[, )

这样多个区间，构成一个完整的集合。

*/

//g++ test_lower_upper_bound.cc --std=c++11
// map::lower_bound/upper_bound
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow = mymap.lower_bound ('b');  // itlow points to b
  itup = mymap.upper_bound ('e');   // itup points to end

  std::cout << "lower_bound " << itlow->first
            << " => " << itlow->second << '\n';

  if (itup == mymap.end()) {
    std::cout << "the map::end" << "\n";
  }

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content
  for (auto& it: mymap) {
    std::cout << it.first << " => " << it.second << '\n';
  }
  return 0;
}
