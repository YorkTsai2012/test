
//http://stackoverflow.com/questions/18473496/pass-a-reference-to-a-reference

#include <iostream>

using namespace std;


int main(int argc, char* argv[]) {

    int a = 0;
    int& b = a;
    int& c = b;
    
    c = 1;

    cout << c << endl;

    return 0;
}
