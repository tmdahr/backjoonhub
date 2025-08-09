#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    char pattern[51], temp[51];
    scanf("%d", &n);
    scanf("%s", pattern);
    for(int i=1; i<n; i++)
    {
        scanf("%s", temp);
        for(int j=0; pattern[j]!='\0'; j++)
        {
            if(pattern[j] != temp[j]) pattern[j] = '?';
        }
    }

    printf("%s\n", pattern);
    return 0;
}