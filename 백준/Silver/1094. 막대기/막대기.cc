#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d", &x);
    int count = 0;
    int stick = 64;

    while(stick > 0)
    {
        if(stick <= x)
        {
            x -= stick;
            count++;
        }
        stick /= 2;
    }
    printf("%d\n", count);

    return 0;
}