#include <stdio.h>

int magic[300][300];

void odd(int n, int row, int col, int add)
{
    int i = 0, j = n/2;
    for(int num=1; num<=n*n; num++)
    {
        magic[row+i][col+j] = num+add;
        int ni = (i-1+n) % n;
        int nj = (j+1) % n;
        if(magic[row+ni][col+nj] != 0) i = (i+1) % n;
        else
        {
            i = ni;
            j = nj;
        }
    }
}

void doublyEven(int n)
{
    int num = 1;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            magic[i][j] = num++;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if((i%4 == j%4) || (i%4 + j%4 == 3))
                magic[i][j] = n*n+1 - magic[i][j];
}
void singlyEven(int n)
{
    int m = n/2;
    int x = 0;
    int y = m/2;
    
    for(int i=1; i<=m*m; i++)
    {
        magic[x][y] = i;
        if(x>=1 && !magic[x-1][(y+1)%m])
        {
            x = x-1;
            y = (y+1)%m;
        }
        else if(x<1 && !magic[m-1][(y+1)%m])
        {
            x = m-1;
            y = (y+1)%m;
        }
        else x = (x+1)%m;
    }
    
    for(int i=1; i<4; i++)
        for(int j=0; j<m; j++)
            for(int k=0; k<m; k++)
                magic[j+(i%2)*m][k+(i==1||i==2)*m] = magic[j][k] + m*m*i;
    
    for(int i=0; i<m; i++)
        for(int j=0; j<m/2; j++)
        {
            int t = magic[i][j+(i==m/2)];
            magic[i][j+(i==m/2)] = magic[i+m][j+(i==m/2)];
            magic[i+m][j+(i==m/2)] = t;
        }
    
    for(int i=0; i<m; i++)
        for(int j=n-n/4+1; j<n; j++)
        {
            int t = magic[i][j];
            magic[i][j] = magic[i+m][j];
            magic[i+m][j] = t;
        }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    if(n%2 == 1) odd(n, 0, 0, 0);
    else if(n%4 == 0) doublyEven(n);
    else singlyEven(n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) printf("%d ", magic[i][j]);
        printf("\n");
    }

    return 0;
}