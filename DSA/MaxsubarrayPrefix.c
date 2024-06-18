#include<stdio.h>
#include<limits.h>
int MaxSubarraySum(int arr[],int n){
    //int start = 0;
    int maxsum=INT_MIN;
    int currentsum = 0;

    //_____________________PREFIX ARRAY CALCULATION________________
    int prefix[n];
    prefix[0] =arr[0];
    for(int i=1;i<n;i++){
        prefix[i] =prefix[i-1]+arr[i];
    }
    //_____________________(can be done in main() also)________________


    for(int i=0;i<n;i++){
        int start=i;
        for(int j=i;j<n;j++){
            int end=j; 
            //______________IMPORTANT STEP________________
           currentsum = start==0 ? prefix[end]:prefix[end]-prefix[start-1];
           //_______________Here we use TERNARY OPERATOR , if i=0(start=0) the above part becomes prefix[0-1], **NEGATIVE INDEX**____________
            printf("\t\t%d",currentsum);
            if (maxsum<currentsum){
                //_____________Can be replaced with MAX()____________
                maxsum=currentsum;
            }
        }
    }
return maxsum;
}
int main(){

int arr[]={ -2, -3, 4, -1, -2, 1, 5, -3 };
//int arr[]={1,-2,6,-1,3};
int n=8;
int sum=MaxSubarraySum(arr,n);
printf("\n%d\n",sum);

}