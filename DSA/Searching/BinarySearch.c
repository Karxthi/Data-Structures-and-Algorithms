#include<stdio.h>

int binarysearch(int arr[],int key,int n){
    
    int s=0;
    int end=n-1;
    
    while(s<=end){
        int mid=(s+end)/2; //This is inside the loop so mid changes every time
        if(arr[mid]==key){
            return mid;
        }
        if(key<arr[mid]){
            end=mid-1;
        }
        else{
            s=mid+1;
        }
    }
}
int main()
{
    //** Array should be Sorted
    int arr[]={1,4,6,7,8,9,13,16,23,32};
    int length=sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",length);
    int ke=23;
    int index=binarysearch(arr,ke,length);
    printf("Found at index %d\n",index);


}