#include <stdio.h>
#include <queue>
using namespace std;

struct node{
    int to, cost;
    node(int t, int c) : to(t), cost(c) {}
};

int num[105][105], vi[105];
int n;

void init()
{
    for(int i=1; i<=n; i++) vi[i]=0;
}

int bfs(int f)
{
    queue<node> q;
    q.push(node(f, 0));
    vi[f]=1;
    int sum=0;
    while(!q.empty())
    {
        node now = q.front();
        q.pop();
        for(int i=1; i<=n; i++)
        {
            if(num[now.to][i]==1 && vi[i]==0)
            {
                vi[i]=1;
                sum+=now.cost+1;
                q.push(node(i,now.cost+1));
            }
        }
    }

    return sum;
}

int main(void)
{
    int m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        num[from][to]=1;
        num[to][from]=1;
    }
    int min=0, min_num=0, cnt;
    for(int i=1; i<=n; i++)
    {
        init();
        cnt = bfs(i);
        if(min_num==0 || cnt < min)
        {
            min = cnt;
            min_num = i;
        }
    }
    printf("%d\n", min_num);

    return 0;
}