#include <stdio.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    int box[1000], book[1000];

    for(int i=0; i<N; i++) scanf("%d", &box[i]);
    for(int i=0; i<M; i++) scanf("%d", &book[i]);

    int b = 0;
    for(int i=0; i<N && b<M; i++) {
        while(b<M && box[i] >= book[b]) {
            box[i] -= book[b];
            b++;
        }
    }

    int answer = 0;
    for(int i=0; i<N; i++) answer += box[i];
    printf("%d\n", answer);

    return 0;
}