#include <iostream>
using namespace std;
int x=2;
int main()
{
    int x=4;
    {
        int x=5;
        cout<<::x; //will print 2 
    }
}