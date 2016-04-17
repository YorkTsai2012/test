#include <stdio.h>
#include <iostream>
#include <inttypes.h>

using namespace std;

int main() {

    int32_t a = -1;
    cout << a << endl;
    int64_t b = (int32_t)a;
    cout << b << endl;

    return 0;
}
