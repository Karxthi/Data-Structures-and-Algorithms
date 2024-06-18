#include <iostream>
#include <climits>
using namespace std;

int MatrixChainMultiplication(int P[], int i, int j) {
    if (i == j) { // COMMON inDEX
        return 0;
    }

    int min = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = MatrixChainMultiplication(P, i, k) + // dividing into i to k and K+1 to J
                   MatrixChainMultiplication(P, k + 1, j) +
                   P[i - 1] * P[k] * P[j];

        //min = min(min, cost);
        if(cost < min) {
            min = cost;
        }
    }

    return min;
}

int main() {
    int n;
    cout << "Total Matrices : " <<endl;
    cin >> n;
 int P[n + 1];
    cout << "Enter the dimensions inn sequential Order: ";
    for (int i = 0; i <= n; i++) {
        cin >> P[i];
    }

    cout << "Min cost is  " << MatrixChainMultiplication(P, 1, n) << endl;

    return 0;
}
