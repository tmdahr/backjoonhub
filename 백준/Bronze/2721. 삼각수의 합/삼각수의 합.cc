#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        int n;
        scanf("%d", &n);

        int sum = 0;

        for(int k=1; k<=n; k++) {
            int t = (k+1) * (k+2) / 2;
            sum += k*t;
        }

        printf("%d\n", sum);
    }

    return 0;
}