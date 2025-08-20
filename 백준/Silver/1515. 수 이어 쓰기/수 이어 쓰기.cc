#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[3005];
    scanf("%s", s);

    int idx = 0;
    int len = strlen(s);
    int num = 0;

    while(idx < len)
    {
        num++;
        char buf[15];
        sprintf(buf, "%d", num);

        for(int i=0; buf[i]; i++)
        {
            if(s[idx] == buf[i])
            {
                idx++;
                if(idx == len) break;
            }
        }
    }

    printf("%d\n", num);
    return 0;
}