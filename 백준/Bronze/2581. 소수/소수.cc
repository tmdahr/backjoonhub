#include <stdio.h>

int isPrime(int n) {
    if(n < 2) return 0;
    
    for(int i=2; i*i<=n; i++)
        if(n % i == 0) return 0;

    return 1;
}

int main(void) {
    int M, N;
    scanf("%d %d", &M, &N);

    int sum = 0;
    int min = 0;

    for(int i=M; i<=N; i++) {
        if(isPrime(i)) {
            sum += i;
            if(min == 0) min = i;
        }
    }

    if(sum == 0) printf("-1\n");
    else{
        printf("%d\n", sum);
        printf("%d\n", min);
    }

    return 0;
}