#include <stdio.h>
#define MOD 1000000007
typedef long long ll;

void multiply(ll a[2][2], ll b[2][2])
{
    ll temp[2][2];
    temp[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % MOD;
    temp[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % MOD;
    temp[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % MOD;
    temp[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % MOD;
    a[0][0] = temp[0][0];
    a[0][1] = temp[0][1];
    a[1][0] = temp[1][0];
    a[1][1] = temp[1][1];
}

void power(ll matrix[2][2], ll n)
{
    if (n <= 1) return;

    power(matrix, n / 2);
    multiply(matrix, matrix);

    if(n%2 == 1)
    {
        ll base[2][2] = { {1, 1}, {1, 0} };
        multiply(matrix, base);
    }
}

int main(void)
{
    ll n;
    scanf("%lld", &n);

    if(n == 0)
    {
        printf("0\n");
        return 0;
    }

    ll matrix[2][2] = { {1, 1}, {1, 0} };
    power(matrix, n - 1);
    printf("%lld\n", matrix[0][0] % MOD);
    return 0;
}