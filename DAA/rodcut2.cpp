#include <bits/stdc++.h>
#include <ctime>
#include <climits>
using namespace std;

int rodCutting(int price[], int n, vector<int>& cuts) {
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));

    // Base cases
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        int best_cut = -1;

        // Try cutting with lengths 3 and 5
        for (int j : {3, 5}) {
            if (i - j >= 0 && dp[i - j] != -1) {
                int val = price[j - 1] + dp[i - j];
                if (val > max_val) {
                    max_val = val;
                    best_cut = j;
                }
            }
        }

        cuts[i] = best_cut;
        dp[i] = (best_cut != -1) ? max_val : -1;
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    int price[5]; // Since you can cut with lengths 3 and 5
    cout << "Enter the prices of rods of length 3 and 5:" << endl;
    for (int i = 0; i < 5; i++)
        cin >> price[i];

    clock_t tStart = clock();
    vector<int> cuts(n + 1, -1);
    cout << "Maximum revenue that can be generated from the rod is: " << rodCutting(price, n, cuts) << endl;

    cout << "Optimal cutting lengths: ";
    while (n > 0) {
        cout << cuts[n] << " ";
        n -= cuts[n];
    }
    cout << endl;

    double time1 = (double)(clock() - tStart) / CLOCKS_PER_SEC;
    cout << "Time taken is " << time1 << endl;

    return 0;
}
