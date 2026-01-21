#include <stdio.h>
#include <stdbool.h>

#define MAX 1000000

bool isprime[MAX+1];
int plist[80000], pcnt = 0;

void sieve() {
    for(int i=2; i<=MAX; i++) isprime[i] = true;
    for(int i=2; i*i<=MAX; i++)
        if(isprime[i])
            for(int j=i*i; j<=MAX; j+=i)
                isprime[j] = false;
    for(int i=2; i<=MAX; i++)
        if(isprime[i])
            plist[pcnt++] = i;
}

int main(void) {
    sieve();
    
    int N;
    scanf("%d", &N);
    
    while(N--) {
        long long S;
        scanf("%lld", &S);
        
        bool ok = true;
        for(int i=0; i<pcnt; i++) {
            if(S % plist[i] == 0) {
                ok = false;
                break;
            }
        }
        
        printf(ok ? "YES\n" : "NO\n");
    }
    return 0;
}