#include <stdio.h>

char board[51][51];

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++) scanf("%s", board[i]);

    int max_size = 1;

    for(int r = 0; r < N; r++)
        for(int c = 0; c < M; c++) {
            int limit = (N - r < M - c) ? N - r : M - c;

            for(int k=1; k<limit; k++)
                if(board[r][c] == board[r][c + k] &&
                    board[r][c] == board[r + k][c] &&
                    board[r][c] == board[r + k][c + k]) {
                    int size = (k + 1) * (k + 1);
                    if(size > max_size) max_size = size;
                }
        }

    printf("%d\n", max_size);
    return 0;
}