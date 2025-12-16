#include <stdio.h>
#include <string.h>

int main(void) {
    while(1) {
        char s[20];
        scanf("%s", s);

        if(strcmp(s, "0") == 0) break;

        int len = strlen(s);
        int width = 2;

        for(int i=0; i<len; i++) {
            if(s[i] == '0') width += 4;
            else if(s[i] == '1') width += 2;
            else width += 3;
        }

        width += (len - 1);
        printf("%d\n", width);
    }
    return 0;
}