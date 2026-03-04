#include <stdio.h>

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    int count = 0;

    for(int i=1; i<=N; i++) {
        if(N % i == 0) {
            count++;
            if(count == K) {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    printf("0\n");
    return 0;
}