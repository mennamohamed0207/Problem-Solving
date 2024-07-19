#include <iostream>
using namespace std;  


int main()
{
    cout<<"\n"<<endl;
    int x, y,z;
    x=5;
    int pre =++x;
    int post=x--;
    y=( ++x) * x--;
    z= ++y + --y;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"z = "<<z<<endl;
    cout<<"\n"<<endl;
    return 0;
}
