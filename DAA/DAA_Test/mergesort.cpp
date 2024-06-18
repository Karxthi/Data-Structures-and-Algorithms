#include<stdio.h>
#include<iostream>
using namespace std;

void merge(int arr[],int si,int mid,int ei){
    int temp[ei-si+1];
    int i=si;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=ei){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];//remainign element ko copy
    }
    while(j<=ei){
        temp[k++]=arr[j++];//remaining elemnet ko coy karein
    }
    int size=sizeof(temp)/sizeof(temp[0]);
    for(k=0,i=si;k<size;k++,i++){
        arr[i]=temp[k];
    }
}
void mergesort(int arr[],int si,int ei) {
    if(si<ei){
        int mid=(si+ei)/2;
        mergesort(arr,si,mid);
        mergesort(arr,mid+1,ei);
        merge(arr,si,mid,ei);
    }
}
int main(){
    int n=6;
    int arr[]={6,3,9,5,2,8};
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}