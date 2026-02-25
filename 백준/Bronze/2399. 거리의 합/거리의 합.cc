#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if(x < y) return -1;
    if(x > y) return 1;
    return 0;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    long long *arr = (long long*)malloc(sizeof(long long)*N);
    for(int i=0; i<N; i++) scanf("%lld", &arr[i]);

    qsort(arr, N, sizeof(long long), cmp);

    long long prefix = 0;
    long long ans = 0;

    for(int i=0; i<N; i++) {
        ans += arr[i] * i - prefix;
        prefix += arr[i];
    }

    printf("%lld\n", ans * 2);

    free(arr);
    return 0;
}
