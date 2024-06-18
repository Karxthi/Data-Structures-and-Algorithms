#include<stdio.h>
//   T(n) = O(n)
void SelectionSort(int arr[],int n){
   
    for(int i=0;i<n-1;i++){//_______N-1_______ Because by the last loop all LHS is sorted
        printf("\n i=%d ",i);
        int min=i;
        for(int j=i+1;j<n;j++){
            printf("\n\tj=%d ",j);//________N________ Because comparison is done from start to end
            if(arr[j]<arr[min]){ //________Decides ASCENDING OR DESCENDING_________
                min=j;
                
            }
        }
        int temp=arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main(){
int n=8;

int arr[]={ -2, -3, 4, -1, -2, 1, 5, -3 };
SelectionSort(arr,n);
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}

}