#include <stdio.h>

int main(void) {
    int A[10], B[10];
    int scoreA = 0, scoreB = 0;
    char lastWinner = 'D';

    for(int i=0; i<10; i++) scanf("%d", &A[i]);

    for(int i=0; i<10; i++) scanf("%d", &B[i]);

    for(int i=0; i<10; i++) {
        if(A[i] > B[i]) {
            scoreA += 3;
            lastWinner = 'A';
        }
        else if(A[i] < B[i]) {
            scoreB += 3;
            lastWinner = 'B';
        }
        else {
            scoreA += 1;
            scoreB += 1;
        }
    }

    printf("%d %d\n", scoreA, scoreB);

    if(scoreA > scoreB) printf("A\n");
    else if(scoreA < scoreB) printf("B\n");
    else printf("%c\n", lastWinner);

    return 0;
}