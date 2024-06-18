#include <iostream>
#include <string.h>
#include <stdbool.h>
using namespace std;
int search(string text,string pattern){
    int n=text.length();
    int m=pattern.length();
    bool flag= true;
    for(int i=0;i<n-m;i++){//If we went beyond n-m, 
    //the inner loop would try to access text characters beyond the bounds of the text, 
    //since we are checking text[i+j] against pattern[j].
        // int j;
        // for(int j=0;j<m;j++){
        //     if(text[i+j]!=pattern[j]){
        //         break;
        //     }
        // }
        // if(j==m)// means j found match and ran till M times
        // {
        //     return i;
        // }
        
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
            return i;
        }

    }
    return -1;// ******* IF NOTHING TO RETURN *******

}
int main(){
    string s1,s2;
    getline(cin,s1);// getline
    cin>> s2;
    int index = search(s1,s2);
    cout<<"found at index:"<<index<<endl;
}