#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int sequence[8];
bool used[8];

void backtrack(int depth)
{
    if(depth == m)
    {
        for(int i=0; i < m; i++) printf("%d ", sequence[i]);
        printf("\n");
        return;
    }
    
    int prev = -1;
    
    for(int i=0; i < n; i++)
    {
        if(!used[i] && arr[i] != prev)
        {
            used[i] = true;
            sequence[depth] = arr[i];
            prev = arr[i];
            backtrack(depth + 1);
            used[i] = false;
        }
    }
}

int main(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr + n);
    
    backtrack(0);
    return 0;
}