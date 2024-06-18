#include <iostream>
using namespace std;
//destructor same as constructor, free memory
class num
{
    int n;
    public:
        num(int na){
            n=na;
            cout<<"CONSTRUCTOR CALLED"<<endl;
            cout<<n<<endl;
            }
        ~num(){
            n=0;
            cout<<"DESTRUCTOR CALLED"<<endl;
            cout<<n<<endl;
        }
};
int main()
{
    num a(1);
    a.~num(); 
    
}
//when compiler realises the obj is no more required in the segment
//it calls the deconstructor