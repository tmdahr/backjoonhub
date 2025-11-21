#include <stdio.h>

int gcd(int a, int b) {
    while(b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main(void) {
    int a[5];
    for(int i=0; i<5; i++) scanf("%d", &a[i]);

    int ans = 1000000000;
    for(int i=0; i<5; i++) {
        for(int j=i+1; j<5; j++) {
            for(int k=j+1; k<5; k++) {
                int cur = lcm(lcm(a[i], a[j]), a[k]);
                if(cur < ans) ans = cur;
            }
        }
    }

    printf("%d", ans);
    return 0;
}
