#include <stdio.h>
int main(void)
{
    int map[505][505];
    int h, w, r=0;
    scanf("%d %d", &h, &w);
    for(int j=0; j<w; j++)
    {
        int b;
        scanf("%d", &b);
        for(int i=h-1; b>0; i--)
        {
            map[i][j]=1;
            b--;
        }
    }
    for(int i=0; i<h; i++)
    {
        int o=0, bw=0;
        for(int j=0; j<w; j++)
        {
            if(map[i][j]==1)
            {
                if(o==0)
                {
                    o=1;
                    bw=j;
                }
                else
                {
                    r+=j-bw-1;
                    bw=j;
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}