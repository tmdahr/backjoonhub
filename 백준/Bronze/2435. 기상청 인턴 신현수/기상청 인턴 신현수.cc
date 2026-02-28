#include <stdio.h>

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[100001];  // 문제 제한에 맞게 충분히 크게
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for(int i=0; i<K; i++) {
        sum += arr[i];
    }

    int max = sum;

    for(int i=K; i<N; i++) {
        sum = sum - arr[i-K] + arr[i];
        if(sum > max) {
            max = sum;
        }
    }

    printf("%d\n", max);
    return 0;
}