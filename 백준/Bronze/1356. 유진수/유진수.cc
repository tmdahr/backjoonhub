#include <stdio.h>
#include <string.h>

int main(void) {
    char N[20];
    scanf("%s", N);

    int len = strlen(N);

    for(int cut=1; cut<len; cut++) {
        int left = 1, right = 1;

        for(int i=0; i<cut; i++) left *= (N[i] - '0');

        for(int i=cut; i<len; i++) right *= (N[i] - '0');

        if(left == right) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}