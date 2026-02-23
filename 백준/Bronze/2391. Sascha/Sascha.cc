#include <stdio.h>
#include <string.h>

#define MAXL 130
#define MAXW 130

int diff(const char *a, const char *b) {
    int d = 0;
    for(int i=0; a[i]; i++) {
        if(a[i] != b[i]) d++;
    }
    return d;
}

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        char s[MAXL];
        int w;

        scanf("%s", s);
        scanf("%d", &w);

        char word[MAXL];
        char best[MAXL];
        int bestDist = 1000000000;

        for(int i=0; i<w; i++) {
            scanf("%s", word);

            int d = diff(s, word);

            if(d < bestDist) {
                bestDist = d;
                strcpy(best, word);
            }
        }
        printf("%s\n", best);
    }
    return 0;
}