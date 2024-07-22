#include <iostream>
using namespace std;
class A
{
public:
    void fun()
    {
        std::cout << "In A" << std::endl;
    }
    void func(int a)
    {
        std::cout << "In A (int a)" << std::endl;
    }
};
class B : public A
{
public:
    void fun()
    {
        std::cout << "In B" << std::endl;
    }
};
int main()
{
   std:: cout<<"\n";
    A* a_ptr = new B();
    A* b_ptr = new B();
    A a;
    B b;
    a.fun();
    b.fun();
    a_ptr->fun();
    // b_ptr->fun();
    return 0;
}