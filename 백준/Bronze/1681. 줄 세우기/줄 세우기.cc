#include <stdio.h>

int hasDigit(int x, int L) {
    if(x == 0 && L == 0) return 1;
    while(x > 0) {
        if(x % 10 == L) return 1;
        x /= 10;
    }
    return 0;
}

int main(void) {
    int N, L;
    scanf("%d %d", &N, &L);

    int count = 0;
    int num = 0;

    while(count < N) {
        num++;
        if(!hasDigit(num, L)) count++;
    }

    printf("%d\n", num);
    return 0;
}
