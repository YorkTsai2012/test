
#include<string>
#include<iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {

    std::string s = "hello";
    std::string result = "";
    int i = 5;
    std::ostringstream oss;
    oss << s << i;
    result += oss.str();
    cout << result << endl;    

    return 0;
}
