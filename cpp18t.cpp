#include <iostream>
using namespace std;
template<typename T,typename U>
U add(T x,U y)// Function Template

{
    U sum = x + y;
    return sum;
}
int main()
{
    int a;
    float b,s;
    cin >> a ;
    cin >> b ;
    s=add(a,b);
    cout << s << endl;
}