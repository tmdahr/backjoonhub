#include <stdio.h>

#define MAX 257
int ground[502][502];

int main(void)
{
    int n,m,b;
    int min = 256, max = 0;
    scanf("%d %d %d", &n, &m, &b);

    for(int i=0; i < n; i++)
    {
        for(int j=0; j < m; j++)
        {
            scanf("%d", &ground[i][j]);
            if(ground[i][j] < min) min = ground[i][j];
            if(ground[i][j] > max) max = ground[i][j];
        }
    }

    int result_t = 2147483647;
    int result_h = 0;
    for(int h=max; h >= min; h--)
    {
        int t = 0;
        int block = b;
        for(int i=0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int diff = ground[i][j] - h;
                if(diff > 0)
                {
                    t += diff * 2;
                    block += diff;
                }
                else if(diff < 0)
                {
                    t += (-diff);
                    block -= (-diff);
                }
            }
        }

        if(block < 0) continue;
        if(t < result_t)
        {
            result_t = t;
            result_h = h;
        }
    }

    printf("%d %d\n", result_t, result_h);
    return 0;
}