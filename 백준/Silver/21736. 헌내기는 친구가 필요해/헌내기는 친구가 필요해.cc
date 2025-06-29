#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
int res = 0;
char map[601][601];
int visit[601][601] = {0};
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
queue<pair<int, int>> q;

void bfs(void)
{
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(map[ny][nx] == 'X') continue;
            if(visit[ny][nx] == 1) continue;

            if(map[ny][nx] == 'P') res++;
            visit[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

int main(void)
{
    scanf("%d %d", &n, &m);
    for(int y = 0; y < n; y++)
    {
        scanf("%s", map[y]);
        for(int x = 0; x < m; x++)
        {
            if(map[y][x] == 'I')
            {
                q.push({y, x});
                visit[y][x] = 1;
            }
        }
    }

    bfs();
    if(res == 0) printf("TT");
    else printf("%d", res);

    return 0;
}