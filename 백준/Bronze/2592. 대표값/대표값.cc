#include <stdio.h>

int main(void) {
    int x;
    int sum = 0;
    int count[1001] = {0};

    for(int i=0; i<10; i++) {
        scanf("%d", &x);
        sum += x;
        count[x]++;
    }

    int max = 0;
    int mode = 0;

    for(int i=0; i<=1000; i++) {
        if(count[i] > max) {
            max = count[i];
            mode = i;
        }
    }

    printf("%d\n", sum / 10);
    printf("%d\n", mode);

    return 0;
}