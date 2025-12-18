#include <stdio.h>
#include <string.h>

int count_char(const char *s, char c) {
    int cnt = 0;
    for(int i=0; s[i]; i++)
        if(s[i] == c) cnt++;
    return cnt;
}

int main(void) {
    char yeondu[51];
    scanf("%s", yeondu);

    int baseL = count_char(yeondu, 'L');
    int baseO = count_char(yeondu, 'O');
    int baseV = count_char(yeondu, 'V');
    int baseE = count_char(yeondu, 'E');

    int N;
    scanf("%d", &N);

    char best[51] = "";
    int bestScore = -1;

    for(int i=0; i<N; i++) {
        char team[51];
        scanf("%s", team);

        int L = baseL + count_char(team, 'L');
        int O = baseO + count_char(team, 'O');
        int V = baseV + count_char(team, 'V');
        int E = baseE + count_char(team, 'E');

        int score = (L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E) % 100;

        if(score > bestScore || (score == bestScore && strcmp(team, best) < 0)) {
            bestScore = score;
            strcpy(best, team);
        }
    }

    printf("%s\n", best);
    return 0;
}
