#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int N, C;
    scanf("%d %d", &N, &C);

    bool fire[2000001] = {0};

    for(int i=0; i<N; i++) {
        int T;
        scanf("%d", &T);
        for(int t = T; t <= C; t += T) fire[t] = true;
    }

    int count = 0;
    for(int i=1; i<=C; i++)
        if(fire[i])
            count++;

    printf("%d\n", count);
    return 0;
}
