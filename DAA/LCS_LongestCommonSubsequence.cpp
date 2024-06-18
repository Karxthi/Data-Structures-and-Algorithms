#include <iostream>
#include <string>
using namespace std;

int LCS(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Add 1 for diagonal match
    
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Choose the larger LCS length
            }
        }
    }

    return dp[m][n];
}
int main() {
string str1 = "apple";
string str2 = "ball";
int lcsLength = LCS(str1, str2);
cout << "Length of LCS: " << lcsLength << endl;
return 0;
}