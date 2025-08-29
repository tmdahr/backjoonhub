#include <stdio.h>
#include <math.h>

typedef long long ll;

int main(void)
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        int x1, y1, x2, y2;
        int n;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);

        int ans = 0;
        for(int i=0; i<n; i++) 
        {
            int cx, cy, r;
            scanf("%d %d %d", &cx, &cy, &r);

            int start_inside = ((x1 - cx)*(x1 - cx) + (y1 - cy)*(y1 - cy)) < r*r;
            int end_inside = ((x2 - cx)*(x2 - cx) + (y2 - cy)*(y2 - cy)) < r*r;

            if(start_inside != end_inside) ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}