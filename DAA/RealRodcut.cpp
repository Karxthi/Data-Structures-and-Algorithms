#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
void Rodcut(int arr[],int n,int length){
    int B[n+1];
    // Profit array or array with values = maximum profit till that length
    B[0]=0; //     Predefined
    // if(n==0){
    //     return arr[0];
    // }
    for(int i=1;i<=n;i++){ //    To iterate over price array
        int q=INT_MIN;
        for(int k=1;k<=i;k++){ //  To create all k till i  (crearting all combinations of i+k=n)
            //cout<<"current :"<<arr[k-1]+B[i-k]<<endl;
            q=max(q,arr[k-1]+B[i-k]);
            //S[i]=k;
        }
        cout<<"\n"<<q;
        B[i]=q;

        //eg:  (||||)(|) = same as B(5)= v(5) + B(4)
    } 
    cout<< B[5]<<endl;
   

}
int main(){
  int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    //int a=0;
    int length = 5;
    Rodcut(arr, size,length);
   // a = Rodcut(arr, size,length);
    //cout <<"\n vALUES : "<<a;
    return 0;
}