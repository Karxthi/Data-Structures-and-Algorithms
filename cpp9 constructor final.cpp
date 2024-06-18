#include <iostream>
using namespace std;
class simple{
    int a,b;
    public:
        simple(int x,int y=9)
        {
            a=x;
            b=y;
            cout<<"The complex are: "<<a<<" and "<<b<<endl;
    }
}
int main()
{
    simple s=simple(5,6);
    simple t(3);
}