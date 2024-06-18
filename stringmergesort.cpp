#include <iostream> 
#include <array> 
#include <ctime>

using namespace std;
const int MAX_SIZE = 5; // Set the size of your array

void merge(array<string, MAX_SIZE>& arr, int left, int middle, int right) { 
    int n1 = middle - left + 1;
    int n2 = right - middle;
    array<string, MAX_SIZE> leftArr; array<string, MAX_SIZE> rightArr;

for (int i = 0; i < n1; i++) 
    leftArr[i] = arr[left + i];
for (int j = 0; j < n2; j++) 
    rightArr[j] = arr[middle + 1 + j];

int i = 0, j = 0, k = left;

while (i < n1 && j < n2) {
    if (leftArr[i] <= rightArr[j]) {
        arr[k++] = leftArr[i++];
}   else {
        arr[k++] = rightArr[j++];
}
}

while (i < n1) {
    arr[k++] = leftArr[i++];
}

while (j < n2) {
    arr[k++] = rightArr[j++];
}
}

void mergeSort(array<string, MAX_SIZE>& arr, int left, int right) {     
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle); 
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}
int main() {
array<string, MAX_SIZE> arr = {"banana", "apple", "orange", "grape", "kiwi"};
cout << "Original array: ";     
for (const auto& str : arr) {
    cout << str << " ";
    }
cout << endl;
mergeSort(arr, 0, MAX_SIZE - 1); 
cout << "Sorted array: ";
for (const auto& str : arr) { 
    cout << str << " ";
}
cout << endl;

return 0;
}
