#include <stdio.h>
#include <string.h>

int main(void) {
    char plain[30005];
    char key[30005];

    if(scanf("%[^\n]%*c", plain) == 0) return 0;
    if(scanf("%[^\n]%*c", key) == 0) return 0;

    int plain_len = strlen(plain);
    int key_len = strlen(key);

    if(key_len == 0) return 0;

    for(int i=0; i < plain_len; i++) {
        if(plain[i] == ' ') printf(" ");
        else {
            int diff = plain[i] - (key[i % key_len] - 'a' + 1);
            if(diff < 'a') diff += 26;
            printf("%c", (char)diff);
        }
    }
    printf("\n");

    return 0;
}