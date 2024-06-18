#include <iostream> 
using namespace std; 
#include <ctime>

int partition(double arr[], int low, int high) {
     int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) { 
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); return (i + 1);
}
void quickSort(double arr[], int low, int high) { 
    if (low < high) {
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); quickSort(arr, pi + 1, high);
    }
}

int main() {
int lengthstocheck[] ={10 ,50 ,100 ,500 ,1000 ,5000 ,10000 ,50000
,100000};
int sizecheck = 9; double times[sizecheck];     
cout << "QUICK SORT\n";
for (int k = 0; k < sizecheck; k++) { 
    int len = lengthstocheck[k]; 
    double arr[len];
    cout << "creating random array with length:" << len << endl; 
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % (len + 1);
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

