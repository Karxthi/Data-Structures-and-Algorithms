#include<stdio.h>
#include<iostream>
using namespace std;
int lcs(string s1, string s2){
    int m=s1.length();
    int n=s2.length();
    int c[m+1][n+1];
    for(int i=0; i<m+1; i++){
        c[i][0]=0;
    }
    for(int i=0; i<n+1; i++){
        c[0][i]=0;
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(s1[i-1]==s2[j-1]){
                c[i][j]=1+c[i-1][j-1];
            }
            else if(c[i-1][j]>c[i][j-1]){
                c[i][j]=c[i-1][j];
            }
            else{
                c[i][j]=c[i][j-1];
            }
    }
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<"\t"<<c[i][j];
        }
        cout<<"\n";
    }

    return c[m][n];
}
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int len=lcs(s1,s2);
    cout<<"\n len"<<len;
}