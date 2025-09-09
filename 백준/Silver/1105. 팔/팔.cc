#include <stdio.h>
#include <string.h>

int main(void)
{
    char L[20], R[20];
    scanf("%s %s", L, R);

    if(strlen(L) != strlen(R))
    {
        printf("0\n");
        return 0;
    }

    int count = 0;
    for(int i=0; L[i]!='\0'; i++)
    {
        if(L[i] == R[i])
        {
            if(L[i] == '8') count++;
        }
        else break;
    }

    printf("%d\n", count);
    return 0;
}
