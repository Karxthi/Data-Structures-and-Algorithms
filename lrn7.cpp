#include <iostream>
using namespace std;
class operator
{
    int x;
    public:
        operator(int a)
        {
            x=a;

        }
        void show()
        {
            cout<<"x: "<<x<<endl;
        }
        operator add +(operator a1)
        {
            operator a2;
            a2.a=a+a1.1;

        }
};
int main()
{
    int x;
    cin>>x;
    operator a(x);
    a.show();
    cin>>x;
    operator aa(x);
    aa.show();
    operator aaa;
    aaa=a+aa;
    aaa.show();
}