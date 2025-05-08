#include <stdio.h>
int main(void)
{
    int n, mi=0;
    int num[100002], max[100002];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf(" %d", &num[i]);
        if(i==0) max[i] = num[i];
        else
        {
            max[i] = max[i-1]+num[i] > num[i] ? max[i-1]+num[i] : num[i];
        }
        if(max[i] > max[mi]) mi = i;
    }
    printf("%d\n", max[mi]);

    return 0;
}