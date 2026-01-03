#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        int maxS=0, maxB=0, x;

        for(int i=0; i<N; i++) {
            scanf("%d", &x);
            if(x > maxS) maxS = x;
        }

        for(int i=0; i<M; i++) {
            scanf("%d", &x);
            if(x > maxB) maxB = x;
        }

        if(maxS >= maxB) printf("S\n");
        else printf("B\n");
    }

    return 0;
}