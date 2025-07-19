#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> nums, seq;

void DFS(int depth, int start)
{
    if(depth == m)
    {
        for(int num : seq) printf("%d ", num);
        printf("\n");
        return;
    }

    int prev = -1;
    for(int i=start; i < n; i++)
    {
        if(prev != nums[i])
        {
            seq.push_back(nums[i]);
            DFS(depth+1, i);
            seq.pop_back();
            prev = nums[i];
        }
    }
}

int main(void)
{
    scanf("%d %d", &n, &m);
    nums.resize(n);
    for(int i=0; i < n; i++) scanf("%d", &nums[i]);
    sort(nums.begin(), nums.end());
    DFS(0, 0);

    return 0;
}