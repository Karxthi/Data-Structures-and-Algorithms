#include <stdbool.h>
#include <stdio.h>

#define N_MAX 10 // temporary wrokaround

bool solveNQUtil(int board[][N_MAX], int N, int col);
void display(int board[][N_MAX], int N);
bool isSafe(int board[][N_MAX], int N, int row, int col);

int main()
{
    int N;
    printf("Enter the value of N (max 10): ");
    scanf("%d", &N);

    if (N <= 0 || N > N_MAX)
    {
        printf("Invalid value of N\n");
        return 1;
    }

    int board[N_MAX][N_MAX];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if (solveNQUtil(board, N, 0) == false)
    {
        printf("Solution does not exist\n");
        return 0;
    }

    display(board, N);
    return 0;
}

void display(int board[][N_MAX], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int board[][N_MAX], int N, int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)//same row on the left side of the current position
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)// left upper diagonal
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)// left lower diagonal
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[][N_MAX], int N, int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, N, i, col))
        {
            board[i][col] = 1;
            if (solveNQUtil(board, N, col + 1))
                return true;
            board[i][col] = 0;
        }
    }

    return false;
}
