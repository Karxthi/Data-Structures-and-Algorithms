#include<stdio.h>
void InsertionSort(int arr[],int n){
   
    for(int i=1;i<n;i++){
        int key=arr[i];
        int prev=i-1;
        //_____________This part is used for shifting greater elements forward
        while(prev>=0 && arr[prev]>key){//________Decides ASCENDING OR DESCENDING_________
            arr[prev+1]=arr[prev];
            prev--;
            
        }
        //_____________Inserting in appropriate position
        arr[prev+1]=key;
    }
};

int main(){
int n=8;

int arr[]={ -2, -3, 4, -1, -2, 1, 5, -3 };
InsertionSort(arr,n);
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}

}