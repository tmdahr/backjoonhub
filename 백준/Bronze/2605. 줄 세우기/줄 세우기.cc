#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int line[101];

    for(int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);

        for(int j=i; j>i-x; j--)
            line[j] = line[j - 1];

        line[i - x] = i + 1;
    }

    for(int i=0; i<N; i++)
        printf("%d ", line[i]);

    return 0;
}