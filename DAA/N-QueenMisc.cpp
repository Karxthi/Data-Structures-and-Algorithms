#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<int>& placement, int row, int col) {
    for (int prevRow = 0; prevRow < row; ++prevRow) {
        if (placement[prevRow] == col ||  // Check same column
            placement[prevRow] - prevRow == col - row ||  // Check left diagonal
            placement[prevRow] + prevRow == col + row) {  // Check right diagonal
            return false;
        }
    }
    return true;
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> solutions;
    vector<int> placement(n, -1);  // Initialize placement with -1

    int row = 0;
    int col = 0;

    while (row >= 0) {
        // Place queen in the current row
        while (col < n) {
            if (isSafe(placement, row, col)) {
                placement[row] = col;
                col = 0;
                break;
            } else {
                ++col;
            }
        }

        if (col == n) {
            // No valid placement in current row, backtrack
            if (row == 0) {
                break;  // Finished exploring all possibilities
            }
            placement[row] = -1;
            --row;
            col = placement[row] + 1;
            continue;
        }

        if (row == n - 1) {
            // Found a solution
            solutions.push_back(placement);
            placement[row] = -1;
            --row;
            col = placement[row] + 1;
            continue;
        }

        // Move to the next row
        ++row;
    }

    return solutions;
}

void printBoard(const vector<int>& placement) {
    int n = placement.size();
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (placement[row] == col) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> solutions = solveNQueens(n);

    cout << "Number of solutions: " << solutions.size() << endl;
    cout << "Solutions:" << endl;
    for (const auto& placement : solutions) {
        printBoard(placement);
    }

    return 0;
}
