#include <stdio.h>
#include <string.h>

#define MAX 50

int A[MAX][MAX];
int B[MAX][MAX];

void flip(int x, int y)
{
    for(int i=x; i<x+3; i++)
        for(int j=y; j<y+3; j++)
            A[i][j] = 1 - A[i][j];
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    char temp[MAX+1];

    for(int i=0; i<N; i++)
    {
        scanf("%s", temp);
        for(int j=0; j<M; j++)
            A[i][j] = temp[j] - '0';
    }
    for(int i=0; i<N; i++)
    {
        scanf("%s", temp);
        for (int j = 0; j < M; j++)
            B[i][j] = temp[j] - '0';
    }

    int count = 0;
    for(int i=0; i<=N-3; i++)
    {
        for(int j=0; j<=M-3; j++)
        {
            if(A[i][j] != B[i][j])
            {
                flip(i, j);
                count++;
            }
        }
    }

    int same = 1;
    for(int i=0; i<N && same; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(A[i][j] != B[i][j])
            {
                same = 0;
                break;
            }
        }
    }

    if(same) printf("%d\n", count);
    else printf("-1\n");

    return 0;
}