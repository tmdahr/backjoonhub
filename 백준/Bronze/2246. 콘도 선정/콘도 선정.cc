#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int price;
    int dist;
} Condo;

int cmp(const void* a, const void* b)
{
    Condo* x = (Condo*)a;
    Condo* y = (Condo*)b;

    if(x->price == y->price) return x->dist - y->dist;
    return x->price - y->price;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    Condo arr[10001];

    for(int i=0; i<N; i++) scanf("%d %d", &arr[i].price, &arr[i].dist);

    qsort(arr, N, sizeof(Condo), cmp);

    int minD = 1e9;
    int count = 0;

    for(int i=0; i<N; i++) {
        if(arr[i].dist < minD) {
            count++;
            minD = arr[i].dist;
        }
    }

    printf("%d\n", count);
    return 0;
}