#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int score[4] = {0};   // 총점
    int three[4] = {0};   // 3점 개수
    int two[4] = {0};     // 2점 개수

    for(int i=0; i<N; i++) {
        for(int j=1; j<=3; j++) {
            int x;
            scanf("%d", &x);

            score[j] += x;
            if(x == 3) three[j]++;
            if(x == 2) two[j]++;
        }
    }

    int winner = 1;

    for(int i=2; i<=3; i++)
        if(score[i] > score[winner]) winner = i;
        else if(score[i] == score[winner]) {
            if(three[i] > three[winner]) winner = i;
            else if(three[i] == three[winner])
                if(two[i] > two[winner])
                    winner = i;
        }

    // 최종 동점 체크
    int same=0;
    for(int i=1; i<=3; i++) {
        if(i!=winner &&
            score[i] == score[winner] &&
            three[i] == three[winner] &&
            two[i] == two[winner]) {
            same = 1;
        }
    }

    if(same) printf("0 %d\n", score[winner]);
    else printf("%d %d\n", winner, score[winner]);

    return 0;
}