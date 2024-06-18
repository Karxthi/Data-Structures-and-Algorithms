#include <iostream>
#include <limits.h>
using namespace std; 

int max(int a, int b) { 
	return (a > b) ? a : b; 
} 

int max(int a, int b, int c) { 
	return max(max(a, b), c); 
} 

int maxSum(int arr[], int l, int m, int h) { 

	int sum = 0; 
	int leftsidesum = INT_MIN; 
	for (int i = m; i >= l; i--) { 
		sum = sum + arr[i]; 
		if (sum > leftsidesum) 
			leftsidesum = sum; 
	} 

	sum = 0; 
	int rightsidesum = INT_MIN; 
	for (int i = m; i <= h; i++) { 
		sum = sum + arr[i]; 
		if (sum > rightsidesum) 
			rightsidesum = sum; 
	} 

	return max(leftsidesum + rightsidesum - arr[m], leftsidesum, rightsidesum); 
} 

int maxsubarray(int arr[], int l, int h) { 

	if (l > h) 
		return INT_MIN; 

	if (l == h) 
		return arr[l]; 


	int m = (l + h) / 2; 
	return max(maxsubarray(arr, l, m - 1), 
			maxsubarray(arr, m + 1, h), 
			maxSum(arr, l, m, h)); 
} 

int main() { 
	int arr[] = { 2,1,2,6,-7,4,3,5,1,9}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int max_sum = maxsubarray(arr, 0, n - 1); 
	cout << "Maximum subarray sum : " << max_sum; 
	return 0; 
} 
