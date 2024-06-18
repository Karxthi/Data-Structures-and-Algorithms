#include<iostream>
using namespace std;
int main() {
    int Arr[100], n, i;
    bool isSorted = true;
    cout<<"Enter number of elements you want to insert ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter element "<<i+1<<":";
        cin>>Arr[i];
    }
    for(i=0;i<n-1;i++)
    {
        if(Arr[i]>Arr[i+1])
        {
            isSorted = false;
            break;
        }
    }
    if(isSorted)
        cout<<"\nThe array is sorted in ascending order";
    else
        cout<<"\nThe array is not sorted in ascending order";
    return 0;
}
