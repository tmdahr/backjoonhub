#include <stdio.h>
#include <string.h>
#include <math.h>

int isPrime(int n) {
    if(n == 1) return 1;
    for(int i=2; i<=sqrt(n); i++)
        if(n % i == 0) return 0;
    return 1;
}

int main(void) {
    char s[21];
    scanf("%s", s);

    int sum = 0;

    for(int i=0; s[i]; i++) {
        if('a' <= s[i] && s[i] <= 'z') sum += s[i] - 'a' + 1;
        else sum += s[i] - 'A' + 27;
    }

    if(isPrime(sum)) printf("It is a prime word.\n");
    else printf("It is not a prime word.\n");

    return 0;
}