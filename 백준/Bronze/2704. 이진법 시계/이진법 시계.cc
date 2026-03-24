#include <stdio.h>

void toBinary(int n, char *bin) {
    for(int i=5; i>=0; i--) {
        bin[i] = (n % 2) + '0';
        n /= 2;
    }
}

int main(void) {
    int N;
    scanf("%d", &N);

    while(N--) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);

        char bh[6], bm[6], bs[6];

        toBinary(h, bh);
        toBinary(m, bm);
        toBinary(s, bs);

        for(int i=0; i<6; i++) printf("%c%c%c", bh[i], bm[i], bs[i]);

        printf(" ");

        for(int i=0; i<6; i++) printf("%c", bh[i]);
        for(int i=0; i<6; i++) printf("%c", bm[i]);
        for(int i=0; i<6; i++) printf("%c", bs[i]);

        printf("\n");
    }

    return 0;
}