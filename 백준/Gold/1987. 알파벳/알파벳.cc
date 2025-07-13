#include <stdio.h>
#include <string.h>
#define MAX 21

int r, c, result = 0;
char map[MAX][MAX];
int visit[26];
int dh[] = {-1, 1, 0, 0}, dw[] = {0, 0, -1, 1};

void DFS(int h, int w, int depth)
{
    if(depth > result) result = depth;

    for(int i=0; i<4; i++)
    {
        int nh = h + dh[i];
        int nw = w + dw[i];

        if(nh>=0 && nh<r && nw>=0 && nw<c)
        {
            int idx = map[nh][nw] - 'A';
            if(!visit[idx])
            {
                visit[idx] = 1;
                DFS(nh, nw, depth+1);
                visit[idx] = 0;
            }
        }
    }
}

int main(void)
{
    scanf("%d %d", &r, &c);

    for(int i = 0; i < r; i++) scanf("%s", map[i]);
    visit[map[0][0]-'A'] = 1;
    DFS(0, 0, 1);

    printf("%d\n", result);
    return 0;
}