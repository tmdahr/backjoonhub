#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
        return (*(int*)a - *(int*)b);
}

int main() {
        int n;
        scanf("%d", &n);
        if(n == 0) {
                printf("0\n");
                return 0;
        }
        int arr[n];
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        qsort(arr, n, sizeof(int), compare);

        int idx = (int)round(n * 0.15);
        double sum = 0;
        int count = n - 2 * idx;
        for(int i = idx; i < n - idx; i++) sum += arr[i];
        printf("%d\n", (int)round(sum / count));
        return 0;
}