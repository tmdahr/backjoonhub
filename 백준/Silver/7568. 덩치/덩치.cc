#include <stdio.h>

int main() {
    int N, x[50] = {0, }, y[50] = {0, }, rank;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    
    for (int i = 0; i < N; i++) {
        rank = 1;
        
        for (int j = 0; j < N; j++) {
            if (x[i] < x[j] && y[i] < y[j]) {
                rank++;
            }
        }
        
        printf("%d ", rank);
    }
    
    return 0;
}