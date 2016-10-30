#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    
    std::stringstream oss;
    double storage = 0;
    storage = 10 * 1024.0 * 1024 * 1024 - 646;
    storage /= 1024.0*1024*1024;
    oss << setprecision(10) << storage;
    cout << "hello" << endl;
    cout <<  oss.str() << endl;

    return 0;
}
