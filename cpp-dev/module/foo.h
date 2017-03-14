
class Foo {
    // function is implicitly inlined, OK to have in the header file
    int implicitly_inlined() {
        return 0;
    }

    int explicitly_inlined();
    int not_inlined();

public:
    void A();
    void B();
};

// explicitly inlined (note the 'inline' keyword)
inline int Foo::explicitly_inlined()  {  // OK to be in .h file
  return 0;
}
