#include <stdio.h>
#include <iostream>
#include <climits>
#include<cmath>
using namespace std;
void mcm(int p[],int n){
    int m[n][n];
    for(int i = 0; i < n;i++){
        m[i][i]=0;

    }
    for(int len=2;len<n;len++){
        for(int i=1;i<n-len+1;i++) {
            int j=i+len-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                //cout<<"\n"<<"i :"<<i<<"j: "<<j<<"cost: "<<cost<<endl;//f(i,i)f(i,k)=0=mini≤j<k[f(i,j)+f(j+1,k)+(ri×cj×ck)]
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(j>=i){
                cout<<m[i][j]<<"\t";
            }
            else{
                cout<<"\t";
            }
        }
        cout<<"\n";
    }

    cout<<m[1][n-2]<<endl;
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    //cout << "Minimum number of multiplications is ";
    
    mcm(arr, N+1);
    return 0;
}