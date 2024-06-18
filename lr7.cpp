#include <iostream>
using namespace std;
class test
{
    int x;
    public:
        test(){}
        test(int a)
        {
            x=a;

        }
        void show()
        {
            cout<<"x: "<<x<<endl;
        }
        test operator +(test a1)
        {
            test a2;
            a2.x=x+a1.x;

        }
};
int main()
{
    int x;
    cin>>x;
    test a(x);
    a.show();
    cin>>x;
    test aa(x);
    aa.show();
    test aaa;
    aaa=a+aa;
    aaa.show();
}