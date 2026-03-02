#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int maxPrize = 0;

    for(int i=0; i<N; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        int prize = 0;

        if(a == b && b == c) prize = 10000 + a * 1000;
        else if(a == b || a == c) prize = 1000 + a * 100;
        else if(b == c) prize = 1000 + b * 100;
        else {
            int max = a;
            if(b > max) max = b;
            if(c > max) max = c;
            prize = max * 100;
        }

        if(prize > maxPrize) maxPrize = prize;
    }

    printf("%d\n", maxPrize);
    return 0;
}