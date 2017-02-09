
#include<stdio.h>

class Top { 
    public: int a;
}; 

class Left : public Top { 
    public: int b;
}; 

class Right : public Top { 
    public: int c;
}; 

//菱形继承 编译通过
class Bottom : public Left, public Right { 
    public: int d;
};


int main(int argc, char* argv[]) {

    Left* left = new Left();
    Top* top = left;

    Bottom* bottom = new Bottom();
    Right* right = bottom;

    //
    //top = bottom;
    /*
     *error: ambiguous conversion from derived class 'Bottom' to base class 'Top':
         class Bottom -> class Left -> class Top
             class Bottom -> class Right -> class Top
     */

    delete left;
    delete bottom;
        
    return 0;
}
