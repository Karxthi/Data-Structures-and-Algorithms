#include <iostream>
using namespace std;
void isPali(int arr[], int size) {
    int start = 0;
    int ch=1;
    int end = size - 1;
    while (start < end) {
        if (arr[start]!= arr[end]) {
            ch=0;
        }
        start++;
        end--;
    }
    if(ch==1){
    cout<<"Palindrome"<<endl;}
    else{
        cout<<"Not Palindrome"<<endl;}
}
int main()
{
	int n;
	cout<<"Enter the array size"<<endl;
	cin>>n;
	int arr[n];
    int a;
	for (int i=0; i<n; i++){
    	cout<<"Enter the "<<i<<"th element: ";
    	cin>>arr[i];
	}
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
	}
	isPali(arr,n);
}
