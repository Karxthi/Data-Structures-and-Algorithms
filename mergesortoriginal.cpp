#include <iostream>
#include <vector>
using namespace std;
void merge(vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<double> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } 
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main() {
// Input Arrays
vector<double> array1 = {0, 1, 2, 3, 4, 5};
vector<double> array2 = {5, 5.5, 6, 3.723, 1.23, 8.88};
// Sorting and Displaying Results
mergeSort(array1, 0, array1.size() - 1);
mergeSort(array2, 0, array2.size() - 1);
cout << "Sorted Array 1: [";
for (int i = 0; i < array1.size(); i++) {
    cout << array1[i];
    if (i < array1.size() - 1) {
        cout << ", ";
    }
}
cout << "]" << endl;
cout << "Sorted Array 2: [";
for (int i = 0; i < array2.size(); i++) {
    cout << array2[i];
    if (i < array2.size() - 1) {
        cout << ", ";
    }
}
cout << "]" << endl;
return 0;
}