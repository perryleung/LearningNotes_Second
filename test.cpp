#include <iostream>
#include <stack>
using namespace std;
typedef unsigned int uint32_t;

class A
{
};

class B
{
    char ch;
    virtual void func0() {}
};

class C
{
    char ch1;
    char ch2;
    virtual void func() {}
    virtual void func1() {}
};

class D : public A, public C
{
    int d;
    virtual void func() {}
    virtual void func1() {}
};

class E : public B, public C
{
    int e;
    virtual void func0() {}
    virtual void func1() {}
};

int main(void)
{
    cout << "A=" << sizeof(A) << endl;
    cout << "B=" << sizeof(B) << endl;
    cout << "C=" << sizeof(C) << endl;
    cout << "D=" << sizeof(D) << endl;
    cout << "E=" << sizeof(E) << endl;
    return 0;
}
