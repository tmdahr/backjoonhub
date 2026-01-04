#include <stdio.h>

int main(void) {
    int M;
    scanf("%d", &M);

    int ball = 1;

    for(int i=0; i<M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        if(ball == a) ball = b;
        else if(ball == b) ball = a;
    }

    printf("%d\n", ball);
    return 0;
}