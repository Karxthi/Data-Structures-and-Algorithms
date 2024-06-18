// #include<iostream>
// #include <bits/stdc++.h>
// using namespace std;
// #define N 6
// struct Activity {
//     int start, finish;
// };
// void  activityselIterative(Activity arr[],int n)
// {
//     cout<<"Selected Activities"<<endl;
//     int  i=0,j=1;
//     //cout<<"("<<arr[i].start<<"'"<<arr[i].end<<")"<<endl;
//     //int min=INT_MIN;

//     for(i=0;i<n-1;i++){
//         for(j=i+1;j<n;j++){
//             if(arr[j].finish<arr[i].finish){
//                 int temp1=arr[j].start;
//                 int temp2=arr[j].finish;
//                 arr[j].start=arr[i].start;
//                 arr[j].finish=arr[i].finish;
//                 arr[i].start=temp1;
//                 arr[i].finish=temp2;
//         }
//     }
//     for(int i=0;i<n;i++){
//         cout<<"("<<arr[i].start<<"'"<<arr[i].finish<<")"<<endl;
//     }
//     }

// }

// int main(){
//     Activity arr[N];// structure of arrays
// 	for(int i=0; i<=N-1; i++)
// 	{
// 		cout<<"Enter the start and end time of "<<i+1<<" :  \n"<<endl;
// 		cin>>arr[i].start>>arr[i].finish;
//     }

// 	activityselIterative(arr,N); 
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
#define N 6
using namespace std;

struct Activity {
    int start, finish;
};

void selectActivities(Activity arr[], int n, vector<Activity>& selected, int lastFinishTime) {// vector<Activity>& selected is a reference to activity vector
    if (n == 0) {
        return;
    }

    if (arr[0].start >= lastFinishTime) {
        selected.push_back(arr[0]);// push the structure into vector
        selectActivities(arr + 1, n - 1, selected, arr[0].finish);// increment arr index by 
    } else {
        selectActivities(arr + 1, n - 1, selected, lastFinishTime);
    }
}

int main() {
    
    int n = sizeof(arr) / sizeof(arr[0]);
    Activity arr[N];// structure of arrays
        	for(int i=0; i<=N-1; i++)
        	{
        		cout<<"Enter the start and end time of "<<i+1<<" :  \n"<<endl;
        		cin>>arr[i].start>>arr[i].finish;
            }

    sort(arr, arr + N, [](Activity a, Activity b) {
        return a.finish < b.finish;
    });

    vector<Activity> selected;
    selectActivities(arr, N, selected, 0);

    cout << "Selected Activities:" << endl;
    for (int i = 0; i < selected.size(); i++) {
        cout << "(" << selected[i].start << ", " << selected[i].finish << ")" << endl;
    }

    return 0;
}
