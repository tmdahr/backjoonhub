#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int board[105];
    for(int i=1; i<=100; i++) board[i] = i;
    for(int i=0; i<n+m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        board[u] = v;
    }
    
    int dist[105];
    fill(dist, dist+105, -1);
    queue<int> q;
    q.push(1);
    dist[1]=0;
    
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        if(now == 100)
        {
            printf("%d\n", dist[100]);
            return 0;
        }
        
        for(int dice=1; dice<=6; dice++)
        {
            int next = now+dice;
            if(next > 100) continue;
            int next_board = board[next];
            
            if(dist[next_board] == -1)
            {
                dist[next_board] = dist[now] + 1;
                q.push(next_board);
            }
        }
    }
    
    return 0;
}