#include <stdio.h>

#define MAX_K 100
#define MAX_N 100000
typedef long long ll;

ll heap[MAX_N * MAX_K + 10];
int heap_size = 0;
ll prime[MAX_K];

void push(ll x)
{
    int i = ++heap_size;
    while(i > 1 && heap[i / 2] > x)
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

ll pop(void)
{
    ll min_val = heap[1];
    ll temp = heap[heap_size--];
    int parent = 1, child = 2;
    while(child <= heap_size)
    {
        if(child < heap_size && heap[child] > heap[child + 1]) child++;
        if(temp <= heap[child]) break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return min_val;
}

int main(void)
{
    int k, n;
    scanf("%d %d", &k, &n);

    for(int i=0; i<k; i++)
    {
        scanf("%lld", &prime[i]);
        push(prime[i]);
    }

    ll num = 0;
    for(int i=0; i<n; i++)
    {
        do num = pop();
        while (heap_size > 0 && num == heap[1]);

        for(int j=0; j<k; j++)
        {
            ll next = num * prime[j];
            push(next);
            if(num % prime[j] == 0) break;
        }
    }
    printf("%lld\n", num);
    return 0;
}