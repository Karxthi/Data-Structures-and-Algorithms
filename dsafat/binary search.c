#include <stdio.h>
int binarysearch(int arr[],int n,int key){
    int si=0;
    int ei=n-1;
    while(si<ei){
        int mid=(si+ei)/2;
        if(arr[mid]==key)
            {
                return mid;
            }
        else if(key<arr[mid]){
            ei=mid-1;
        }
        else{
            ei=mid+1;
        }
        
    }
}
int main(){
    int arr[]={4,5,7,2,3,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int index=binarysearch(arr,n,7);
    printf("%d\n",index);
}