#include <stdio.h>

int main(void) {
    int A, B;
    scanf("%d %d", &A, &B);

    int idx = 0;
    int sum = 0;

    for(int num=1; idx<B; num++) {
        for(int cnt=0; cnt < num; cnt++) {
            idx++;
            if(idx >= A && idx <= B) sum += num;
            if(idx == B) break;
        }
    }

    printf("%d\n", sum);
    return 0;
}