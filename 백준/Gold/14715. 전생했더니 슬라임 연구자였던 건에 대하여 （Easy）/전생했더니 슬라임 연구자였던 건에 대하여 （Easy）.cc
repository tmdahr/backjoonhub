#include <stdio.h>

int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}

int DFS(int k)
{
    int res = 2147483647;
    int split = 0;

    for(int i=2; i*i<=k; i++)
    {
        if(k%i == 0)
        {
            split = 1;
            int a = i;
            int b = k/i;
            int d1 = DFS(a);
            int d2 = DFS(b);
            res = min(res, max(d1, d2)+1);
        }
    }

    if(!split) return 0;
    return res;
}

int main(void)
{
    int k;
    scanf("%d", &k);
    printf("%d\n", DFS(k));
    return 0;
}