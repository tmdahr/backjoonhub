#include <stdio.h>
int main(void)
{
    int r=31, m=1234567891, len;
    char arr[51];
    long long hash = 0, R = 1;

    scanf("%d %s", &len, arr);

    for (int i = 0; i < len; i++)
    {
        hash += ((arr[i] - 'a' + 1) * R) % m;
        hash %= m;
        R *= r;
        R %= m;
    }
    printf("%lld", hash);
    return 0;
}