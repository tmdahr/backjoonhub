#include <stdio.h>

int main(void) {
    int N, L, D;
    scanf("%d %d %d", &N, &L, &D);

    int total = N * L + (N - 1) * 5;

    for(int t=D; ; t += D) {
        if(t > total) {
            printf("%d\n", t);
            break;
        }

        int pos = t % (L + 5);

        if(pos >= L) {
            printf("%d\n", t);
            break;
        }
    }

    return 0;
}