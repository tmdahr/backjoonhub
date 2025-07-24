#include <stdio.h>

int cnt[100005];

void solution(int num, int d)
{
    num = num < 0 ? -num : num;

    for(int i=2; i*i<=num; i++)
    {
        while(num%i == 0)
        {
            cnt[i] += d;
            num /= i;
        }
    }
    if(num > 1) cnt[num] += d;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int num;
    scanf("%d", &num);
    if(num == 0)
    {
        printf("mint chocolate\n");
        return 0;
    }
    n--;
    solution(num, 1);

    while(n--)
    {
        char cal;
        scanf(" %c %d", &cal, &num);
        if(num == 0)
        {
            printf("mint chocolate\n");
            return 0;
        }
        solution(num, cal == '*' ? 1 : -1);
    }

    for(int i=2; i<=100000; i++)
    {
        if(cnt[i] < 0)
        {
            printf("toothpaste\n");
            return 0;
        }
    }
    printf("mint chocolate\n");
    return 0;
}