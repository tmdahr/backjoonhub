#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        long long c_iq[200005];
        long long c_sum = 0, e_sum = 0;

        for(int i=0; i<N; i++) {
            scanf("%lld", &c_iq[i]);
            c_sum += c_iq[i];
        }

        for(int i=0; i<M; i++) {
            long long temp;
            scanf("%lld", &temp);
            e_sum += temp;
        }

        int count = 0;
        for(int i=0; i<N; i++)
            if(c_iq[i] * N < c_sum && c_iq[i] * M > e_sum)
                count++;
        printf("%d\n", count);
    }
    return 0;
}