#include <stdio.h>

int main(void) {
    int h1, m1, s1;
    int h2, m2, s2;

    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);

    int t1 = h1 * 3600 + m1 * 60 + s1;
    int t2 = h2 * 3600 + m2 * 60 + s2;

    int diff = t2 - t1;
    if(diff < 0) diff += 24 * 3600;

    int hh = diff / 3600;
    diff %= 3600;
    int mm = diff / 60;
    int ss = diff % 60;

    printf("%02d:%02d:%02d\n", hh, mm, ss);

    return 0;
}