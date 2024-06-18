#include<stdio.h>
#include<limits.h>
int MaxSubarraySum(int arr[],int n){
    //int start = 0;
    int maxsum=INT_MIN;
    int currentsum = 0;
    for(int i=0;i<n;i++){
        int start=i;
        for(int j=i;j<n;j++){
            int  end=j; 
            currentsum=0;//***DONT FORGET THIS ***
            //printf("\t\tmaxsum %d |", currentsum);
            for(int k=start;k<=end;k++){
                //printf("%d ", arr[k]);
                currentsum+=arr[k];
            }
            //printf("\t\tcursum1 %d ", maxsum);
            if (maxsum<currentsum){
                //_____________Can be replaced with MAX()____________
                maxsum=currentsum;
            }
           
            //printf("\n");
            //printf("\n");
        
        }
    }
return maxsum;
}
int main(){

int arr[]={ -2, -3, 4, -1, -2, 1, 5, -3 };
//int arr[]={2,4,6,8,10};
int n=8;
int sum=MaxSubarraySum(arr,n);
printf("%d\n",sum);

}