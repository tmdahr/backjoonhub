#include <stdio.h>

int map[55][55];
int visit[55][55];
int dh[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dw[] = {0, 0, 1, -1, 1, -1, 1, -1};
int H, W;

void DFS(int h, int w)
{
    visit[h][w]=1;
    for(int i=0; i<8; i++)
    {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if(0<=nh && nh<H && 0<=nw && nw<W)
            if(!visit[nh][nw] && map[nh][nw])
                DFS(nh, nw);
    }
}

int main(void)
{
    scanf("%d %d", &W, &H);
    while(H||W)
    {
        for(int i=0; i<H; i++)
            for(int j=0; j<W; j++)
            {
                scanf("%d", &map[i][j]);
                visit[i][j]=0;
            }
        int count=0;
        for(int i=0; i<H; i++)
            for(int j=0; j<W; j++)
                if(!visit[i][j] && map[i][j])
                {
                    DFS(i,j);
                    count++;
                }
        printf("%d\n", count);
        scanf("%d %d", &W, &H);
    }

    return 0;
}