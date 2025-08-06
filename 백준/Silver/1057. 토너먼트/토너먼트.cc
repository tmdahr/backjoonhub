#include <stdio.h>

int main(void)
{
    int N, a, b;
    int round = 0;
    scanf("%d %d %d", &N, &a, &b);

    while(a != b)
    {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        round++;
    }

    printf("%d\n", round);
    return 0;
}