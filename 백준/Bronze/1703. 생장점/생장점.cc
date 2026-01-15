#include <stdio.h>

int main(void) {
    while(1) {
        int a;
        if(scanf("%d", &a) != 1) return 0;
        if(a == 0) break;
        
        long long leaves = 1;
        
        for(int i=0; i<a; i++) {
            int s, c;
            scanf("%d %d", &s, &c);
            leaves = leaves * s - c;
        }
        
        printf("%lld\n", leaves);
    }
    return 0;
}