#include <stdio.h>

int main(void)
{
    int n, len;
    scanf("%d %d", &n, &len);

    for(; len<=100; len++)
    {
        int temp = n - (len * (len-1)) / 2;
        if(temp < 0) break;

        if(temp % len == 0)
        {
            int start = temp / len;
            for(int i=0; i<len; i++) printf("%d ", start + i);
            printf("\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}