#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    a = llabs(a);
    b = llabs(b);

    long long dist = a + b;

    if(dist <= c && (dist % 2) == (c % 2)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
