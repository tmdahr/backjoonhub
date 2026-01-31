#include <stdio.h>

int to_seconds(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

int main(void) {
    for(int tc=0; tc<3; tc++) {
        int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);

        int start = to_seconds(h1, m1, s1);
        int end   = to_seconds(h2, m2, s2);

        int count = 0;
        int t = start;

        while(1) {
            int hh = t / 3600;
            int mm = (t % 3600) / 60;
            int ss = t % 60;

            int clock_num = hh * 10000 + mm * 100 + ss;
            if(clock_num % 3 == 0) count++;
            if(t == end) break;
            t++;
            if(t == 86400) t = 0;
        }
        printf("%d\n", count);
    }
    return 0;
}