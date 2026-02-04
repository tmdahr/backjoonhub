#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int sum = 0;
    for(int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
    }

    printf("%d\n", sum - (N - 1));
    return 0;
}