#include <stdio.h>

int N;
long long D[200002];

void take(int c, long long x)
{
    long long left = x, right = x;
    for(int i=0; i<N; i++)
    {
        if(left>0 && c-i>=1)
        {
            long long noise = (D[c-i]<left) ? D[c-i] : left;
            D[c-i] += noise;
            left -= noise;
        }

        if(right>0 && c+1+i<=N)
        {
            long long noise = (D[c+1+i]<right) ? D[c+1+i] : right;
            D[c+1+i] += noise;
            right -= noise;
        }

        if((left<=0 || c-i<=1) && (right<=0 || c+1+i>=N)) return;
    }
}

int main(void)
{
    int Q;
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%lld", &D[i]);
    scanf("%d", &Q);

    while(Q--)
    {
        int q, c;
        long long x;
        scanf("%d", &q);
        if(q == 1)
        {
            scanf("%d %lld", &c, &x);
            take(c, x);
        }
        else
        {
            scanf("%d", &c);
            printf("%lld\n", D[c]);
        }
    }

    return 0;
}