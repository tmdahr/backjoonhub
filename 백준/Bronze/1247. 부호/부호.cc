#include <stdio.h>

int main(void) {
    for(int t=0; t<3; t++) {
        int N;
        scanf("%d", &N);

        __int128 sum = 0;
        const __int128 LIMIT = (__int128)1 << 120;

        for(int i=0; i<N; i++) {
            long long x;
            scanf("%lld", &x);
            sum += x;

            if(sum > LIMIT) sum = LIMIT;
            if(sum < -LIMIT) sum = -LIMIT;
        }

        if(sum > 0) printf("+\n");
        else if (sum < 0) printf("-\n");
        else printf("0\n");
    }
    return 0;
}