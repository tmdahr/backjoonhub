#include <stdio.h>
#include <math.h>

int main(void) {
    int D, H, W;
    scanf("%d %d %d", &D, &H, &W);

    double scale = D / sqrt((double)H * H + (double)W * W);

    int height = (int)(H * scale);
    int width  = (int)(W * scale);

    printf("%d %d\n", height, width);
    return 0;
}