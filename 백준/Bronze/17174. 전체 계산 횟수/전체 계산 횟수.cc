#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int ans = 0;

    while(n > 0) {
        ans += n;
        n /= m; 
    }

    printf("%d\n", ans);

    return 0;
}