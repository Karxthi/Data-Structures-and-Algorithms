#include <iostream>
using namespace std;
class complex
{
    int x,y;
    public:
    complex(){
        x=0;
        y=0;
    }
    complex(int a,int b=999){
        x=a;
        y=b;
    }
    complex(int a){//parameterised constructor
        x=a;
        y=0;
    }
    void display(){
        cout<<"The complex are: "<<x<<" and "<<y<<endl;
    }
};
int main(){
    complex c1;
    c1.display();
    complex c2=complex(3,5);//****NOTEE*****
    c2.display();
    //complex c3(4);
    //c3.display();
}