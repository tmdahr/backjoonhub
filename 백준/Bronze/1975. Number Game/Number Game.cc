#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        int N;
        scanf("%d", &N);

        int ans = 0;

        for(int b=2; b<=N; b++) {
            int temp = N;
            while(temp % b == 0) {
                ans++;
                temp /= b;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}