#include <stdio.h>
#include <string.h>

char map[51][51];

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%s", map[i]);

    int max = 0;
    for(int i=0; i<n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            if(map[i][j] == 'Y') cnt++;
            else
            {
                for(int k=0; k<n; k++)
                {
                    if(map[i][k] == 'Y' && map[k][j] == 'Y')
                    {
                        cnt++;
                        break;
                    }
                }
            }
        }
        if(cnt > max) max = cnt;
    }

    printf("%d\n", max);
    return 0;
}