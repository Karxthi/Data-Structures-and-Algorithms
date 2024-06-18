#include <iostream>
using namespace std;
class bank{
    int principal;
    int years;
    float rate;
    float return_value;
    public:
        //bank();
        bank(int p, int y, double r){
            //rate input as rate (float)
            principal = p;
            years = y;
            rate = r;
            for (int i = 0; i <r;i++){
                return_value=principal+(principal*years*rate);
            }
        }
        bank(int p, int y, int r){
            //rate input in percentage
            principal = p;
            years = y;
            rate = float(r);
            //for (int i = 0; i <rate;i++){
            return_value=principal+(principal*years*rate)/100;
        //}
        }
        void print(){
            cout<<"Return value: "<<return_value<<endl;
    }
};
int main()
{
    //bank b;
    
    bank c(100,1,0.05);
    c.print();
    
    bank d(100,1,5);
    d.print();
    return 0;
}
//ompiler figures out the run time by seeing the data type and runs the relevant constructor.