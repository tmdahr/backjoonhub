#include <stdio.h>
#include <string.h>

int value(char *color)
{
    if(strcmp(color, "black") == 0) return 0;
    if(strcmp(color, "brown") == 0) return 1;
    if(strcmp(color, "red") == 0) return 2;
    if(strcmp(color, "orange") == 0) return 3;
    if(strcmp(color, "yellow") == 0) return 4;
    if(strcmp(color, "green") == 0) return 5;
    if(strcmp(color, "blue") == 0) return 6;
    if(strcmp(color, "violet") == 0) return 7;
    if(strcmp(color, "grey") == 0) return 8;
    else return 9;
}

int main(void)
{
    char c1[10], c2[10], c3[10];
    scanf("%s", c1);
    scanf("%s", c2);
    scanf("%s", c3);

    long long v1 = value(c1);
    long long v2 = value(c2);
    long long mul = value(c3);

    long long result = (v1 * 10 + v2);
    for(int i=0; i<mul; i++) result *= 10;

    printf("%lld\n", result);
    return 0;
}