#include <stdio.h>

int main() {
    int n, k;
    int num[1005];
    for(int i=2; i<=1000; i++) num[i]=i;
    scanf("%d %d", &n, &k);
    for(int i=2; i<=n; i++)
    {
        if(num[i]==0) continue;
        int m=0;
        while(m<=n)
        {
            m+=i;
            if(m>n) break;
            if(num[m]==0) continue;
            k--;
            if(k==0)
            {
                printf("%d", num[m]);
                break;
            }
            num[m]=0;
        }
        if(k==0) break;
    }
    return 0;
}