#include <iostream>
using namespace std;
template<class T>
class add
{ 
    T a,b;
    public:
    add( T x, T y )
    {
        a=x;
        b=y;
        //sum=a+b;
    }
    //T x,y,sum;
    T sum=a+b;
    T display()
    {
        return sum;
    }
};
int main()
{
    int a,b;
    add<int> a1(1,1);
    a1.display();
}