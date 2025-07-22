#include <stdio.h>
int main(void)
{
    int i, j, n;
    int arr[50];
    int tmp[50] = {0, };
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        for(j=0; j<i; j++)
        {
            if(arr[j] > arr[i]) tmp[j]++;			
            else if(arr[j] <= arr[i]) tmp[i]++;
        }
    }
    for(i = 0; i<n; i++) printf("%d ", tmp[i]);
    return 0;
}