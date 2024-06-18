#include <iostream>
using namespace std;
class Base 
{
    public:
    int a;
    Base(int x)
    {
        a=x;
    }
    void display()
    {
        cout << "a: " << a << endl;
    }
};
class Base2
{
    public:
    int b;
    Base2(int y)
    {
        b=y;
    }
    void display()
    {
        cout << "b: " << b << endl;
    }
};
class Combined:public Base,public Base2
{
    public:
        int z;
        Combined(int a,int b,int c):Base(x),Base2(y)
        {
            z=c;

        }
        void display()
        {
            Base::display();
            Base2::display();
            cout << "z: " << z << endl;
        }
};
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    Combined c1(a,b,c);
    c1.display();
}
