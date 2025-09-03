#include <stdio.h>

int parent[500001];

int find(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int union_set(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b) return 0;
    if(a < b) parent[b] = a;
    else parent[a] = b;
    return 1;
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++) parent[i] = i;

    for(int i=1; i<=m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(!union_set(a, b))
        {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("0\n");
    return 0;
}
