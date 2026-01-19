#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    
    int a[1001];
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
        
    int d1 = a[1] - a[0];
    int d2 = a[2] - a[1];
    
    if(d1 == d2) printf("%d\n", a[N-1] + d1);
    else {
        // geometric sequence
        int r = a[1] / a[0];
        printf("%d\n", a[N-1] * r);
    }
    return 0;
}