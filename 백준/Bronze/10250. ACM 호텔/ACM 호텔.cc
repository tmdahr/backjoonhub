#include <stdio.h>
int main(void)
{
    int t, h, w, n;
    scanf("%d", &t);
    while(t)
    {
        scanf("%d %d %d", &h, &w, &n);
        w = n/h+1;
        if(n%h!=0) h = n%h;
        else w--;
        printf("%d%02d\n", h, w);
        t--;
    }
    
    return 0;
}