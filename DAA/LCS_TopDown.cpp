#include <iostream>
#include <string>
#include <vector>
using namespace std;
int dp[1000][1000];
void initialize(int m, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
}
pair<int, string> LCS(string str1, string str2, int i, int j) {
    if (i == 0 || j == 0) {
        return {0, ""};
    
    }
    if (dp[i][j] != -1) {
        return {dp[i][j], ""};
    }
    if (str1[i - 1] == str2[j - 1]) {
        pair<int, string> result = LCS(str1, str2, i - 1, j - 1);
        dp[i][j] = result.first + 1;
        return {dp[i][j], str1[i - 1] + result.second};
    } else {
        pair<int, string> result1 = LCS(str1, str2, i - 1, j);
        pair<int, string> result2 = LCS(str1, str2, i, j - 1);
        dp[i][j] = max(result1.first, result2.first);
        return {dp[i][j], result1.first > result2.first ? result1.second : result2.second};
    }
}
int main() {
string str1 = "apple";
string str2 = "ball";
initialize(str1.length(), str2.length());
pair<int, string> result = LCS(str1, str2, str1.length(), str2.length());
int lcsLength = result.first;
string lcs = result.second;
cout << "Length of LCS: " << lcsLength << endl;
cout << "LCS: " << lcs << endl;

return 0;
}