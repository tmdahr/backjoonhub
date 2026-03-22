#include <stdio.h>

int gcd(int a, int b) {
    while(b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        int A, B;
        scanf("%d %d", &A, &B);

        int g = gcd(A, B);
        int l = (A * B) / g;

        printf("%d %d\n", l, g);
    }

    return 0;
}