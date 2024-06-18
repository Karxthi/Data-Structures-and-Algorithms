#include<stdio.h>
#include<cmath>
#include<climits>
#include<iostream>
using namespace std;
int rodcut(int arr[],int n,int length){
    int B[n+1];
    B[0]=0;
    for(int i=1;i<n+1;i++){
        int q=INT_MIN;
        for(int k=1;k<=i;k++){
            q=max(q,arr[k-1]+B[i-k]);
        }
        B[i]=q;
        cout<<" "<<B[i];

    }
    return B[length];
}
int main(){
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int length=5;
    cout <<"Maximum Obtainable Value is "<<rodcut(arr, size,length)<<endl;
    getchar();
    return 0;
}