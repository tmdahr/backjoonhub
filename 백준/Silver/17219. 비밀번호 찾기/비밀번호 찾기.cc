#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SITE 100000
#define MAX_LENGTH 21

typedef struct
{
    char site[MAX_LENGTH];
    char password[MAX_LENGTH];
} Entry;

int compare(const void* a, const void* b)
{
    return strcmp(((Entry*)a)->site, ((Entry*)b)->site);
}

Entry entries[MAX_SITE];

int binary_search(char* key, int n)
{
    int left = 0, right = n-1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        int cmp = strcmp(entries[mid].site, key);
        if(cmp == 0) return mid;
        if(cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(void)
{
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i=0; i < n; i++) scanf("%s %s", entries[i].site, entries[i].password);
    qsort(entries, n, sizeof(Entry), compare);

    char query[MAX_LENGTH];
    for(int i = 0; i < m; i++)
    {
        scanf("%s", query);
        int idx = binary_search(query, n);
        if(idx != -1) printf("%s\n", entries[idx].password);
    }

    return 0;
}
