#include<stdio.h>
void Merge(int arr[],int si,int mid,int ei){
    int n1=mid-si+1;
    int n2=ei-mid;
    int L1[n1],L2[n2];// Creating Right & Left Subarrays

    for(int i=0;i<n1;i++){
        L1[i]=arr[i+si];//    Copying from main array
    }

    for(int j=0;j<n2;j++){
        L2[j]=arr[j+mid+1];//    Copying from main array
    }

    int i=0;
    int j=0;
    int k=si;

    while(i<n1 && j<n2){
        if(L1[i]<L2[j]){
            arr[k++]=L1[i++];

        }
        else{
            arr[k++]=L2[j++];
        }
    }printf("\n Kazhijnjj\n");
    //   Remaining elements

    while(i<n1){
        arr[k++]=L1[i++]; //    left part leftover
    }

    while(j<n2){
        arr[k++]=L2[j++]; // right part leftover
    }

}
void MergeSort(int arr[],int si, int ei){
    if (si<ei){
       
            //        To prevent case of single element 
        int mid = (si+ei)/2;
        //OR int mid = (1+h)/2;
        MergeSort(arr,si,mid);//           Recursively Sorts LEFT PART
        MergeSort(arr,mid+1,ei);//         Recursively Sorts RIGHT PART
        Merge(arr,si,mid,ei);
    }
}

int main(){
int n=6;
int arr[]={6,3,9,5,2,8};
MergeSort(arr,0,n-1);
printf("\n Kazhijnjj\n");
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}

}