#include <iostream>
using namespace std;
class Base
{
    public:
    int x=3;
    
        
        virtual int edit(int a)
        {
            x=a;
            cout<<"edited x of base = "<<x<<endl;
        }
};
class derived:public Base
{
    public:
    int y;
    
        
        int edit(int a)
        {
            y=a;
            cout<<"edited x of derived = "<<this->x<<endl;

        }
};
int main()
{
    int p,q;
    cin >> p >> q;
    Base *ptr;
    derived d;
    ptr=&d;
    
    ptr->edit(2);
}
// Errors

//1 . If using constructor always create a default constructor

// WHAT I LEARNT
// If no Virtual Function is used - Base will be called