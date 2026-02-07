#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int d = 10;
    while(n >= d) {
        n = ((n + d / 2) / d) * d;
        d *= 10;
    }
    printf("%d\n", n);

    return 0;
}
