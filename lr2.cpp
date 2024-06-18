#include <iostream>
using namespace std;
//friend complex add(complex, complex);
class complex
{
    int a,b;
    public:
        void getdata()
        {
            cout<<"Enter a & b"<<endl;
            cin>>a>>b;
        }
        void showdata()
        {
            cout<<"a is "<<a<<"b is "<<b<<endl;
        }
        friend complex add(complex a1, complex b1);
       
};
complex add(complex a1,complex b1)
{
    complex c;
    c.a = a1.a+b1.a;
    c.b = a1.b+b1.b;
    return c;
}
int main()
{
    int p;
    complex c1,c2;
    c1.getdata();
    c1.showdata();
    c2.getdata();
    c2.showdata();
    complex c3;
    c3=add(c1,c2);
    c3.showdata();
}