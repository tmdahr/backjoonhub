#include <stdio.h>
int main(void)
{
    int map[15][15]={0,};
    
    for(int i=0; i<15; i++) map[0][i]=i;
    for(int i=1; i<15; i++) for(int j=1; j<15; j++) map[i][j]=map[i-1][j]+map[i][j-1];

    int t, k, n;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        scanf("%d %d", &k, &n);
        printf("%d\n", map[k][n]);
    }

    return 0;
}