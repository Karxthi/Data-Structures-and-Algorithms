#include<stdio.h>
#include<conio.h>
int largestnumber(int arr[],int n){
    int max=arr[0];
    for(int j=0;j<=n;j++){
        if(arr[j]>max){
            max=arr[j];
            max=j;
        }
    }
    return max;
};

int main(){
int n;
scanf("%d",&n);

int arr[]={4,3,2,5,7,8,6,8,9};
int length=sizeof(arr)/sizeof(arr[0]);
int in=largestnumber(arr,length);
printf("%d\n",in);

}