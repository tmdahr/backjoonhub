#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        long long N;
        scanf("%lld", &N);

        long long sum = 0;

        for(long long i=0; i<N; i++) {
            long long candy;
            scanf("%lld", &candy);

            sum = (sum + candy) % N;
        }

        if(sum%N == 0) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}