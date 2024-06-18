#include <iostream>
using namespace std;
class Base1
{
    public:
    Base1(int x){
    int a=x;
    }

};
class Base2
{
    public:
    Base2(int y){
    int b=10;
    }
};
class Base3:public Base1,public Base2
{
    public:
    Base3(int x,int y,int z):Base1(x),Base2(y){
        cout<<"Base 1 : "<<x<<endl;
        cout<<" Base 2 : "<<y<<endl;
        cout<<" Base 3 : "<<z<<endl;
    }
};
int main()
{
   
    Base3 b3(3,6,9);
    return 0;
}

//eeeesssyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy

//USE COMMMMAA