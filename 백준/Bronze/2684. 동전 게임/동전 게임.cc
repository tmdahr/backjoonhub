#include <stdio.h>

int main(void) {
    int P;
    scanf("%d", &P);

    while(P--) {
        char s[41];
        scanf("%s", s);

        int cnt[8] = {0};

        for(int i=0; i<38; i++) {
            int a = (s[i] == 'H') ? 1 : 0;
            int b = (s[i+1] == 'H') ? 1 : 0;
            int c = (s[i+2] == 'H') ? 1 : 0;

            int idx = a * 4 + b * 2 + c;
            cnt[idx]++;
        }

        for(int i=0; i<8; i++) {
            printf("%d", cnt[i]);
            if(i != 7) printf(" ");
        }
        printf("\n");
    }

    return 0;
}