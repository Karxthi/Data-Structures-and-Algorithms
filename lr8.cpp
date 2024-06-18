#include <iostream>
using namespace std;
class complex
{
    public:
    int real;
    int img;
    complex(){}
    complex(int x, int y)
    {
        real = x;
        img = y;
    }
    void show()
    {
        cout<<"complex "<<real<<"+i"<<img<<endl;
    }
    complex operator + (complex a2)
    {
        complex a3;
        a3.real = real + a2.real;
        a3.img = img + a2.img;
        return a3;
    }
};
int main()
{
    int a,b;
    cin>>a>>b;
    complex c1(a,b);
    c1.show();
    cin>>a>>b;
    complex c2(a,b);
    c2.show();
    complex c3;
    c3=c1+c2;
    c3.show();
    
}