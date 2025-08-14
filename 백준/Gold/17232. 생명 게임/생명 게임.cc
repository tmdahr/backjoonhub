#include <stdio.h>
#include <string.h>

#define MAXN 102

int N, M, T, K, A, B;
char board[MAXN][MAXN];
char next_board[MAXN][MAXN];
int sum[MAXN][MAXN];

int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}

void build_sum(void)
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            int alive = (board[i][j] == '*');
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + alive;
        }
    }
}

int get_sum(int r1, int c1, int r2, int c2)
{
    if (r1 > r2 || c1 > c2) return 0;
    return sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1];
}

int main(void)
{
    scanf("%d %d %d", &N, &M, &T);
    scanf("%d %d %d", &K, &A, &B);

    for(int i=1; i<=N; i++) scanf("%s", board[i] + 1);

    while(T--)
    {
        build_sum();

        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=M; j++)
            {
                int r1 = max(1, i - K);
                int c1 = max(1, j - K);
                int r2 = min(N, i + K);
                int c2 = min(M, j + K);

                int neighbors = get_sum(r1, c1, r2, c2);
                if(board[i][j] == '*') neighbors--;

                if(board[i][j] == '*')
                {
                    if(neighbors >= A && neighbors <= B) next_board[i][j] = '*';
                    else next_board[i][j] = '.';
                }
                else
                {
                    if(neighbors > A && neighbors <= B) next_board[i][j] = '*';
                    else next_board[i][j] = '.';
                }
            }
        }
        memcpy(board, next_board, sizeof(board));
    }

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++) putchar(board[i][j]);
        putchar('\n');
    }

    return 0;
}