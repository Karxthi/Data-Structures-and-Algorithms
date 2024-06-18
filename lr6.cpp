#include <iostream>
using namespace std;
class shape
{
    public:
        int x;
        shape(int a)
        {
            x=a;

        }
        void show()
        {
            cout<<"x:"<< x <<endl;
        }
};
class rectangle
{
    public:
    int y;
    rectangle(int b)
    {
        y=b;

    }
    void show()
    {
        cout<<"y:"<<y<<endl;
    }
};
class volume:public shape,public rectangle
{
    public:
        int z;
        volume(int a,int b,int c):shape(a),rectangle(b)
        {
            z=c;
        }
        void show()
        {
            cout<<"z:"<<z<<endl;
            rectangle::show();
            shape::show();
        }
        void area()
        {
            cout<<"\narea:"<<x*y<<endl;
        }
        void volme()
        {
            cout<<"\nvolume:"<<x*y*z<<endl;
        }
};
int main()
{
    int p,q,r;
    cin>>p>>q>>r;
    volume v1(p,q,r);
    v1.show();
    v1.area();
    v1.volme();

}