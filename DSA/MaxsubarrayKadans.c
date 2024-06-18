#include<stdio.h>
#include<limits.h>
int kadans(int arr[],int n){
    //______________________________KADAN'S ALGORITHM________________________
    int maxsum=INT_MIN;
    int currentsum=0;
    
    for(int i=0; i<n;i++){//_________Only 1 LOOP , O(n)
        currentsum+=arr[i];
        if (currentsum<0){
            currentsum=0;
        }
        if (currentsum>maxsum){
            //_____________Can be replaced with MAX()____________
            maxsum=currentsum;
        }
    }
    return maxsum;
}

int main(){
int arr[]={ -2, -3, 4, -1, -2, 1, 5, -3 };

int n=8;
int sum=kadans(arr,n);\
printf("%d\n",sum);

}