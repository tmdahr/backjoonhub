#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define MAX_SUM (MAX * (MAX+1) / 2)

long long A[MAX], B[MAX];
long long sumA[MAX_SUM], sumB[MAX_SUM];
int n, m, t;
int sizeA = 0, sizeB = 0;

int lower(long long* arr, int size, long long target)
{
    int left = 0, right = size;
    while(left < right)
    {
        int mid = (left+right) / 2;
        if(arr[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

int upper(long long* arr, int size, long long target)
{
    int left = 0, right = size;
    while(left < right)
    {
        int mid = (left+right) / 2;
        if(arr[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left;
}

int cmp(const void* a, const void* b)
{
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    return (x > y) - (x < y);
}

int main(void)
{
    scanf("%d", &t);
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lld", &A[i]);
    scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%lld", &B[i]);

    for(int i=0; i<n; i++)
    {
        long long sum = 0;
        for(int j=i; j<n; j++)
        {
            sum += A[j];
            sumA[sizeA++] = sum;
        }
    }
    for(int i=0; i<m; i++)
    {
        long long sum = 0;
        for(int j=i; j<m; j++)
        {
            sum += B[j];
            sumB[sizeB++] = sum;
        }
    }
    qsort(sumB, sizeB, sizeof(long long), cmp);

    long long ans = 0;
    for(int i=0; i<sizeA; i++)
    {
        long long target = t - sumA[i];
        ans += (upper(sumB, sizeB, target) - lower(sumB, sizeB, target));
    }

    printf("%lld\n", ans);
    return 0;
}