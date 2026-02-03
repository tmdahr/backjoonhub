#include <stdio.h>

int main(void) {
    int M, N;
    scanf("%d %d", &M, &N);

    int sum = 0;
    int min = -1;

    for(int i=1; i*i <= N; i++) {
        int sq = i * i;
        if(sq >= M) {
            sum += sq;
            if(min == -1) min = sq;
        }
    }

    if(sum == 0) printf("-1\n");
    else printf("%d\n%d\n", sum, min);

    return 0;
}