#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int time = 0;
    int k = 1;

    while(N > 0) {
        if(N < k) k = 1;
        else {
            N -= k;
            k++;
            time++;
        }
    }

    printf("%d\n", time);
    return 0;
}
