#include <stdio.h>
#include <string.h>

char code[8][7] = {
    "000000", "001111", "010011", "011100",
    "100110", "101001", "110101", "111010"
};

int main(void) {
    int N;
    scanf("%d", &N);

    char s[6001];
    scanf("%s", s);

    char result[1001];
    int idx = 0;

    for(int i=0; i<N; i++) {
        char temp[7];
        strncpy(temp, s + i * 6, 6);
        temp[6] = '\0';

        int found = 0;

        for(int j=0; j<8; j++) {
            int diff = 0;

            for(int k=0; k<6; k++)
                if(temp[k] != code[j][k])
                    diff++;

            if(diff <= 1) {
                result[idx++] = 'A' + j;
                found = 1;
                break;
            }
        }

        if(!found) {
            printf("%d\n", i+1);
            return 0;
        }
    }

    result[idx] = '\0';
    printf("%s\n", result);

    return 0;
}