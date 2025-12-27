#include <stdio.h>
#include <string.h>

int main(void) {
    char bin[1000005];
    scanf("%s", bin);

    int len = strlen(bin);

    if(len == 1 && bin[0] == '0') {
        printf("0\n");
        return 0;
    }

    char result[400000];
    int idx = 0;

    for(int i=len; i>0; i-=3) {
        int value = 0;
        int power = 1;

        for(int j=i-1; j>=0 && j>=i-3; j--) {
            if(bin[j] == '1') value += power;
            power *= 2;
        }

        result[idx++] = value + '0';
    }

    for(int i=idx-1; i>=0; i--) putchar(result[i]);
    putchar('\n');

    return 0;
}
