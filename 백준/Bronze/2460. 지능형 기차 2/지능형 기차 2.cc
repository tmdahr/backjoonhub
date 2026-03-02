#include <stdio.h>

int main(void) {
    int out, in;
    int current = 0;
    int max = 0;

    for(int i=0; i<10; i++) {
        scanf("%d %d", &out, &in);

        current -= out;
        current += in;

        if(current > max) max = current;
    }

    printf("%d\n", max);
    return 0;
}