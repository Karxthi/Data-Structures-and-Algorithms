#include <iostream>
#include <climits>
#include <map>
using namespace std;
// Function to calculate the maximum revenue for rod cutting
int maxRevenue(int n, map<int, int>& memo, int value3, int value5) {
// Base cases
    if (n == 0) return 0;
    if (n < 0) return INT_MIN;
// Check if the result is already memoized
    if (memo.find(n) != memo.end()) {
        return memo[n];
            }
// Recursive calls for rods of length 3 and 5
    int revenue = INT_MIN;
    if (n >= 3) {
        int currentRevenue3 = maxRevenue(n - 3, memo, value3, value5) + value3;
        revenue = max(revenue, currentRevenue3);
    }
    if (n >= 5) {

        int currentRevenue5 = maxRevenue(n - 5, memo, value3, value5) + value5;
        revenue = max(revenue, currentRevenue5);
    }
// Memoize the result
    memo[n] = revenue;
    return revenue;
}
int main() {
int length;
int value3, value5;
// Input the values for rod lengths 3 and 5
cout << "Enter value for rod length 3: ";
cin >> value3;
cout << "Enter value for rod length 5: ";
cin >> value5;
// Ensure the length is greater than or equal to 8
do {
    cout << "Enter the length of the rod (>= 8): ";
    cin>> length;
} 
while (length < 8);
    map<int, int> memo; // Memoization map to store already calculated results
    int result = maxRevenue(length, memo, value3, value5);
    cout << "Maximum revenue that may be generated: Rs." << result << endl;

    return 0;
}
