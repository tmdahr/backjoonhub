#include <stdio.h>

int main(void)
{
    long long X, Y;
    scanf("%lld %lld", &X, &Y);

    int Z = (Y * 100) / X;

    if(Z >= 99)
    {
        printf("-1\n");
        return 0;
    }

    long long left = 1, right = 1000000000;
    long long answer = -1;

    while(left <= right)
    {
        long long mid = (left + right) / 2;
        long long newZ = ((Y + mid) * 100) / (X + mid);

        if(newZ > Z)
        {
            answer = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    printf("%lld\n", answer);
    return 0;
}