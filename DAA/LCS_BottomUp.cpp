#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Enter the first string: Batman
// Enter the second string: Batwomen
// Length of LCS: 5
// LCS: Batmn

void findLCS(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();
    //D vector to store the length of LCS for each prefix
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    
    int lengthLCS = dp[m][n];
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
                i--;
                j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    cout << "Length of LCS: " << lengthLCS << endl;
    cout << "LCS: " << lcs << endl;
}
int main() {
string str1, str2;
cout << "Enter the first string: ";
cin >> str1;
cout << "Enter the second string: ";
cin >> str2;
findLCS(str1, str2);
return 0;
}