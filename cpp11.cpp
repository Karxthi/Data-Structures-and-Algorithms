#include <iostream>
using namespace std;
class number{
    int a;
    public:
    number(){} // *******DEFAULT CONSTRUCTOR *******
        //  A DEFAULT CONSTRUCTOR IS REQUIRED WHENEVER THERE IS A CONSTRUCTOR
        //CALL IN THE MAIN() WITHOUT ANY ARGUMENTS
        number(int x){
            a=x;

        }
        void display(){
            cout<<"Number is "<<a<<endl;
        }
};
int main()
{
    number a,b,c;
    number n(5);
    n.display();
    
}