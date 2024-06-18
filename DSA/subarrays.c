#include<stdio.h>
void subarray(int arr[],int n){
    for(int i=0;i<=n;i++){
        int start=i;
        for(int j=i;j<=n;j++){
            int end=j;
            for(int k=start;k<end;k++){      
                printf("%d ",arr[k]);
        }
        printf("\t");

    }
    printf("\n");
}
}


int main(){
int arr[] = {0,1,2,3,4,5,6};
int n=sizeof(arr)/sizeof(arr[0]);
subarray(arr,n);

}