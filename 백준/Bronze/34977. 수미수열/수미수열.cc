#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int L[1000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    for(int K=1; K <= N/2; K++) {
        int same = 1;

        for(int i=0; i<K; i++) {
            if(L[i] != L[N - K + i]) {
                same = 0;
                break;
            }
        }

        if(same) {
            printf("yes\n");
            return 0;
        }
    }

    printf("no\n");
    return 0;
}