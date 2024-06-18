#include<stdio.h>
#include<limits.h>
int CountingSort(int arr[],int n){
    int max=INT_MIN;
    //_____________FINDING MAXIMUM VALULE____
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }

    }
    printf("%d\n",max);
    //______________SETTING COUNT ARRAY TO 0_____________
    int count[max+1];
    int b[max+1];
    for(int i=0;i<max+1;i++){//         MAX + 1    or <=MAX
        
        count[i]=0;
    }//________________________________________________________________
    //______________INCREMENTING COUNT ARRAY________
    
    for(int i=0;i<n;i++){
        ++count[arr[i]];
    }
    for(int i=1;i<max+1;i++){
        count[i]+=count[i-1];//   Summming
    }
    for(int i=0;i<n;i++){
        b[--count[arr[i]]]=arr[i];
    }
    //________________________________________________________________
    for(int i=0;i<n;i++){//       Copying back
        arr[i]=b[i];
    }
  

};

int main(){
int n=7;
int arr[]={4,2,2,8,3,3,1};
CountingSort(arr,n);
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}

}