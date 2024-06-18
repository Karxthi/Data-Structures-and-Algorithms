#include <iostream>
#include <climits>

using namespace std;

int MatrixChainMultiplication(int P[], int n) {
    int m[n][n];
    int s[n-1][2*n];
    for(int i = 0; i < n;i++){
        m[i][i] =0;
    }

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {//_______ IT STARTS FROM ROW 1, ROW 0 IS AVOIDED
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j];
                cout<<"\n"<<"i :"<<i<<"j: "<<j<<"cost: "<<cost<<endl;//f(i,i)f(i,k)=0=mini≤j<k[f(i,j)+f(j+1,k)+(ri×cj×ck)]
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
                cout << "\nTable-" << endl;
    // for (int i = 0; i <n; i++) {//_______SKIPPING *****TOP****** ROW
    //     for (int j = 0; j <n; j++) {//_____________SKIPPING ******LEFT********  COLUMN
            
    //         if (j >= i) { // since it is an upper triangulR matrix
    //             cout << m[i][j] << "\t";
    //         } else {
    //             cout << "0\t";// for lower triangular half, since its empty
    //         }
    //     }
    //     cout << endl;
    // }
            }
        }
    }
    // for printing the entire table
    cout << "Table-" << endl;
    for (int i = 1; i <n; i++) {//_______SKIPPING A ROW
        for (int j = 1; j <n; j++) {//_____________SKIPPING A COLUMN
            
            if (j >= i) { // since it is an upper triangulR matrix
                cout << m[i][j] << "\t";
            } else {
                cout << "0\t";// for lower triangular half, since its empty
            }
        }
        cout << endl;
    }

    return m[1][n - 1];
}

int main() {
    // int n;
    // cout << "Total Matrices : " <<endl;
    // cin >> n;

    // int P[n + 1];// N matrix has N+1 dimensions
    // cout << "Enter the dimensions in sequential order :"; //P[i]->number of rows in matrix i
    // //                                                      P[i+1] gives you the number of columns
    // for (int i = 0; i <= n; i++) {
    //     cin >> P[i];
    // }

    // cout << "Number of ways to parenthesize: " << MatrixChainMultiplication(P, n + 1) << endl;

    // return 0;

    {
    int arr[] = { 1, 2, 3, 4, 3 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    //cout << "Minimum number of multiplications is ";
    
    MatrixChainMultiplication(arr, N+1);
    return 0;
}
}
