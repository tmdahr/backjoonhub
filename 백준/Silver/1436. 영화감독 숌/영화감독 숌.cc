#include <stdio.h>
int main(void)
{
    int num;
    scanf("%d", &num);
    if (num == 1)
    {
        printf("666");
        return 0;
    }
    int cnt=1;
    for (int i = 667; ; i++)
    {
        int temp = i;
        int check = 0;
        while(temp)
        {
            if(temp % 1000 == 666)
            {
                check = 1;
            }
            temp /= 10;
        }
        if(check)
        {
            cnt++;
            if (cnt == num)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}