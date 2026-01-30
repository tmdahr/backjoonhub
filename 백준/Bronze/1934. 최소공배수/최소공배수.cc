#include <stdio.h>

int gcd(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int g = gcd(a, b);
        printf("%d\n", a / g * b);
    }
    return 0;
}