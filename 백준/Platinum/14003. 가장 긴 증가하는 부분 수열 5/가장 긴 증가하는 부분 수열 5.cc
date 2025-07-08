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
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    vector<int> lis;            // LIS의 끝 값들 (실제 수열 X)
    vector<int> index(n);       // a[i]가 LIS에서 몇 번째 위치에 들어갔는지
    vector<int> pos;            // lis[k]를 만든 a[]의 인덱스 저장
    vector<int> prev(n, -1);    // 실제 수열 복원용: 각 원소의 이전 위치

    for(int i = 0; i < n; i++)
    {
        int num = a[i];
        auto it = lower_bound(lis.begin(), lis.end(), num);
        int p = it - lis.begin();

        if (it == lis.end()) {
            lis.push_back(num);
            pos.push_back(i);
        } else {
            *it = num;
            pos[p] = i;
        }

        index[i] = p;

        // 이전 위치 저장 (p > 0이면, 이전 단계 LIS의 마지막 원소 위치 저장)
        if (p > 0)
            prev[i] = pos[p - 1];
    }

    int len = lis.size();
    printf("%d\n", len);

    // LIS 수열 역추적
    stack<int> result;
    int cur = pos[len - 1];
    while (cur != -1) {
        result.push(a[cur]);
        cur = prev[cur];
    }

    while (!result.empty()) {
        printf("%d ", result.top());
        result.pop();
    }
    printf("\n");

    return 0;
}