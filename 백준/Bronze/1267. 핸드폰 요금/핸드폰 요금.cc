#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int Y=0;
    int M=0;

    for(int i=0; i<N; i++) {
        int t;
        scanf("%d", &t);

        Y += (t / 30 + 1) * 10;
        M += (t / 60 + 1) * 15;
    }

    if(Y < M) printf("Y %d\n", Y);
    else if(M < Y) printf("M %d\n", M);
    else printf("Y M %d\n", Y);

    return 0;
}