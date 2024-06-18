#include <iostream>
using namespace std;
class Base
{
    public:
    int x=3;
    
        
        virtual int edit(int a)=0;
};
class derived:public Base
{
    public:
    int y;
    
        
        int edit(int a)
        {
            x=a;
            cout<<"edited x of derived = "<<this->x<<endl;

        }
};
int main()
{
  
    Base *ptr;
    derived d;
    ptr=&d;
    
    ptr->edit(2);
}