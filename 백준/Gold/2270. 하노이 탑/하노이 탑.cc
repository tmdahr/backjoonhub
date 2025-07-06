#include <stdio.h>
#define MOD 1000000

int num[100001], pos[100001];
int ans;

void cal(int n)
{
    num[0] = 1;
    for(int i=1; i<=n; i++) num[i] = (num[i-1] * 2) % MOD;
}

void hanoi(int m, int to)
{
    if(m == 0) return;

    int now = pos[m];

    if(now == to) hanoi(m-1, to);
    else
    {
        ans = (ans + num[m-1]) % MOD;
        hanoi(m-1, 6-now-to);
    }
}

int main(void)
{
    int n, a, b, c, m;
    
    scanf("%d", &n);
    cal(n);
    scanf("%d %d %d", &a, &b, &c);

    for(int i=0; i<a; i++)
    {
        scanf("%d", &m);
        pos[m] = 1;
    }
    for(int i=0; i<b; i++)
    {
        scanf("%d", &m);
        pos[m] = 2;
    }
    for(int i=0; i<c; i++)
    {
        scanf("%d", &m);
        pos[m] = 3;
    }

    hanoi(n, pos[n]);
    printf("%d\n%d\n", pos[n], ans);

    return 0;
}