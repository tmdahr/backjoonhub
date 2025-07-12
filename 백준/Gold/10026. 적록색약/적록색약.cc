#include <stdio.h>
#include <string.h>
#define MAX 101

int n;
char map[MAX][MAX];
int visit[MAX][MAX];
int dh[] = {-1,1,0,0}, dw[] = {0,0,-1,1};

void DFS(int h, int w, char color)
{
    visit[h][w] = 1;

    for(int i=0; i<4; i++)
    {
        int nh = h+dh[i];
        int nw = w+dw[i];

        if(nh>=0 && nh<n && nw>=0 && nw<n)
            if(!visit[nh][nw] && map[nh][nw]==color)
                DFS(nh, nw, color);
    }
}

int main(void)
{
    scanf("%d", &n);

    for(int i=0; i < n; i++) scanf("%s", map[i]);

    int normal = 0;
    memset(visit, 0, sizeof(visit));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(!visit[i][j])
            {
                DFS(i, j, map[i][j]);
                normal++;
            }


    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(map[i][j] == 'R') map[i][j] = 'G';
    int blind = 0;
    memset(visit, 0, sizeof(visit));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(!visit[i][j])
            {
                DFS(i, j, map[i][j]);
                blind++;
            }

    printf("%d %d\n", normal, blind);
    return 0;
}