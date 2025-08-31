#include <stdio.h>

typedef struct
{
    int line;
    int val;
} Material;

int N;
Material material[15];

long GCD(long a, long b)
{
    while(b)
    {
        long tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

void update(int idx, int mul, int line, int propagate)
{
    int prevLine = material[idx].line;

    material[idx].val *= mul;
    material[idx].line = line;

    if(propagate && prevLine != line && prevLine != -1)
        for(int i = 0; i < N; i++)
            if(material[i].line == prevLine && i != idx) 
                update(i, mul, line, 0);
}

int main(void)
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        material[i].val = 1;
        material[i].line = -1;
    }

    for(int i=0; i<N-1; i++)
    {
        int a, b, p, q;
        scanf("%d %d %d %d", &a, &b, &p, &q);

        int g = (int)GCD(p, q);
        p /= g; q /= g;

        int aval = material[b].val * p;
        int bval = material[a].val * q;
        g = (int)GCD(aval, bval);
        aval /= g;
        bval /= g;

        update(a, aval, i, 1);
        update(b, bval, i, 1);
    }

    for(int i=0; i<N; i++) printf("%d ", material[i].val);

    return 0;
}