
#include <iostream>
using namespace std;
void smallestsum(int arr[], int n)
{
	int inv_count = 0;
	int i,j;
	int mj=0;int mi=0;
	int sum=0;
	int minsum = 0;

	minsum=arr[0]+arr[1];
	
	for(i = 0; i<n - 1; i++)
	{
		for(j = i + 1; j<n-1;j++)
		{

		    sum = arr[i] + arr[j];


	    	if(minsum>sum)
			{

			minsum=sum;
            mi=i;
            mj=j;
            
			}
		}
	}
	cout << "The two elements whose sum is minimum are "<< mi << " and " << mj <<"sum is"<<minsum <<endl;
}
int main()
{
	int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	smallestsum(arr, n);
	return 0;
}


