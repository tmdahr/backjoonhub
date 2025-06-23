#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int map[1005][1005];
int dist[1005][1005];
bool visit[1005][1005];
int d[4] = { 1, -1, 0, 0 };
int n, m;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;
    dist[x][y] = 0;

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
		for(int i=0; i<4; i++)
        {
            int x_next = now.first + d[i];
            int y_next = now.second + d[3-i];
            if(x_next >= 0 && x_next < n && y_next >= 0 && y_next < m)
				if(map[x_next][y_next] == 1 && !visit[x_next][y_next])
				{
					q.push({ x_next, y_next });
					visit[x_next][y_next] = true;
					dist[x_next][y_next] = dist[now.first][now.second] + 1;
				}
        }
    }
}

int main(void)
{
	scanf("%d %d", &n, &m);
    int x, y;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
			if(map[i][j]==2)
            {
                x = i;
                y = j;
            }
        }
    }

    bfs(x, y);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == 0 && map[i][j] == 1)
                printf("-1 ");
            else
				printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}