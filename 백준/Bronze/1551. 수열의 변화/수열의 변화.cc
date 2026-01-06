#include <stdio.h>

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[25];
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        if (i < N-1) scanf(","); // 콤마 처리
    }

    for(int step=0; step<K; step++) {
        for (int i=0; i < N-1; i++)
            arr[i] = arr[i + 1] - arr[i];
        N--;
    }

    for(int i=0; i<N; i++) {
        printf("%d", arr[i]);
        if(i < N-1) printf(",");
    }
    printf("\n");

    return 0;
}