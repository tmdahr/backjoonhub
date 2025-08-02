#include <stdio.h>

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    int setMin = 1000000;
    int min = 1000000;

    for(int i=0; i<M; i++)
    {
        int setPrice, price;
        scanf("%d %d", &setPrice, &price);

        if(setPrice < setMin) setMin = setPrice;
        if(price < min) min = price;
    }

    int cost1 = ((N/6)+1) * setMin;
    int cost2 = (N/6)*setMin + (N%6)*min; // 세트 + 낱개 조합
    int cost3 = N * min;

    int minCost = cost1;
    if(cost2 < minCost) minCost = cost2;
    if(cost3 < minCost) minCost = cost3;
    printf("%d\n", minCost);

    return 0;
}