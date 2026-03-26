#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        int N;
        char str[81];

        scanf("%d %s", &N, str);

        int len = strlen(str);

        for(int i=0; i<len; i++)
            if(i != N - 1)
                printf("%c", str[i]);

        printf("\n");
    }

    return 0;
}