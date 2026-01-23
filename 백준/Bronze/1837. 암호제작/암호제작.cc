#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000000

bool isprime[MAX+1];
int plist[800000], pcnt = 0;

void sieve(int K) {
    for(int i=2; i<K; i++)
        isprime[i] = true;
    for(int i=2; i*i<K; i++)
        if(isprime[i])
            for(int j=i*i; j<K; j+=i)
                isprime[j] = false;
    for(int i=2; i<K; i++)
        if(isprime[i])
            plist[pcnt++] = i;
}

int mod(char *num, int p) {
    int r = 0;
    for(int i=0; num[i]; i++)
        r = (r*10 + (num[i]-'0')) % p;
    return r;
}

int main(void) {
    char P[105];
    int K;
    
    scanf("%s %d", P, &K);
    sieve(K);
    
    for(int i=0; i<pcnt; i++) {
        int p = plist[i];
        if(mod(P, p) == 0) {
            printf("BAD %d\n", p);
            return 0;
        }
    }
    printf("GOOD\n");
    return 0;
}