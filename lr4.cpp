#include <iostream>
using namespace std;
class interest
{
    int p;
    float r;
    int t;
    float intrest;
    public:
        interest(int a, int b,int c)
        {
            p = a;
            r=b;
            t=c;
            intrest =(p*r*t)/100;


        }
        interest(int a , double b,int c)
        {
            p=a;
            r=b;
            t=c;
            intrest =p*r*t;
        }
        void display()
        {
            cout<<"Interest: "<<intrest<<endl;
        }
};
int main()
{
    int pr,ra,ti;
    float ra2;
    cin>>pr>>ra>>ti;
    cin>>ra2;
    interest i1(pr,ra,ti);
    i1.display();
    interest i2(pr,ra2,ti);
    i2.display();
}