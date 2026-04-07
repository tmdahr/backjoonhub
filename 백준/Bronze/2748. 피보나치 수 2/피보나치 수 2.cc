#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    long long a = 0, b = 1;

    for(int i=2; i<=n; i++) {
        long long temp = a + b;
        a = b;
        b = temp;
    }

    if (n == 0) printf("0\n");
    else printf("%lld\n", b);

    return 0;
}