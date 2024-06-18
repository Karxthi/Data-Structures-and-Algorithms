#include <iostream>
using namespace std;
class test
{
    int a;
    public:
        test(){}
        test(int r){
            a=r;
        }
        test operator + (test obj)
        {
            test res;

            res.a=a+obj.a;
            return res;
        }
        void display(){
            cout<<"a = "<<a<<endl;
        }
};
int main(){
    int n,a;
    cin>>n;
    test t(n);
    t.display();
    cin>>a;

    test s(a);
    s.display();
    test c;
    c=t+s;
    c.display();
}