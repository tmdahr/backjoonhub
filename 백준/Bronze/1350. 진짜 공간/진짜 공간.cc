#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    long long size[1000];
    for(int i=0; i<N; i++) scanf("%lld", &size[i]);

    long long C;
    scanf("%lld", &C);

    long long total = 0;

    for(int i=0; i<N; i++) {
        if(size[i] == 0) continue;

        long long clusters = (size[i] + C - 1) / C;
        total += clusters * C;
    }

    printf("%lld\n", total);
    return 0;
}