#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string str;
    cin.ignore();
    getline(cin, str);
    cout << str << endl;
    int n=0;
    cout<<strlen(str)<<endl;
    for(int i = 0; i < 100; i++)
    {
        if(str[i] != 0)
        {
            n++;
        }
    }
    cout << n << endl;
}