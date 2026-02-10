#include <stdio.h>
#include <string.h>

#define MAX 1000001

char K[105];
int prime[MAX];

int mod(char *s, int p) {
    int r = 0;
    for(int i=0; s[i]; i++) r = (r * 10 + (s[i] - '0')) % p;
    return r;
}

int main(void) {
    int L;
    scanf("%s %d", K, &L);

    for(int i=2; i < L; i++) prime[i] = 1;

    for(int i=2; i*i<L; i++) {
        if(prime[i]) {
            for(int j=i*i; j<L; j+=i)
                prime[j] = 0;
        }
    }

    // 소수 검사
    for(int i=2; i<L; i++) {
        if(prime[i] && mod(K, i) == 0) {
            printf("BAD %d\n", i);
            return 0;
        }
    }
    printf("GOOD\n");
    return 0;
}
