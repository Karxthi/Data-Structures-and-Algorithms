//T(n)=n
//S(n)=1
// Space complexity is 1 , no new array is needed
//SWAP

#include<stdio.h>
void reverse(int arr[],int n){
    int first=0;
    while(first<n){
        int temp=arr[first];
        arr[first]=arr[n];
        arr[n]=temp;
        first++;
        n--;
    }
}

int main(){
int arr[]={1,2,3,4,5,6,7,8};
int ni=8;
int i;
reverse(arr,ni);
printf("\ndone");
for(i=0;i<=8;i++){// Beware that this affects n also, so keep a copy of n
    printf("%d ",arr[i]);
}
}