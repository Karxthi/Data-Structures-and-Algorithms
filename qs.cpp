#include <iostream>
#include <ctime>
using namespace std;

void display(double arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void swap(double* a, double* b){
    double temp= *a;
    *a=*b;
    *b=temp; 
}

int partition(double arr[], int s, int  e){
    double pivot = arr[s];
    int i=s;
    int j=e;
    while(i<j){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[s],&arr[j]);
    return j;
}

void quickSort(double arr[], int s, int e){
    if(s<e){
        int j=partition(arr,s,e);
        quickSort(arr, s, j-1);
        quickSort(arr, j+1, e);
    }
}

int main(){
    int lengthstocheck[] = {10, 50, 100, 1000, 5000, 10000, 50000, 100000};
  int sizecheck = 8;
  double times[sizecheck];

  for (int k = 0; k < sizecheck; k++) {
    int len = lengthstocheck[k];
    double arr[len];
    cout << "creating descending array with length:" << len << endl;
    for (int i = len; i < 0; i++) {
      arr[i] = 10 * i;
    }

    clock_t start, end;
    start = clock();
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    end = clock();
    double t = double(end - start) / double(CLOCKS_PER_SEC);
    times[k] = t;
    cout << "Time taken is:" << t << " seconds" << endl;
  }
}