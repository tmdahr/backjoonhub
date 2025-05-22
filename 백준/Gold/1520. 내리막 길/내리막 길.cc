#include <stdio.h>

int map[505][505];
int dp[505][505];
int n, m;

int DFS(int h, int w)
{
    if(h==m-1 && w==n-1) return 1;
    if(dp[h][w]!=-1) return dp[h][w];

    int dh[]={0,0,1,-1}, dw[]={1,-1,0,0};
    dp[h][w]=0;
    for(int i=0;i<4;i++)
    {
        int hh = h+dh[i];
        int ww = w+dw[i];
        if(0<=hh&&hh<m&&0<=ww&&ww<n)
        {
            if(map[hh][ww]<map[h][w]) dp[h][w]+=DFS(hh,ww);
        }
    }
    return dp[h][w];
}

int main(void)
{
    scanf("%d %d", &m, &n);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &map[i][j]);
            dp[i][j]=-1;
        }
    }
    printf("%d\n", DFS(0,0));

    return 0;
}