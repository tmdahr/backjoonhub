#include <stdio.h>

int main(void) {
    int N, m, M, T, R;
    scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);

    if(m + T > M) {
        printf("-1\n");
        return 0;
    }

    int time = 0;
    int cur = m;
    int work = 0;

    while(work < N) {
        if(cur + T <= M) {
            cur += T;
            work++;
        }
        else {
            cur -= R;
            if (cur < m) cur = m;
        }
        time++;
    }
    printf("%d\n", time);
    return 0;
}
