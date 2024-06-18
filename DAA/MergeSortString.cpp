#include<iostream>
#include<string>
using namespace std;
void Merge(string arr[],int si,int mid,int ei){
    std::string temp[ei-si+1];
    int i=si; // iterator for left part
    int j=mid+1; // iterator for right part
    int k=0; // iterator for temp

    while(i<=mid && j<=ei){
        if(arr[i].compare(arr[j])<0){
            temp[k++]=arr[i++];
            //i++;

        }
        else{
            temp[k++]=arr[j++];
            //j++;
        }//k++;
    }
    //   Remaining elements

    while(i<=mid){
        temp[k++]=arr[i++]; //    left part leftover
    }

    while(j<=ei){
        temp[k++]=arr[j++]; // right part leftover
    }
    //printf("Merged elements");
    int size= sizeof(temp)/sizeof(temp[0]);
    //printf("\t\t%d ",size);
    for( k=0, i=si;k<size;k++,i++){
        //printf("%d ",temp[k]);
        arr[i]=temp[k];
    }

}
void MergeSort(string arr[],int si, int ei){
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
std::string arr[]={"a","e","c","b","d","f"};
MergeSort(arr,0,n-1);
for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}

}