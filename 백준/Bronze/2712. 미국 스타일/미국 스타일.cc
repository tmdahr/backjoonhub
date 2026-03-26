#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        double value;
        char unit[3];

        scanf("%lf %s", &value, unit);

        if(unit[0] == 'k') printf("%.4f lb\n", value * 2.2046);
        else if(unit[0] == 'l' && unit[1] == 'b') printf("%.4f kg\n", value * 0.4536);
        else if(unit[0] == 'l') printf("%.4f g\n", value * 0.2642);
        else if(unit[0] == 'g') printf("%.4f l\n", value * 3.7854);
    }

    return 0;
}