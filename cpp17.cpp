#include <iostream>
using namespace std;
class complexmul
{
    public:
    int real,imag;
    
        complexmul(){}
        complexmul(int x, int y)
        {
            real = x;
            imag = y;
        }
        void display()
        {
            cout<<real<<" + i"<<imag<<endl;
        }
        complexmul operator *( complexmul c1)//                 Inside class defintiion
        {
            complexmul c3;
            c3.real=real*c1.real;
            c3.imag=imag*c1.imag;
            return c3;
        }
};
/*complexmul operator *(complexmul c1, complexmul c2)//          Outside class declaration
{
    complexmul c3;
    c3.real = c1.real*c2.real;
    c3.imag = c1.imag*c2.imag;
    return c3;
}*/
int main()
{
    int a,b;
    cin>>a>>b;
    complexmul com1(a,b);
    com1.display();
    cin>>a>>b;
    complexmul com2(a,b);
    com2.display();
    complexmul com3;
    com3=com1*com2;
    com3.display();
}
//Fat eassyy
