#include <stdio.h>

int main(void) {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int prefix[105] = {0};

    for(int i=1; i<=N; i++) {
        int x;
        scanf("%d", &x);
        prefix[i] = prefix[i-1] + x;
    }

    while(Q--) {
        int t;
        scanf("%d", &t);

        for(int i=1; i<=N; i++) {
            if(t < prefix[i]) {
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}