#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);

    char big[600000] = "";
    char temp[10];
    char target[10];

    sprintf(target, "%d", N);

    for(int i=1; i<=N; i++) {
        sprintf(temp, "%d", i);
        strcat(big, temp);
    }

    char *pos = strstr(big, target);
    printf("%ld\n", pos - big + 1);

    return 0;
}