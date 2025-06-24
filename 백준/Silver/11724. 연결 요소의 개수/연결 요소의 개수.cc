#include <stdio.h>
#include <vector>
using namespace std;

vector<int> map[1001];
int visit[1001];
int n,m;

void DFS(int start)
{
    visit[start] = 1;
    for(int i=0; i<map[start].size(); i++)
    {
        int idx = map[start][i];
        if(visit[idx] == 0) DFS(idx);
    }
}

int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        map[s].push_back(e);
        map[e].push_back(s);
    }

    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(visit[i] == 0)
        {
            cnt++;
            DFS(i);
        }
    }
    printf("%d", cnt);
}