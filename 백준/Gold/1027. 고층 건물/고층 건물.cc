#include <stdio.h>

int N;
long long h[55];
int cnt[55];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &h[i]);

    for (int i = 0; i < N; i++) {
        double max_slope = -1e18;
        for (int j = i + 1; j < N; j++) {
            double slope = (double)(h[j] - h[i]) / (j - i);
            if (slope > max_slope) {
                max_slope = slope;
                cnt[i]++;
                cnt[j]++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (cnt[i] > ans) ans = cnt[i];
    }
    printf("%d\n", ans);

    return 0;
}
