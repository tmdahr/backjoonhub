#include <stdio.h>
#include <string.h>

int main(void)
{
    int N;
    char winners[100001];

    scanf("%d %s", &N, winners);
    int len = strlen(winners);
    printf("%c\n", winners[len - 1]);

    return 0;
}
