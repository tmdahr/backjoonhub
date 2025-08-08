#include <stdio.h>

char map[10][11];
int n, m;
int max = -1;

int square(int num)
{
    if(num < 0) return 0;
    for(int i = 0; i*i <= num; i++)
    {
        if(i * i == num) return 1;
    }
    return 0;
}

int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf("%s", map[i]);

    for(int i=0; i<n; i++)
        for (int j = 0; j < m; j++)
            for (int dx = -n; dx <= n; dx++)
                for (int dy = -m; dy <= m; dy++)
                {
                    if (dx == 0 && dy == 0) continue;
                    int x = i, y = j;
                    int val = 0;

                    while(x >= 0 && x < n && y >= 0 && y < m)
                    {
                        val = val * 10 + (map[x][y] - '0');
                        if(square(val) && val > max) max = val;
                        x += dx;
                        y += dy;
                    }
                }

    printf("%d\n", max);
    return 0;
}