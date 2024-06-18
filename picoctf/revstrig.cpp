#include <bits/stdc++.h>

using namespace std; 
#define N 6		


struct Activity 
{ 
    int start, finish; 
}; 


bool Sort_activity(Activity s1, Activity s2) //
{ 
    return (s1.finish< s2.finish); 
} 


void acivitySelectionGreedy(Activity arr[], int n) 
{ 
    // inbuilt function
	sort(arr, arr+n, Sort_activity); 

	cout<< "Selected Activties are \n"; 

   
    int i = 0; 
	cout<< "(" <<arr[i].start<< ", " <<arr[i].finish << ")\n"; 

    
    for (int j = 1; j < n; j++) 
    { 
    	// Select this activity if it has start time greater than or equal
    	// to the finish time of previously selected activity
      	if (arr[j].start>= arr[i].finish) 
      	{	 
			cout<< "(" <<arr[j].start<< ", "<<arr[j].finish << ") \n"; 
			i = j; 
      	} 
    } 
} 


int main() 
{ 
    Activity arr[N];// structure of arrays
	for(int i=0; i<=N-1; i++)
	{
		cout<<"Enter the start and end time of "<<i+1<<" :  \n"<<endl;
		cin>>arr[i].start>>arr[i].finish;
    }

	acivitySelectionGreedy(arr, N); 
    return 0; 
}