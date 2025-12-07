#include <stdio.h>
#include <math.h>

int main(void) {
    float k;
    scanf("%f", &k);

    int p = 1;
    int q = 1;

    while(fabs((float)p / q - k) > 1e-6) {
        if((float)p / q > k) q++;
        else p++;
    }

    printf("YES\n");
    printf("%d %d\n", p, q);

    return 0;
}
