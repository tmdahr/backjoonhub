#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        int n;
        scanf("%d", &n);

        int used[10] = {0};

        while(n > 0) {
            used[n % 10] = 1;
            n /= 10;
        }

        int count = 0;
        for(int i=0; i<10; i++)
            if(used[i])
                count++;

        printf("%d\n", count);
    }

    return 0;
}