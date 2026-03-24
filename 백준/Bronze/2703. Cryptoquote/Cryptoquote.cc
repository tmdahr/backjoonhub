#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    if(scanf("%d", &T) != 1) return 0;

    getchar(); 

    while(T--) {
        char cipher[105];
        char rule[30];

        fgets(cipher, sizeof(cipher), stdin);
        cipher[strcspn(cipher, "\r\n")] = '\0';

        fgets(rule, sizeof(rule), stdin);
        rule[strcspn(rule, "\r\n")] = '\0';

        int len = strlen(cipher);
        for(int i=0; i<len; i++) {
            if(cipher[i] >= 'A' && cipher[i] <= 'Z')
                printf("%c", rule[cipher[i] - 'A']);
            else printf("%c", cipher[i]);
        }
        printf("\n");
    }

    return 0;
}