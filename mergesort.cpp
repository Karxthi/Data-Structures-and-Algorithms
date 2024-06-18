//Algorithm
//**Merging**
//if two lists are already sortd , it is compared i with j , and result is combined in K array whcih is also sorted
// THETA( m + n ) - moving m and n to K array
//i=1,j=1,k=1;
// while(i<=n & j<=m)
// if(A[i]>B[j])
//     C[k++]=A[i++];
// else
//     C[k++]=B[i++];
// *******copying remaining elements*****
// for(;i<=n;i++)
// c[k++]=A[i];
// for(;j<=mi++)
// c[k++]=B[i];
//  ________________________________________________________________
//mergesort(l,h)
// if l<h;
// mid=1+h/2
// mergesort(l,mi)
// mergesort(mid+1,h)
// merge(l,mmid,h)

#include<stdio.h>
void mergesort(int arr[],int l, int m, int h ){
    int i=1,j=1,k=1;
    while(i<=l && j<=h){
        if(arr[i]>arr[j]){
            
        }
    }
}

#include <iostream> 
#include <ctime> 
using namespace std;

void merge(int arr[], int p, int q, int r) {

int n1 = q - p + 1; 
int n2 = r - q;

int L[n1], M[n2];

for (int i = 0; i < n1; i++){
    L[i] = arr[p + i];}
for (int j = 0; j < n2; j++){
    M[j] = arr[q + 1 + j];
}

int i, j, k; i = 0;
j = 0;
k = p;

while (i < n1 && j < n2) { if (L[i] <= M[j]) {
    arr[k] = L[i++];
} else {
    arr[k] = M[j++];
} k++;
}

while (i < n1) {
     arr[k++] = L[i++];
}

while (j < n2) {
     arr[k++] = M[j++];
}
}

void mergeSort(int arr[], int l, int r) { 
    if (l < r) {
int m = l + (r - l) / 2;

mergeSort(arr, l, m); 
mergeSort(arr, m + 1, r);
merge(arr, l, m, r);
}
}

void printArray(int arr[], int size) { 
    for (int i = 0; i < size; i++)
cout << arr[i] << " "; cout << endl;
}

int main() {
int lengthsToCheck[] = {10 ,50 ,100 ,500 ,1000 ,5000 ,10000 ,50000
,100000};
int sizeCheck = 9; 
double times[sizeCheck];

for(int k = 0; k < sizeCheck; k++){ 
    int len = lengthsToCheck[k]; int arr [len];
    cout << "Creating random array with length: "<< len << endl; 
    for(int i = 0; i < len; i++){
    arr[i] = rand() % (len + 1 - 0) + 0;
    }
clock_t start,end; start = clock();
mergeSort(arr, 0, len - 1);
end = clock();
double t = double(end-start)/double(CLOCKS_PER_SEC); 
cout << "Time to sort the array: " << t << " s" << endl; 
times[k] = t;
}
return 0;
}

