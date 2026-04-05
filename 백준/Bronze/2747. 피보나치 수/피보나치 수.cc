#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    if(n == 0) {
        printf("0\n");
        return 0;
    }

    int a = 0, b = 1;
    for(int i=2; i<=n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }

    printf("%d\n", b);

    return 0;
}