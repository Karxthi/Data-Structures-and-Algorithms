#include<stdio.h>
void countingsort(int arr[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){max=arr[i];}
    }
    printf("%d\n",max);
    int count[max+1];
    int b[max+1];
    for(int i=0;i<max+1;i++){
        count[i]=0;// ** MISTAKE , INITIALIZE COUNT ARR TO 0    
    }
    for(int i=0;i<n;i++){
        ++count[arr[i]];
    }
    for(int i=1;i<max+1;i++){
        count[i]+=count[i-1];// CUMMULATIVE SUM
    }
    for(int i=0;i<n;i++){
        b[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        printf("\t%d",b[i]);
    }
}

int main(){
int n=8;

int arr[]={1,3,8,3,5,7,1};
// int n=7;
// int arr[]={4,2,2,8,3,3,1};
countingsort(arr,n);
// for(int i=0;i<n;i++){
//     printf("%d ",arr[i]);
// }

}