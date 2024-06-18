#include <iostream> 
 
#include <climits> 
 
using namespace std; 
 
void printMaxSubArray(int arr[], int n) { 
  int max_sum = arr[0], curr_sum = arr[0], start_index = 0, end_index = 0, s = 0, len = 1; 
 
  for (int i = 1; i < n; i++) { 
    if (curr_sum + arr[i] > arr[i]) { 
      curr_sum += arr[i]; 
    } else { 
      curr_sum = arr[i]; 
      s = i; 
    } 
 
    if (curr_sum > max_sum) { 
      max_sum = curr_sum; 
      start_index = s; 
      end_index = i; 
      len = end_index - start_index + 1; 
    } else if (curr_sum == max_sum && i - s + 1 > len) { 
      end_index = i; 
      start_index = s; 
      len = end_index - start_index + 1; 
    } 
  } 
 
  cout << "Starting Index: " << start_index << endl; 
  cout << "Ending Index: " << end_index << endl; 
  cout << "Maximum Sum: " << max_sum << endl; 
} 
 
int main()  
{ 
  int arr[] = {4,-12,3,10,4,5,-15,6,7,1,3,1,4}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  printMaxSubArray(arr, n); 
  return 0; 
} 

