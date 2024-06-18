#include<stdio.h>
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int Partition(int arr[],int si,int ei)
{
    int pivot=arr[si];
    int i=si;
    int j=ei;
    
    while(i<j){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
            
        }}
    swap(&arr[j],&pivot);
    
    return j;
}
void QuickSort(int arr[],int si,int ei){
    if(si<ei){
    int pIdx=Partition(arr,si,ei);
    QuickSort(arr,si,pIdx-1);// left
    QuickSort(arr,pIdx+1,ei);// right               Because The Pivot is already in its right place
    }
}



int main(){
int n=6;
int arr[]={6,3,9,8,2,5};
QuickSort(arr,0,n-1);
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}
}