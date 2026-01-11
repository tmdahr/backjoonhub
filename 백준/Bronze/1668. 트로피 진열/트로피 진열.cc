#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int h[1001];
    for(int i=0; i<N; i++) scanf("%d", &h[i]);

    int left = 0, right = 0;
    int max = 0;

    for(int i=0; i<N; i++)
        if(h[i]>max) {
            max = h[i];
            left++;
        }

    max = 0;
    for(int i=N-1; i>=0; i--)
        if(h[i] > max) {
            max = h[i];
            right++;
        }

    printf("%d\n%d\n", left, right);

    return 0;
}