#include <stdio.h>
#include <string.h>

char map[3072][6144];

void draw(int r, int c, int n)
{
    if(n == 3)
    {
        map[r][c] = '*';
        map[r+1][c-1] = '*';
        map[r+1][c+1] = '*';
        for(int i=-2; i<=2; i++) map[r+2][c+i] = '*';
        return;
    }

    int half = n / 2;
    draw(r, c, half);
    draw(r+half, c-half, half);
    draw(r+half, c+half, half);
}

int main(void)
{
    int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++) memset(map[i], ' ', 2*N);
    draw(0, N - 1, N);

    for(int i=0; i<N; i++)
    {
        map[i][2*N-1] = '\0';
        printf("%s\n", map[i]);
    }

    return 0;
}