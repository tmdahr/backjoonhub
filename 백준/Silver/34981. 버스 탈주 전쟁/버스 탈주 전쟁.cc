#include <stdio.h>

int main(void) {
    int X, Y;
    scanf("%d %d", &X, &Y);

    int now = X * 60 + Y;

    int N;
    scanf("%d", &N);

    int ans = 1e9;

    for(int i=0; i<N; i++) {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);

        int start = x * 60 + y;
        int candidate;

        if(now <= 1439) {
            if(now <= start) candidate = start;
            else {
                int diff = now - start;
                int k = (diff + d - 1) / d;
                candidate = start + k * d;
            }

            if(candidate > 1439) candidate = start + 1440;
        }
        else candidate = start + 1440;

        if(candidate < ans) ans = candidate;
    }

    int result = ans % 1440;
    int hh = result / 60;
    int mm = result % 60;

    printf("%02d:%02d\n", hh, mm);

    return 0;
}