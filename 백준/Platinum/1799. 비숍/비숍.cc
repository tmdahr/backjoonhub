#include <stdio.h>

#define MAX 10

int N;
int board[MAX][MAX];
int max_black = 0, max_white = 0;
int diag1[2*MAX], diag2[2*MAX];

void dfs(int idx, int count, int size, int cells[][2], int *max_count)
{
    if(idx == size)
    {
        if(count > *max_count) *max_count = count;
        return;
    }
    
    int r = cells[idx][0], c = cells[idx][1];
    int d1 = r + c;
    int d2 = r - c + N - 1;

    if (!diag1[d1] && !diag2[d2])
    {
        diag1[d1] = diag2[d2] = 1;
        dfs(idx+1, count+1, size, cells, max_count);
        diag1[d1] = diag2[d2] = 0;
    }

    dfs(idx+1, count, size, cells, max_count);
}

int main(void)
{
    scanf("%d", &N);
    int black_cells[MAX*MAX][2], white_cells[MAX*MAX][2];
    int b_size = 0, w_size = 0;

    for(int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            scanf("%d", &board[i][j]);
            if(board[i][j])
            {
                if((i+j) % 2 == 0)
                {
                    black_cells[b_size][0] = i;
                    black_cells[b_size][1] = j;
                    b_size++;
                }
                else
                {
                    white_cells[w_size][0] = i;
                    white_cells[w_size][1] = j;
                    w_size++;
                }
            }
        }
    }
    
    dfs(0, 0, b_size, black_cells, &max_black);
    dfs(0, 0, w_size, white_cells, &max_white);

    printf("%d\n", max_black + max_white);
    return 0;
}