#include <iostream>
using namespace std;
int main()
{
    //pointer - address of other objects  
    int a;
    cin >> a;
    int *ptr;
    ptr=&a;
    cout<<"ptr = "<<ptr<<"*ptr = "<<*ptr<<endl;
}