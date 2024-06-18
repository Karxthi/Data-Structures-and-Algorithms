#include<iostream>
using namespace std;
int checkcount(int arr[],int num,int si,int ei){
    int count=0;
    int k=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<k;i++){
        if(arr[i]==count){
            count++;
        }
    }
    return count;
}
int Majority(int arr[],int si,int ei){
    if(si<ei){
        int mid=(si+ei)/2;
        int left=Majority(arr,si,mid);
        int right=Majority(arr,mid+1,ei);

    }
    else{return 0;}

    if(left==right){return left;}
    else{
        int n1=checkcount(arr,left,si,mid);
        int n2=checkcount(arr,right,mid+1,ei);
        int final = n1>n2?n1:n2;
        return final;
    }
}
int main(){
    int n=6;
    int arr[]={1,2,3,3,3,1};
    int maj=Majority(arr,0,6);
}