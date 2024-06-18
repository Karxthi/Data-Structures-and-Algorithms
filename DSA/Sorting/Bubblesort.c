#include<stdio.h>
//T(n) = O(n^2);

void swap(int x,int y){
    //printf("swapping");
    int temp=0;
    temp = x;
    x=y;
    y=temp;
}
void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){          //N-1
        for(int j=0;j<n-1-i;j++){    //N-1-i
            if(arr[j+1]<arr[j]){ //________Decides ASCENDING OR DESCENDING_________
                
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\nSorting completed");
}

int main(){
int n=5;

int arr[]={5,4,-1,3,2};
BubbleSort(arr, n);
for(int i=0;i<n;i++){
    printf("%d  ",arr[i]);
}

}