#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    char k[101];
    scanf("%s", k);
    
    char frac[101];
    strcpy(frac, k + 2);

    int len = strlen(frac);

    int numerator, denominator;

    if (len == 1 || frac[0] != frac[len - 1]) {
        numerator = atoi(frac);

        denominator = 1;
        for(int i=0; i<len; i++) denominator *= 10;
    }
    else {
        numerator = atoi(frac);

        denominator = 0;
        for(int i=0; i<len; i++)
            denominator = denominator * 10 + 9;
    }

    int commonDivisor = gcd(numerator, denominator);
    numerator /= commonDivisor;
    denominator /= commonDivisor;

    printf("YES\n");
    printf("%d %d\n", numerator, denominator);

    return 0;
}