#include <stdio.h>
#define MAX 1000

int find(int parent[], int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find(parent, parent[x]);
}

void merge(int parent[], int x, int y)
{
    x = find(parent, x);
    y = find(parent, y);
    if(x != y) parent[x] = y;
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    char map[MAX][MAX+1];
    int parent[MAX*MAX];
    int visit[MAX*MAX] = {0};

    for(int i= 0; i<n; i++)
    {
        scanf("%s", map[i]);
        for(int j = 0; j < m; j++) parent[i*m+j] = i * m + j;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int cur = i * m + j;
            switch(map[i][j])
            {
                case 'U': merge(parent, cur, (i-1) * m + j); break;
                case 'D': merge(parent, cur, (i+1) * m + j); break;
                case 'L': merge(parent, cur, i * m + (j-1)); break;
                case 'R': merge(parent, cur, i * m + (j+1)); break;
            }
        }
    }

    int count = 0;
    for(int i=0; i<n*m; i++)
    {
        int rep = find(parent, i);
        if(!visit[rep])
        {
            visit[rep] = 1;
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}