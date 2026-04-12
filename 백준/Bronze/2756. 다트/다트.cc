#include <stdio.h>

int getScore(double x, double y) {
    double d2 = x * x + y * y;

    if(d2 <= 9) return 100;
    else if(d2 <= 36) return 80;
    else if(d2 <= 81) return 60;
    else if(d2 <= 144) return 40;
    else if(d2 <= 225) return 20;
    else return 0;
}

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        double x, y;
        int scoreA = 0, scoreB = 0;

        for(int i=0; i<3; i++) {
            scanf("%lf %lf", &x, &y);
            scoreA += getScore(x, y);
        }
        for(int i=0; i<3; i++) {
            scanf("%lf %lf", &x, &y);
            scoreB += getScore(x, y);
        }

        if(scoreA > scoreB)
            printf("SCORE: %d to %d, PLAYER 1 WINS.\n", scoreA, scoreB);
        else if(scoreA < scoreB)
            printf("SCORE: %d to %d, PLAYER 2 WINS.\n", scoreA, scoreB);
        else
            printf("SCORE: %d to %d, TIE.\n", scoreA, scoreB);
    }

    return 0;
}