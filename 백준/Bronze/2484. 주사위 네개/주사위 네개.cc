#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int maxPrize = 0;

    for(int i=0; i<N; i++) {
        int count[7] = {0};
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        count[a]++;
        count[b]++;
        count[c]++;
        count[d]++;

        int prize = 0;
        int pair1 = 0, pair2 = 0;
        int maxNum = 0;

        for(int j=1; j<=6; j++) {
            if(count[j] > 0 && j > maxNum) maxNum = j;

            if(count[j] == 4) prize = 50000 + j * 5000;
            else if(count[j] == 3) prize = 10000 + j * 1000;
            else if(count[j] == 2) {
                if(pair1 == 0) pair1 = j;
                else pair2 = j;
            }
        }

        if(prize == 0) {
            if(pair1 && pair2) prize = 2000 + pair1 * 500 + pair2 * 500;
            else if(pair1) prize = 1000 + pair1 * 100;
            else prize = maxNum * 100;
        }

        if(prize > maxPrize) maxPrize = prize;
    }

    printf("%d\n", maxPrize);
    return 0;
}