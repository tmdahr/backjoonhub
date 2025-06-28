#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    vector<int> sorted;

    for(int i=0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sorted.push_back(arr[i]);
    }

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    for(int i=0; i < n; i++)
    {
        int idx = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
        printf("%d ", idx);
    }

    return 0;
}