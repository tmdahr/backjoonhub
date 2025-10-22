#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int n;
    scanf("%d", &n);
    double A[6][7];
    for(int i=0; i<n; i++) {
        for(int j=0; j<=n; j++) {
            int m;
            scanf("%d", &m);
            A[i][j] = (double)m;
        }
    }

    for(int i=0; i<n; i++) {
        if(fabs(A[i][i]) < 1e-9) {
            for(int k=i+1; k<n; k++) {
                if(fabs(A[k][i]) > 1e-9) {
                    for(int j=0; j<=n; j++) {
                        double tmp = A[i][j];
                        A[i][j] = A[k][j];
                        A[k][j] = tmp;
                    }
                    break;
                }
            }
        }
        for(int k=i+1; k<n; k++) {
            double factor = A[k][i] / A[i][i];
            for(int j=i; j<=n; j++) {
                A[k][j] -= A[i][j] * factor;
            }
        }
    }

    int num[10];
    for(int i=n-1; i>=0; i--) {
        double sum = A[i][n];
        for(int j=i+1; j<n; j++) sum -= A[i][j] * num[j];
        num[i] = (int)round(sum / A[i][i]);
    }
    for(int i=0; i<n; i++) printf("%d ", num[i]);
    printf("\n");

    return 0;
}