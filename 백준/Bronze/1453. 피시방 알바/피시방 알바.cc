#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int seat[101] = {0};
    int rejected = 0;

    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);

        if(seat[x]) rejected++;
        else seat[x] = 1;
    }

    printf("%d\n", rejected);
    return 0;
}
