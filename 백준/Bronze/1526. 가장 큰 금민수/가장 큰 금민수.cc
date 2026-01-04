#include <stdio.h>

int isLucky(int x) {
    while(x > 0) {
        int d = x % 10;
        if(d != 4 && d != 7) return 0;
        x /= 10;
    }
    return 1;
}

int main(void) {
    int N;
    scanf("%d", &N);

    for(int i=N; i>=1; i--) {
        if(isLucky(i)) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
