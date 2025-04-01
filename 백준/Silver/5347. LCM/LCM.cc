#include <stdio.h>
 
long long gcd(long long a, long long b)
{
    long long A, B;
    if (a > b)
    {
        A = a;
        B = b;
    }
    else
    {
        A = b;
        B = a;
    }
    if (B == 0)
    {
        return A;
    }
    return gcd(B, A % B);
}
 
long long lcm(long long a, long long b)
{
    return (a * b) / gcd(a, b);
}
 
int main() {
    long long a, b;
    long long n;
    scanf("%lld", &n);
    while (n--)
    {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", lcm(a, b));
    }
    return 0;
}
