#include <iostream>
using namespace std;
void diagonal(int arr,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j){
            cout<<arr[i][j]<<endl;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n][n]; 
    for(int i = 0; i < n;){
        for(int j = 0; j < n; j)
        cin >> arr[i][j];
    }
    diagonal(arr[n][n],n);
}