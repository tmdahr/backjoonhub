#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        int C;
        scanf("%d", &C);

        int q = C / 25;
        C %= 25;

        int d = C / 10;
        C %= 10;

        int n = C / 5;
        C %= 5;

        int p = C;

        printf("%d %d %d %d\n", q, d, n, p);
    }

    return 0;
}