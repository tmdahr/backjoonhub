#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    vector<int> lis;
    vector<int> index(n);
    vector<int> pos;
    vector<int> prev(n, -1);

    for(int i=0; i<n; i++)
    {
        int num = a[i];
        auto it = lower_bound(lis.begin(), lis.end(), num);
        int p = it - lis.begin();

        if(it == lis.end())
        {
            lis.push_back(num);
            pos.push_back(i);
        }
        else
        {
            *it = num;
            pos[p] = i;
        }
        index[i] = p;
        if(p > 0) prev[i] = pos[p-1];
    }
    
    printf("%d\n", lis.size());
    stack<int> result;
    int cur = pos[lis.size()-1];
    while(cur != -1)
    {
        result.push(a[cur]);
        cur = prev[cur];
    }

    while(!result.empty())
    {
        printf("%d ", result.top());
        result.pop();
    }
    printf("\n");

    return 0;
}