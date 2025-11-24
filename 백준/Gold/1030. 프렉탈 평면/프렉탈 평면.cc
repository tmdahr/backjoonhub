#include <cstdio>

long long powN[12];

int main(void) {
    long long s, N, K, R1, R2, C1, C2;
    scanf("%lld %lld %lld %lld %lld %lld %lld", &s, &N, &K, &R1, &R2, &C1, &C2);

    powN[0] = 1;
    for(int i = 1; i <= s; i++) powN[i] = powN[i - 1] * N;

    long long mid_start = (N - K) / 2;
    long long mid_end = mid_start + K;

    for(long long r = R1; r <= R2; r++) {
        for(long long c = C1; c <= C2; c++) {

            long long rr = r, cc = c;
            int black = 0;

            for(int level = 0; level < s; level++) {
                long long block = powN[s - level - 1];

                long long br = rr / block;
                long long bc = cc / block;

                if(br >= mid_start && br < mid_end && bc >= mid_start && bc < mid_end) {
                    black = 1;
                    break;
                }
                
                rr %= block;
                cc %= block;
            }
            putchar(black ? '1' : '0');
        }
        putchar('\n');
    }
    return 0;
}