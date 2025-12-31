#include <stdio.h>

int valid(int h, int m, int s) {
    if(h<1 || h>12) return 0;
    if(m<0 || m>59) return 0;
    if(s<0 || s>59) return 0;
    return 1;
}

int main(void) {
    int t[3];
    scanf("%d:%d:%d", &t[0], &t[1], &t[2]);

    int count = 0;
    count += valid(t[0], t[1], t[2]);
    count += valid(t[0], t[2], t[1]);
    count += valid(t[1], t[0], t[2]);
    count += valid(t[1], t[2], t[0]);
    count += valid(t[2], t[0], t[1]);
    count += valid(t[2], t[1], t[0]);

    printf("%d\n", count);
    return 0;
}