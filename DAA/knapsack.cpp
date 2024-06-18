#include <stdbool.h>
#include <stdio.h>
#include<iostream>
using namespace std;
int max(int a, int b){
    //cout<<"max: "<<a<<" "<<b<<endl;
    return (a>b)?a:b;
}
void knapsack(int M,int w[],int val[],int n){
    for(int i=0;i<n;i++){
        // cout<<val[i]<<endl;
        // cout<<w[i]<<endl;
    }
    cout<<endl;
    int k[n+1][M+1];//addtional row and col for base cases which are 0
    for(int i=0;i<n+1;i++){
        for(int j=0;j<M+1;j++){
            if(i==0||j==0){
                k[i][j]=0;

            }
            else if(w[i]<=j){
                k[i][j]=max(k[i-1][j],val[i]+k[i-1][j-w[i]]);
                //cout<<k[i][j]<<endl;
            }
            else{
                k[i][j]=k[i-1][j];
            }
        }
    }
    cout<<k[n+1][M+1];

}
int main(){

    
     int val[] = { 0, 3, 4, 5, 6 }; // Array index to start from 1
    int wt[] = { 0, 2, 3, 4, 5 }; // Array index to start from 1
    int M = 8; 
    int n = 5;
    knapsack(M,wt,val,n);

}
