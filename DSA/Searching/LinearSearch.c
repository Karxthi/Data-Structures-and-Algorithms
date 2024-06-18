#include <stdio.h>
int main()
{
    int n; 
    scanf("%d", &n);
    int ele;
    scanf("%d", &ele);
    int arr[n];
   int index=0;
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            index=i;
            break;}
        else{
            index=0;
        }

    }
    if(index>0){
        printf("found at index %d\n",index);
    }
}