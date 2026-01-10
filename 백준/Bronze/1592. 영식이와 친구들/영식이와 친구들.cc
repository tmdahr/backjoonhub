#include <stdio.h>

int main(void) {
    int N, M, L;
    scanf("%d %d %d", &N, &M, &L);

    int cnt[1001] = {0};

    int cur = 1;
    cnt[cur] = 1;

    int throws = 0;

    while(cnt[cur] < M) {
        if(cnt[cur] % 2 == 1) cur = (cur - 1 + L) % N + 1;
        else cur = (cur - 1 - L + N * 1000) % N + 1;
        cnt[cur]++;
        throws++;
    }

    printf("%d\n", throws);
    return 0;
}