#include <iostream>
#include <cmath>
using namespace std;

void rodcut(int arr[], int n)
{
    int dp[n+1];
    for(int i=1;i<=n;i++)
    {
        int maxprice = 0;
        for(int j=1;j<=i;j++)
        {
            maxprice = max(maxprice, arr[j-1]+dp[i-j]);
        }
        dp[i] = maxprice;
    }
    cout<<dp[5];
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // int arr[] = {0,1, 5, 8, 9, 10, 13, 17, 18,22};
    // int n=9;
    rodcut(arr,n);
    return 0;
}