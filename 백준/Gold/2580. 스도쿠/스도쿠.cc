#include <stdio.h>
#include <stdbool.h>

typedef struct _node
{
    int h, w;
} node;

int map[10][10];
node zero[100];
int cnt=0;
bool end = false;

bool ch1(int h, int w, int num)
{
    for(int i=0; i<9; i++)
    {
        if(map[h][i]==num) return false;
    }
    return true;
}

bool ch2(int h, int w, int num)
{
    for(int i=0; i<9; i++)
    {
        if(map[i][w]==num) return false;
    }
    return true;
}

bool ch3(int h, int w, int num)
{
    int hh = h/3*3;
    int ww = w/3*3;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(map[hh+i][ww+j]==num) return false;
    return true;
}

void solution(int n)
{
    if(n==cnt)
    {
        end = true;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
                printf("%d ", map[i][j]);
            printf("\n");
        }
        return ;
    }

    int nh = zero[n].h;
    int nw = zero[n].w;
    for(int i=1; i<=9; i++)
    {
        if(ch1(nh,nw,i) && ch2(nh,nw,i) && ch3(nh,nw,i))
        {
            map[nh][nw] = i;
            solution(n+1);
            if(end) return;
            map[nh][nw] = 0;
        }
    }
}

int main(void)
{
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
        {
            scanf("%d", &map[i][j]);
            if(map[i][j]==0)
            {
                zero[cnt].h = i;
                zero[cnt].w = j;
                cnt++;
            }
        }
    solution(0);

    return 0;
}