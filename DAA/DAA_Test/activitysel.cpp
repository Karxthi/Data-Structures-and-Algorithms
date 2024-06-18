#include<stdio.h>
#include<iostream>
#include<stdbool.h>
#define N 100;
using namespace std;
struct Activity{
    int start;
    int finish;
};

void activitysel(struct Activity arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[j].finish<arr[i].finish){
                int temp=arr[j].finish;
                arr[j].finish=arr[i].finish;
                arr[i].finish=temp;
            }
        }
    }
    int i=0;
    cout<<arr[i].start<<" and "<<arr[i].finish<<"\n";
    for(int j=1;j<n;j++){
        if(arr[j].start>=arr[i].finish){
            cout<<arr[j].start<<" and "<<arr[j].finish<<"\n";
            i=j;
        }
    }

}
int main(){
    int n;
    cin>>n;
    //#undef N

    struct Activity arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].finish;
    }
    activitysel(arr,n);
}