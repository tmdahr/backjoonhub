#include <stdio.h>

#define PI 3.1415927

int main(void) {
    double D, T;
    int R;
    int caseNum = 1;

    while(1) {
        scanf("%lf %d %lf", &D, &R, &T);

        if(R == 0) break;

        double distance = PI * D * R / (12 * 5280);
        double speed = distance / (T / 3600.0);

        printf("Trip #%d: %.2f %.2f\n", caseNum++, distance, speed);
    }

    return 0;
}