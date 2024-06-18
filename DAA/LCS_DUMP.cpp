#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int findLCSLength(const string& str1, const string& str2) {
    int m = str1.length();

    int n = str2.length();
    
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1])
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            else
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
        }
    }
  
    return dp[m % 2][n];
}
int main() {
string str1, str2;
cout << "Enter the first string: ";
cin >> str1;
cout << "Enter the second string: ";
cin >> str2;
int lengthLCS = findLCSLength(str1, str2);
// Print the length of LCS
cout << "Length of LCS: " << lengthLCS << endl;
return 0;
}