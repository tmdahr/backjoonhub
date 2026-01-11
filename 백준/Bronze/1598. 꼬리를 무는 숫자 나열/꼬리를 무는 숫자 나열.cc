#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);

    int ar = (a-1) % 4;
    int ac = (a-1) / 4;
    int br = (b-1) % 4;
    int bc = (b-1) / 4;

    int dist = abs(ar - br) + abs(ac - bc);
    printf("%d\n", dist);

    return 0;
}