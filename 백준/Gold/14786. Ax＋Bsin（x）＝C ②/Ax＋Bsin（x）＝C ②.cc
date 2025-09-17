#include <stdio.h>
#include <math.h>

int main(void) {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    double left = 0.0;
    double right = (double)(C + B) / A;

    for(int i=0; i<100; i++) {
        double mid = (left + right) / 2.0;
        double f = A * mid + B * sin(mid) - C;

        if(f > 0) right = mid;
        else left = mid;
    }

    printf("%.19f\n", (left + right) / 2.0);
    return 0;
}