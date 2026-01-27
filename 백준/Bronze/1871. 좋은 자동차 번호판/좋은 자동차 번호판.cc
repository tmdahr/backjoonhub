#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        char s[20];
        scanf("%s", s);

        int front = 0;
        front += (s[0] - 'A') * 26 * 26;
        front += (s[1] - 'A') * 26;
        front += (s[2] - 'A');

        int back = atoi(s + 4);

        if(abs(front - back) <= 100) printf("nice\n");
        else printf("not nice\n");
    }
    return 0;
}
