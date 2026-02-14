#include <stdio.h>
#include <string.h>

int main(void) {
    char s[1001];

    while(1) {
        scanf("%s", s);

        if(strcmp(s, "0") == 0) break;

        int sum = 0;

        for(int i=0; s[i]; i++) sum += s[i] - '0';

        while(sum >= 10) {
            int temp = 0;
            while(sum > 0) {
                temp += sum % 10;
                sum /= 10;
            }
            sum = temp;
        }
        printf("%d\n", sum);
    }
    return 0;
}