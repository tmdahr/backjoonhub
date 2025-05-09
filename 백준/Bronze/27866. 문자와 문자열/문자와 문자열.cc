#include <stdio.h>
int main(void)
{
    int i;
    char s[1005];
    scanf("%s", s);
    scanf("%d", &i);
    printf("%c\n", s[i-1]);

    return 0;
}