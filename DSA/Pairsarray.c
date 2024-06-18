#include<stdio.h>
void pairs(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
        {
            printf("%d %d ",arr[i],arr[j]);
        }
        printf("\n");
    }
};

int main(){
    int arr[]={2,4,6,8};
int n=4;
pairs(arr,n);


}