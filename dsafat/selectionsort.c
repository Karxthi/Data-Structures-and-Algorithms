#include<stdio.h>
void selectionsort(int arr[],int n){
    
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
int main(){
    int arr[]={ -2, -3, 4, -1, -2, 1, 5, -3 };
    int n=sizeof(arr)/sizeof(arr[0]);
selectionsort(arr,n);
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}
}