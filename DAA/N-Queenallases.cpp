#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
        // check upper element
        int duprow = row;
        int dupcol = col;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 1)
                return false;
            row--;
            col--;
        }

        col = dupcol;
        row = duprow;
        while (col >= 0) {
            if (board[row][col] == 1)
                return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        while (row < n && col >= 0) {
            if (board[row][col] == 1)
                return false;
            row++;
            col--;
        }
        return true;
    }

    void solve(int col, vector<vector<int>>& board, vector<vector<vector<int>>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 1;
                solve(col + 1, board, ans, n);
                board[row][col] = 0;
            }
        }
    }

    vector<vector<vector<int>>> solveNQueens(int n) {
        vector<vector<vector<int>>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(0, board, ans, n);
        return ans;
    }
};

int main() {
    int n = 0; // 
    cin>>n;
    Solution obj;
    vector<vector<vector<int>>> ans = obj.solveNQueens(n);
    for (int i = 0; i < ans.size(); i++) {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++) {
            for (int k = 0; k < ans[0][0].size(); k++) {
                cout << ans[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
