#include <iostream>
using namespace std;
class complex{
    int a;
    int b;
    public:
    void set(int a1, int b1){
    a=a1;
    b=b1;
    }
    void setdatasum(complex c1,complex c2,complex c3){
        a=c1.a+c2.a;
        b=c1.b+c2.b;

        cout<<a<<"+i"<<b<<endl;
}
void printdata(){
    cout<<a<<"+i"<<b<<endl;
}
};
int main(){
    complex c1,c2,c3;
    c1.set(1,2);
    c1.printdata();
    c2.set(3,4);
    c2.printdata();
    cout<<"="<<endl;
    
    c3.setdatasum(c1,c2);
} 