#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#include <string.h>
#define d 10
using namespace std;
void rabinkarp(string text,string pattern,int q){
    int n=text.length();
    int m=pattern.length();
    int h=1;
    int t=0;
    int p=0;
    bool flag=true;
    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
    }
    //hashingggg
    for(int i=0;i<m;i++){
        p=(d*p+pattern[i])%q;
        t=(d*t+text[i])%q;
    }
    for(int i=0;i<=n-m;i++){//-------------MISTAKE 1----------
    //                                  i<=n-m
        if(t==p){//pattern found
            for(int j=0;j<m;j++){
                if(text[i+j]==pattern[j]){
                    flag=true;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                cout<<"found at index "<<i+1<<endl;
            }
            // else{
            //     cout<<"not found"<<endl;
            // }
        }
        if(i<n-m){
            t=(d*(t-text[i]*h)+text[i+m])%q;
            if(t<0){
                t+=q;
            }
        }
    }
}
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    rabinkarp(s1,s2,13);
}