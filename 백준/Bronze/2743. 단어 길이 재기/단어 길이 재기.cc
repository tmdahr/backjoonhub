#include <stdio.h>

int main(void) {
    char str[101];
    scanf("%s", str);

    int len = 0;
    while(str[len] != '\0') len++;

    printf("%d\n", len);

    return 0;
}