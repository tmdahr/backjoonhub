#include <stdio.h>
#include <string.h>

int main(void) {
    int p, w;
    scanf("%d %d\n", &p, &w);

    char s[1005];
    fgets(s, sizeof(s), stdin);
    int key[26] = {
        2,2,2, 3,3,3, 4,4,4, 5,5,5,
        6,6,6, 7,7,7,7, 8,8,8, 9,9,9,9
    };
    int press[26] = {
        1,2,3, 1,2,3, 1,2,3, 1,2,3,
        1,2,3, 1,2,3,4, 1,2,3, 1,2,3,4
    };

    int total = 0;
    int prev = -1;

    for(int i=0; s[i] && s[i] != '\n'; i++) {
        int curKey, cnt;

        if(s[i] == ' ') {
            curKey = 1;
            cnt = 1;
        }
        else {
            int idx = s[i] - 'A';
            curKey = key[idx];
            cnt = press[idx];
        }
        if(curKey == prev && curKey != 1) total += w;
        total += cnt * p;
        prev = curKey;
    }

    printf("%d\n", total);
    return 0;
}