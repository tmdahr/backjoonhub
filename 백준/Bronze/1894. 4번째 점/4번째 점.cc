#include <stdio.h>
#include <math.h>

int same(double x1, double y1, double x2, double y2) {
    return fabs(x1 - x2) < 1e-9 && fabs(y1 - y2) < 1e-9;
}

int main(void) {
    double x[4], y[4];

    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
                 &x[0], &y[0], &x[1], &y[1],
                 &x[2], &y[2], &x[3], &y[3]) == 8) {

        int p = -1, a = -1, b = -1;

        for(int i=0; i<4; i++) {
            for(int j=i+1; j<4; j++) {
                if(same(x[i], y[i], x[j], y[j])) {
                    p = i;
                    int idx = 0;
                    for(int k=0; k<4; k++) {
                        if(k != i && k != j) {
                            if(idx == 0) a = k;
                            else b = k;
                            idx++;
                        }
                    }
                }
            }
        }

        double rx = x[a] + x[b] - x[p];
        double ry = y[a] + y[b] - y[p];

        printf("%.3f %.3f\n", rx, ry);
    }
    return 0;
}