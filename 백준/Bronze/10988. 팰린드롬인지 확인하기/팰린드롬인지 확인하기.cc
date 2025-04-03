#include <stdio.h>
#include <string.h>
int main(void)
{
    char arr[1005];
    scanf("%s", arr);
    int l = strlen(arr);
    int o=0;
    for(int i=0; i<l; i++)
    {
        if(arr[i]!=arr[l-1-i])
        {
            o=1;
            printf("0");
            break;
        }
    }
    if(o==0) printf("1");
    return 0;
}