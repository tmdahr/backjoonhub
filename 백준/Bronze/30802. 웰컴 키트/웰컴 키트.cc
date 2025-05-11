#include <stdio.h>
int main(void)
{
    int n, s, m, l, xl, xxl, xxxl, t, p;
    scanf("%d", &n);
    scanf("%d %d %d %d %d %d", &s, &m, &l, &xl, &xxl, &xxxl);
    scanf("%d %d", &t, &p);
    int sum=0;
    sum+=s/t;
    if(s%t!=0) sum+=1;
    sum+=m/t;
    if(m%t!=0) sum+=1;
    sum+=l/t;
    if(l%t!=0) sum+=1;
    sum+=xl/t;
    if(xl%t!=0) sum+=1;
    sum+=xxl/t;
    if(xxl%t!=0) sum+=1;
    sum+=xxxl/t;
    if(xxxl%t!=0) sum+=1;
    printf("%d\n", sum);
    printf("%d %d", n/p, n%p);

    return 0;
}