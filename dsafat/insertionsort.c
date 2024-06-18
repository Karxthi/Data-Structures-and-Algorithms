#include<stdio.h>
void insertionsort(int arr[],int n)
{
    for(int i = 0; i < n; i++){
        int key=arr[i];
        int prev =i-1;
        while(prev>=0 && arr[prev]>key){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=key;
    }
}
int main(){
int n=8;

int arr[]={ -1,3,8,3,-5,7,1};
insertionsort(arr,n);
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}

}