#include <stdio.h>

#define MAX 200000

int arr[MAX];
int count[10];  // 과일 번호는 1~9만 사용
int main(void)
{
    int n, left = 0, types = 0, result = 0;;
    scanf("%d", &n);
    for(int i=0; i < n; i++) scanf("%d", &arr[i]);

    for(int right=0; right < n; right++)
    {
        int fruit = arr[right];
        if(count[fruit]++ == 0) types++;

        while(types > 2)
        {
            int removed = arr[left++];
            if(--count[removed] == 0) types--;
        }
        if(result < right-left+1) result = right-left+1;
    }

    printf("%d\n", result);
    return 0;
}
