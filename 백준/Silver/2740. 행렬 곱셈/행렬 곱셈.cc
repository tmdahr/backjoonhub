#include <stdio.h>
int main(void)
{
    int a[100][100], b[100][100], c[100][100]={0,};
    int n, m, k;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d", &m, &k);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<k; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int l=0; l<k; l++)
        {
            for(int j=0; j<m; j++)
            {
                c[i][l] += a[i][j]*b[j][l];
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int l=0; l<k; l++)
        {
            printf("%d ",c[i][l]);
        }
        printf("\n");
    }
    return 0;
}