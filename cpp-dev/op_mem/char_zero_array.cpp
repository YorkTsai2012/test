
/*
 Copy From http://blog.csdn.net/maopig/article/details/7243646

在结构中，data是一个数组名 该数组没有元素
该数组的真实地址紧随结构体MyData之后，而这个地址就是结构体后面数据的地址
如果给这个结构体分配的内容大于这个结构体实际大小，后面多余的部分就是这个data的内容
这种声明方法可以巧妙的实现C语言里的数组扩展

*/

#include <iostream>

#include <stdlib.h>
#include <string.h>

using namespace std;

struct MyData {
    int nLen;
    char data[0];
};

int main() {
    int nLen = 10;
    char str[10] = "123456789";

    cout << "Size of MyData: " << sizeof(MyData) << endl;

    MyData *myData = (MyData*)malloc(sizeof(MyData) + 10);
    memcpy(myData->data,  str, 10);

    cout << "myData's Data is: " << myData->data << endl;

    free(myData);

    return 0;
}
