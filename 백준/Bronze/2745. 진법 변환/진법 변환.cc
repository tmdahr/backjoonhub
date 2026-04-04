#include <stdio.h>
#include <string.h>

int main(void) {
    char N[100];
    int B;
    scanf("%s %d", N, &B);

    int result = 0;

    for(int i=0; N[i]; i++) {
        int value;

        if(N[i]>='0' && N[i]<='9') value = N[i] - '0';
        else value = N[i] - 'A' + 10;

        result = result * B + value;
    }
    printf("%d\n", result);

    return 0;
}